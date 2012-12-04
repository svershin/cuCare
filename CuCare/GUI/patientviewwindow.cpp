#include "patientviewwindow.h"
#include "ui_patientviewwindow.h"

PatientViewWindow::PatientViewWindow(AccessControl *accessControlParam,
                                     PatientData *patientDataParam, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientViewWindow),
    accessControl(accessControlParam),
    patientData(patientDataParam),
    currentPatientId(-1),
    currentConsultationId(-1),
    followupBaseStatus(0),
    newPatient(false),
    newConsultation(false),
    newFollowup(false)
{
    ui->setupUi(this);

    initializeUi();
}

PatientViewWindow::~PatientViewWindow()
{
    delete ui;
}

void PatientViewWindow::on_NewPatientPushButton_clicked()
{
    clearStatus();

    newPatient = true;
    ui->CreateConsultationPushButton->setEnabled(false);
    enablePatientEditing();
    clearPatientInfo();

    ui->PatientTreeWidget->clear(); //TODO : Makes sure this is where it should be

    //Move to Patient tab
    ui->DisplayTabsWidget->setTabEnabled(0, true);
    ui->DisplayTabsWidget->setCurrentIndex(0);
    ui->DisplayTabsWidget->setTabEnabled(1, false);
    ui->DisplayTabsWidget->setTabEnabled(2, false);
}

void PatientViewWindow::on_SelectPatientPushButton_clicked()
{
    clearStatus();

    PatientSelectDialogWindow *patientDialog = new PatientSelectDialogWindow(patientData);

    if (patientDialog->exec() == 1) {
        newPatient = false;
        currentPatientId = patientDialog->getSelectedPid();

        enablePatientEditing();
        ui->CreateConsultationPushButton->setEnabled(true);

        populatePatientTree();

        showPatientInfo();
    }

    delete patientDialog;
}

void PatientViewWindow::on_CreateConsultationPushButton_clicked()
{
    clearStatus();

    newConsultation = true;
    ui->SubmitChangesPushButton->setEnabled(true);
    ui->ResetFormsPushButton->setEnabled(true);
    clearConsultationInfo();
    ui->CreateFollowupPushButton->setEnabled(false);

    //Move to Consultation tab
    ui->DisplayTabsWidget->setTabEnabled(1, true);
    ui->DisplayTabsWidget->setCurrentIndex(1);
    ui->DisplayTabsWidget->setTabEnabled(0, false);
    ui->DisplayTabsWidget->setTabEnabled(2, false);
}

void PatientViewWindow::on_LogOutPushButton_clicked()
{
    try {
        accessControl->logOut();
        accept();
    }
    catch (char const * err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }
    catch (string err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }
}

void PatientViewWindow::on_ResetFormsPushButton_clicked()
{
    clearStatus();

    switch(ui->DisplayTabsWidget->currentIndex()) {

    case 0: //Patient Tab
        if (newPatient)
            clearPatientInfo();
        else
            showPatientInfo();
        break;

    case 1: //Consultation Tab
        if (newConsultation)
            clearConsultationInfo();
        else
            showConsultationInfo(ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt());
        break;

    case 2: //Followup Tab
        if (newFollowup)
            clearFollowupInfo();
        else
            showFollowupInfo(ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt());
        break;
    }
}

void PatientViewWindow::on_SubmitChangesPushButton_clicked()
{
    clearStatus();

    Consultation::ConsultationStatus cStatus = Consultation::CSTAT_PENDING;
    Followup::FollowupStatus fStatus = Consultation::FSTAT_PENDING;
    Date tempReceivedDate(0,0,0);
    Date tempCompletedDate(0,0,0);
    Patient tempPatient;
    Consultation tempConsultation;
    MedicalTest tempMedicalTest;
    MedicationRenewal tempMedicationRenewal;
    Referral tempReferral;
    ReturnConsultation tempreturnConsultation;
    int returnId = -1;

    ui->SubmitChangesPushButton->setEnabled(false);
    ui->ResetFormsPushButton->setEnabled(false);

    switch(ui->DisplayTabsWidget->currentIndex()) {
    case 0: //Patient Tab

        //Populate the temp object
        tempPatient.setFirstName(ui->FirstNameLineEdit->text().toStdString());
        tempPatient.setLastName(ui->LastNameLineEdit->text().toStdString());

        tempPatient.setAddress(Address(ui->CountryLineEdit->text().toStdString(), ui->CityLineEdit->text().toStdString(), ui->Address1LineEdit->text().toStdString(),
                                       ui->Address2LineEdit->text().toStdString(), ui->PostalCodeLineEdit->text().toStdString()));

        tempPatient.setContact(ContactInfo(ui->WorkPhoneLineEdit->text().toStdString(), ui->CellPhoneLineEdit->text().toStdString(),
                                           ui->EmailLineEdit->text().toStdString(), ui->WorkEmailLineEdit->text().toStdString()));

        tempPatient.setPhysicianId(ui->PatientPhysicianSelectComboBox->itemData(ui->PatientPhysicianSelectComboBox->currentIndex(), Qt::UserRole).toInt());

        tempPatient.setDateOfBirth(Date(ui->DOBDateEdit->date().day(), ui->DOBDateEdit->date().month(), ui->DOBDateEdit->date().year()));
        tempPatient.setDateAddedToSystem(Date(ui->AddedDateEdit->date().day(), ui->AddedDateEdit->date().month(), ui->AddedDateEdit->date().year()));

        tempPatient.setHealthCard(HealthCard(ui->CardNumberLineEdit->text().toStdString(), Date(ui->CardExpirationDateEdit->date().day(),
                                                                                                ui->CardExpirationDateEdit->date().month(),
                                                                                                ui->CardExpirationDateEdit->date().year())));

        tempPatient.setNotes(ui->PatientNotesTextEdit->toPlainText().toStdString());

        if (newPatient) {
            try {
                currentPatientId = patientData->createPatient(&tempPatient);
                newPatient = false;

                populatePatientTree();
                showPatientInfo();
                ui->StatusLabel->setText("New patient created.");
                ui->CreateConsultationPushButton->setEnabled(true);
            }
            catch (char const * err) {
                ui->StatusLabel->setText(QString::fromStdString(err));
            }
            catch (string err) {
                ui->StatusLabel->setText(QString::fromStdString(err));
            }
        }
        else {
            tempPatient.setId(currentPatientId);
            try {
                patientData->modifyPatient(&tempPatient);
                populatePatientTree();
                ui->StatusLabel->setText("Patient record modified successfully.");
            }
            catch (char const * err) {
                ui->StatusLabel->setText(QString::fromStdString(err));
            }
            catch (string err) {
                ui->StatusLabel->setText(QString::fromStdString(err));
            }
        }
        break;

    case 1: //Consultation Tab
        //Create the status object
        switch(ui->ConsultationStatusComboBox->currentIndex()) {
        case 0: //pending
            cStatus = Consultation::CSTAT_PENDING;
            break;
        case 1: //occured
            cStatus = Consultation::CSTAT_OCCURED;
            break;
        case 2: //completed
            cStatus = Consultation::CSTAT_COMPLETED;
            break;
        }

        //Populate the temp object
        tempConsultation.setReason(ui->ReasonTextEdit->toPlainText().toStdString());
        tempConsultation.setDiagnosis(ui->DiagnosisTextEdit->toPlainText().toStdString());
        tempConsultation.setComments(ui->ConsultationCommentsTextEdit->toPlainText().toStdString());

        tempConsultation.setCStatus(cStatus);

        tempConsultation.setDate(Date(ui->ConsultationDateTimeEdit->date().day(),
                                      ui->ConsultationDateTimeEdit->date().month(),
                                      ui->ConsultationDateTimeEdit->date().year()));
        tempConsultation.setTime(Time(ui->ConsultationDateTimeEdit->time().hour(),
                                      ui->ConsultationDateTimeEdit->time().minute()));

        tempConsultation.setPhysicianId(ui->ConsultationPhysicianSelectComboBox->itemData(ui->ConsultationPhysicianSelectComboBox->currentIndex(), Qt::UserRole).toInt());

        if (newConsultation) {
            try {
                returnId = patientData->createConsultation(&tempConsultation, currentPatientId);
                newConsultation = false;

                populatePatientTree();
                showConsultationInfo(returnId);
                ui->CreateFollowupPushButton->setEnabled(false);
                ui->StatusLabel->setText("New consultation created.");
            }
            catch (char const * err) {
                ui->StatusLabel->setText(QString::fromStdString(err));
            }
            catch (string err) {
                ui->StatusLabel->setText(QString::fromStdString(err));
            }
        }
        else {
            try {
                tempConsultation.setId(ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt());
                patientData->modifyConsultation(&tempConsultation);

                populatePatientTree();
                ui->CreateFollowupPushButton->setEnabled(false);
                ui->StatusLabel->setText("Consultation record modified successfully.");
            }
            catch (char const * err) {
                ui->StatusLabel->setText(QString::fromStdString(err));
            }
            catch (string err) {
                ui->StatusLabel->setText(QString::fromStdString(err));
            }
        }
        break;

    case 2: //Followup Tab
        //create the status object
        switch(ui->FollowupStatusComboBox->currentIndex()) {
        case 0: //pending
            fStatus = Followup::FSTAT_PENDING;
            break;
        case 1: //overdue
            fStatus = Followup::FSTAT_OVERDUE;
            break;
        case 2: //received
            fStatus = Followup::FSTAT_RECEIVED;
            break;
        case 3: //completed
            fStatus = Followup::FSTAT_COMPLETED;
            break;
        }

        if (ui->FollowupReceivedCheckBox->isChecked()) {
            tempReceivedDate.setYear(ui->ReceivedDateEdit->date().year());
            tempReceivedDate.setMonth(ui->ReceivedDateEdit->date().month());
            tempReceivedDate.setDay(ui->ReceivedDateEdit->date().day());
        }

        if (ui->FollowupCompletedCheckBox->isChecked()) {
            tempCompletedDate.setYear(ui->ReceivedDateEdit->date().year());
            tempCompletedDate.setMonth(ui->ReceivedDateEdit->date().month());
            tempCompletedDate.setDay(ui->ReceivedDateEdit->date().day());
        }

        switch(ui->FollowupTypeComboBox->currentIndex()) {
        case 0: //Medical Test

            //Populate the temp object
            tempMedicalTest.setFStatus(fStatus);
            tempMedicalTest.setDateDue(Date(ui->DueDateEdit->date().day(),
                                            ui->DueDateEdit->date().month(),
                                            ui->DueDateEdit->date().year()));
            tempMedicalTest.setDateReceived(tempReceivedDate);
            tempMedicalTest.setDateCompleted(tempCompletedDate);

            tempMedicalTest.setTestType(ui->FollowupInfoTextEdit->toPlainText().toStdString());
            tempMedicalTest.setResults(ui->FollowupInfoTextEdit2->toPlainText().toStdString());

            if (newFollowup) {
                try {
                    returnId = patientData->createFollowup(&tempMedicalTest, currentConsultationId);
                    newFollowup = false;

                    populatePatientTree();
                    showFollowupInfo(returnId);
                    ui->StatusLabel->setText("New followup created.");
                }
                catch (char const * err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }
                catch (string err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }
            }
            else {
                tempMedicalTest.setId(ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt());
                try {
                    patientData->modifyFollowup(&tempMedicalTest);
                    populatePatientTree();
                    ui->StatusLabel->setText("Followup record modified successfully.");
                }
                catch (char const * err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }
                catch (string err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }

            }
            break;

        case 1: //Medication Renewal

            //Populate the temp object
            tempMedicationRenewal.setFStatus(fStatus);
            tempMedicationRenewal.setDateDue(Date(ui->DueDateEdit->date().day(),
                                            ui->DueDateEdit->date().month(),
                                            ui->DueDateEdit->date().year()));
            tempMedicationRenewal.setDateReceived(tempReceivedDate);
            tempMedicationRenewal.setDateCompleted(tempCompletedDate);

            tempMedicationRenewal.setMedication(ui->FollowupInfoTextEdit->toPlainText().toStdString());

            if (newFollowup) {
                try {
                    returnId = patientData->createFollowup(&tempMedicationRenewal, currentConsultationId);
                    newFollowup = false;

                    populatePatientTree();
                    showFollowupInfo(returnId);
                    ui->StatusLabel->setText("New followup created.");
                }
                catch (char const * err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }
                catch (string err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }
            }
            else {
                tempMedicationRenewal.setId(ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt());
                try {
                    patientData->modifyFollowup(&tempMedicationRenewal);
                    populatePatientTree();
                    ui->StatusLabel->setText("Followup record modified successfully.");
                }
                catch (char const * err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }
                catch (string err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }

            }
            break;

        case 2: //Referral

            //Populate the temp object
            tempReferral.setFStatus(fStatus);
            tempReferral.setDateDue(Date(ui->DueDateEdit->date().day(),
                                            ui->DueDateEdit->date().month(),
                                            ui->DueDateEdit->date().year()));
            tempReferral.setDateReceived(tempReceivedDate);
            tempReferral.setDateCompleted(tempCompletedDate);

            tempReferral.setSpecialistName(ui->FollowupInfoTextEdit->toPlainText().toStdString());
            tempReferral.setResults(ui->FollowupInfoTextEdit2->toPlainText().toStdString());

            if (newFollowup) {
                try {
                    returnId = patientData->createFollowup(&tempReferral, currentConsultationId);
                    newFollowup = false;

                    populatePatientTree();
                    showFollowupInfo(returnId);
                    ui->StatusLabel->setText("New followup created.");
                }
                catch (char const * err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }
                catch (string err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }
            }
            else {
                tempReferral.setId(ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt());
                try {
                    patientData->modifyFollowup(&tempReferral);
                    populatePatientTree();
                    ui->StatusLabel->setText("Followup record modified successfully.");
                }
                catch (char const * err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }
                catch (string err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }

            }
            break;

        case 3: //Return Consultation

            //Populate the temp object
            tempreturnConsultation.setFStatus(fStatus);
            tempreturnConsultation.setDateDue(Date(ui->DueDateEdit->date().day(),
                                            ui->DueDateEdit->date().month(),
                                            ui->DueDateEdit->date().year()));
            tempreturnConsultation.setDateReceived(tempReceivedDate);
            tempreturnConsultation.setDateCompleted(tempCompletedDate);

            if (newFollowup) {
                try {
                    returnId = patientData->createFollowup(&tempreturnConsultation, currentConsultationId);
                    newFollowup = false;

                    populatePatientTree();
                    showFollowupInfo(returnId);
                    ui->StatusLabel->setText("New followup created.");
                }
                catch (char const * err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }
                catch (string err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }
            }
            else {
                tempreturnConsultation.setId(ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt());
                try {
                    patientData->modifyFollowup(&tempreturnConsultation);
                    populatePatientTree();
                    ui->StatusLabel->setText("Followup record modified successfully.");
                }
                catch (char const * err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }
                catch (string err) {
                    ui->StatusLabel->setText(QString::fromStdString(err));
                }

            }
            break;

        }

    }
}

void PatientViewWindow::on_CreateFollowupPushButton_clicked()
{
    clearStatus();

    newFollowup = true;
    ui->SubmitChangesPushButton->setEnabled(true);
    ui->ResetFormsPushButton->setEnabled(true);
    followupBaseStatus = 0;
    currentConsultationId = ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt();

    clearFollowupInfo();

    //Move to Followup tab
    ui->DisplayTabsWidget->setTabEnabled(2, true);
    ui->DisplayTabsWidget->setCurrentIndex(2);
    ui->DisplayTabsWidget->setTabEnabled(0, false);
    ui->DisplayTabsWidget->setTabEnabled(1, false);
}

void PatientViewWindow::on_FollowupTypeComboBox_currentIndexChanged(int index)
{
    clearStatus();

    switch(index) {
    case 0: //Medical Test
        ui->FollowupInfoLabel->setText("Test Type:");
        ui->FollowupInfoLabel->show();
        ui->FollowupInfoLabel2->setText("Results:");
        ui->FollowupInfoLabel2->show();
        ui->FollowupInfoTextEdit->show();
        ui->FollowupInfoTextEdit2->show();
        break;

    case 1: //Medication Renewal
        ui->FollowupInfoLabel->setText("Medication:");
        ui->FollowupInfoLabel->show();
        ui->FollowupInfoLabel2->hide();
        ui->FollowupInfoTextEdit->show();
        ui->FollowupInfoTextEdit2->hide();
        break;

    case 2: //Referral
        ui->FollowupInfoLabel->setText("Specialist Name:");
        ui->FollowupInfoLabel->show();
        ui->FollowupInfoLabel2->setText("Results:");
        ui->FollowupInfoLabel2->show();
        ui->FollowupInfoTextEdit->show();
        ui->FollowupInfoTextEdit2->show();
        break;

    case 3: //Return Consultation
        ui->FollowupInfoLabel->hide();
        ui->FollowupInfoLabel2->hide();
        ui->FollowupInfoTextEdit->hide();
        ui->FollowupInfoTextEdit2->hide();
        break;
    }
}

void PatientViewWindow::on_FollowupReceivedCheckBox_stateChanged(int arg1)
{
    clearStatus();

    if (arg1 == 0) {
        ui->ReceivedDateEdit->setEnabled(false);
    }
    else {
        ui->ReceivedDateEdit->setEnabled(true);
    }

    if (ui->FollowupCompletedCheckBox->checkState() == Qt::Checked) {
        ui->FollowupStatusComboBox->setCurrentIndex(3);
    }
    else if (ui->FollowupReceivedCheckBox->checkState() == Qt::Checked) {
        ui->FollowupStatusComboBox->setCurrentIndex(2);
    }
    else {
        ui->FollowupStatusComboBox->setCurrentIndex(followupBaseStatus);
    }
}

void PatientViewWindow::on_FollowupCompletedCheckBox_stateChanged(int arg1)
{
    clearStatus();

    if (arg1 == 0) {
        ui->CompletedDateEdit->setEnabled(false);
    }
    else {
        ui->CompletedDateEdit->setEnabled(true);
    }

    if (ui->FollowupCompletedCheckBox->checkState() == Qt::Checked) {
        ui->FollowupStatusComboBox->setCurrentIndex(3);
    }
    else if (ui->FollowupReceivedCheckBox->checkState() == Qt::Checked) {
        ui->FollowupStatusComboBox->setCurrentIndex(2);
    }
    else {
        ui->FollowupStatusComboBox->setCurrentIndex(followupBaseStatus);
    }
}

void PatientViewWindow::on_PatientTreeWidget_itemClicked(QTreeWidgetItem *item)
{
    clearStatus();

    switch(item->data(0, Qt::UserRole).toInt()) {
    case 0: //Patient has been selected
        newPatient = false;
        ui->SubmitChangesPushButton->setEnabled(true);
        ui->ResetFormsPushButton->setEnabled(true);
        showPatientInfo();
        break;
    case 1: //Consultation has been selected
        newConsultation = false;
        ui->SubmitChangesPushButton->setEnabled(true);
        ui->ResetFormsPushButton->setEnabled(true);
        showConsultationInfo(item->data(1, Qt::UserRole).toInt());
        break;
    case 2: //Followup has been selected
        newFollowup = false;
        ui->SubmitChangesPushButton->setEnabled(true);
        ui->ResetFormsPushButton->setEnabled(true);
        showFollowupInfo(item->data(1, Qt::UserRole).toInt());
        break;
    }
}

void PatientViewWindow::initializeUi()
{
    //Disable UI elements for features not required to be implemented
    ui->RunReportsPushButton->setEnabled(false);
    ui->DeletePatientPushButton->setEnabled(false);
    ui->DeleteConsultationPushButton->setEnabled(false);
    ui->DeleteFollowupPushButton->setEnabled(false);

    //Initially, only the patient tab is displayed.
    ui->DisplayTabsWidget->setCurrentIndex(0);
    ui->DisplayTabsWidget->setTabEnabled(1, false);
    ui->DisplayTabsWidget->setTabEnabled(2, false);

    //Disable consultation creation until a patient is selected
    ui->CreateConsultationPushButton->setEnabled(false);

    //Disable followup creation until a consultation is selected
    ui->CreateFollowupPushButton->setEnabled(false);

    //Followup status combo box is never user-modifiable, it just displays the current status
    ui->FollowupStatusComboBox->setEnabled(false);

    //All of the elements of the patient tab are grayed out until one is
    //selected, or until a new one is to be created
    disablePatientEditing();

    //Populate list of physicians in consultation tab
    populatePhysicianLists();
}

void PatientViewWindow::enablePatientEditing()
{
    ui->FirstNameLineEdit->setEnabled(true);
    ui->LastNameLineEdit->setEnabled(true);

    ui->WorkPhoneLineEdit->setEnabled(true);
    ui->CellPhoneLineEdit->setEnabled(true);
    ui->EmailLineEdit->setEnabled(true);
    ui->WorkEmailLineEdit->setEnabled(true);

    ui->Address1LineEdit->setEnabled(true);
    ui->Address2LineEdit->setEnabled(true);
    ui->CityLineEdit->setEnabled(true);
    ui->CountryLineEdit->setEnabled(true);
    ui->PostalCodeLineEdit->setEnabled(true);

    ui->PatientPhysicianSelectComboBox->setEnabled(true);

    ui->DOBDateEdit->setEnabled(true);
    ui->AddedDateEdit->setEnabled(true);
    ui->CardNumberLineEdit->setEnabled(true);
    ui->CardExpirationDateEdit->setEnabled(true);

    ui->PatientNotesTextEdit->setEnabled(true);

    ui->SubmitChangesPushButton->setEnabled(true);
    ui->ResetFormsPushButton->setEnabled(true);
}

void PatientViewWindow::disablePatientEditing()
{
    ui->FirstNameLineEdit->setEnabled(false);
    ui->LastNameLineEdit->setEnabled(false);

    ui->WorkPhoneLineEdit->setEnabled(false);
    ui->CellPhoneLineEdit->setEnabled(false);
    ui->EmailLineEdit->setEnabled(false);
    ui->WorkEmailLineEdit->setEnabled(false);

    ui->Address1LineEdit->setEnabled(false);
    ui->Address2LineEdit->setEnabled(false);
    ui->CityLineEdit->setEnabled(false);
    ui->CountryLineEdit->setEnabled(false);
    ui->PostalCodeLineEdit->setEnabled(false);

    ui->PatientPhysicianSelectComboBox->setEnabled(false);

    ui->DOBDateEdit->setEnabled(false);
    ui->AddedDateEdit->setEnabled(false);
    ui->CardNumberLineEdit->setEnabled(false);
    ui->CardExpirationDateEdit->setEnabled(false);

    ui->PatientNotesTextEdit->setEnabled(false);

    ui->SubmitChangesPushButton->setEnabled(false);
    ui->ResetFormsPushButton->setEnabled(false);
}

void PatientViewWindow::clearPatientInfo()
{
    ui->FirstNameLineEdit->clear();
    ui->LastNameLineEdit->clear();

    ui->WorkPhoneLineEdit->clear();
    ui->CellPhoneLineEdit->clear();
    ui->EmailLineEdit->clear();
    ui->WorkEmailLineEdit->clear();

    ui->Address1LineEdit->clear();
    ui->Address2LineEdit->clear();
    ui->CityLineEdit->clear();
    ui->CountryLineEdit->clear();
    ui->PostalCodeLineEdit->clear();

    ui->PatientPhysicianSelectComboBox->setCurrentIndex(0);

    ui->DOBDateEdit->setDate(QDate(2000,1,1));
    ui->AddedDateEdit->setDate(QDate(2000,1,1));
    ui->CardNumberLineEdit->clear();
    ui->CardExpirationDateEdit->setDate(QDate(2000,1,1));

    ui->PatientNotesTextEdit->clear();
}

void PatientViewWindow::clearConsultationInfo()
{
    AccessControl::LoginStatus tempStatus = AccessControl::AC_LOGGED_OUT;

    ui->ConsultationPhysicianSelectComboBox->setCurrentIndex(0);
    ui->ConsultationStatusComboBox->setCurrentIndex(0);

    ui->ConsultationDateTimeEdit->setDateTime(QDateTime(QDate(2000,1,1), QTime(0,0)));

    ui->ReasonTextEdit->clear();
    ui->DiagnosisTextEdit->clear();

    ui->ConsultationCommentsTextEdit->clear();

    try {
        tempStatus = accessControl->getLoginStatus();
    }
    catch (char const * err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }
    catch (string err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }

    if (tempStatus == AccessControl::AC_LOGGED_IN_AS_PHYSICIAN) { //disable editing of certain fields if not logged in as physician
        ui->DiagnosisTextEdit->setEnabled(true);
        ui->CreateFollowupPushButton->setEnabled(true);
    }
    else {
        ui->DiagnosisTextEdit->setEnabled(false);
        ui->CreateFollowupPushButton->setEnabled(false);
    }
}

void PatientViewWindow::clearFollowupInfo()
{
    AccessControl::LoginStatus tempStatus = AccessControl::AC_LOGGED_OUT;

    ui->FollowupTypeComboBox->setCurrentIndex(0);
    ui->FollowupStatusComboBox->setCurrentIndex(0);

    ui->FollowupInfoTextEdit->clear();
    ui->FollowupInfoTextEdit2->clear();

    ui->DueDateEdit->setDate(QDate(2000,1,1));
    ui->ReceivedDateEdit->setDate(QDate(2000,1,1));
    ui->CompletedDateEdit->setDate(QDate(2000,1,1));

    ui->FollowupReceivedCheckBox->setCheckState(Qt::Unchecked);
    ui->FollowupCompletedCheckBox->setCheckState(Qt::Unchecked);
    ui->ReceivedDateEdit->setEnabled(false);
    ui->CompletedDateEdit->setEnabled(false);

    //The default followup type is Medical Test, so show/rename elements accordingly
    ui->FollowupInfoLabel->setText("Test Type:");
    ui->FollowupInfoLabel->show();
    ui->FollowupInfoLabel2->setText("Results:");
    ui->FollowupInfoLabel2->show();
    ui->FollowupInfoTextEdit->show();
    ui->FollowupInfoTextEdit2->show();

    try {
        tempStatus = accessControl->getLoginStatus();
    }
    catch (char const * err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }
    catch (string err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }

    if (tempStatus == AccessControl::AC_LOGGED_IN_AS_PHYSICIAN) //disable editing of certain fields if not logged in as physician
        ui->FollowupCompletedCheckBox->setEnabled(true);
    else
        ui->FollowupCompletedCheckBox->setEnabled(false);
}

void PatientViewWindow::showPatientInfo()
{
    Patient *tempPatient = NULL;

    if (currentPatientId == -1) //no patient selected
        return;

    try {
        tempPatient = patientData->getFullPatient(currentPatientId);
    }
    catch (char const * err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }
    catch (string err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }

    clearPatientInfo();

    //Switch to patient tab and disable other tabs
    ui->DisplayTabsWidget->setTabEnabled(0, true);
    ui->DisplayTabsWidget->setCurrentIndex(0);
    ui->DisplayTabsWidget->setTabEnabled(1, false);
    ui->DisplayTabsWidget->setTabEnabled(2, false);

    //Populate fields with patient info
    ui->FirstNameLineEdit->setText(QString::fromStdString(tempPatient->getFirstName()));
    ui->LastNameLineEdit->setText(QString::fromStdString(tempPatient->getLastName()));

    ui->WorkPhoneLineEdit->setText(QString::fromStdString(tempPatient->getWorkPhone()));
    ui->CellPhoneLineEdit->setText(QString::fromStdString(tempPatient->getCellPhone()));
    ui->EmailLineEdit->setText(QString::fromStdString(tempPatient->getEmail()));
    ui->WorkEmailLineEdit->setText(QString::fromStdString(tempPatient->getWorkEmail()));

    ui->Address1LineEdit->setText(QString::fromStdString(tempPatient->getLineOne()));
    ui->Address2LineEdit->setText(QString::fromStdString(tempPatient->getLineTwo()));
    ui->CityLineEdit->setText(QString::fromStdString(tempPatient->getCity()));
    ui->CountryLineEdit->setText(QString::fromStdString(tempPatient->getCountry()));
    ui->PostalCodeLineEdit->setText(QString::fromStdString(tempPatient->getPostalCode()));

    ui->PatientPhysicianSelectComboBox->setCurrentIndex(ui->PatientPhysicianSelectComboBox->findData(tempPatient->getPhysicianId(), Qt::UserRole));

    ui->DOBDateEdit->setDate(QDate(tempPatient->getYear(),
                                       tempPatient->getMonth(),
                                       tempPatient->getDay()));
    ui->AddedDateEdit->setDate(QDate(tempPatient->getYear1(),
                                         tempPatient->getMonth1(),
                                         tempPatient->getDay1()));

    ui->CardNumberLineEdit->setText(QString::fromStdString(tempPatient->getHCNumber()));
    ui->CardExpirationDateEdit->setDate(QDate(tempPatient->getHCExpiryYear(),
                                                  tempPatient->getHCExpiryMonth(),
                                                  tempPatient->getHCExpiryDay()));

    ui->PatientNotesTextEdit->setText(QString::fromStdString(tempPatient->getNotes()));
}

void PatientViewWindow::showConsultationInfo(int cid)
{
    Consultation *tempConsult = NULL;

    try {
        tempConsult = patientData->getConsultation(cid);
    }
    catch (char const * err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }
    catch (string err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }

    clearConsultationInfo();
    ui->CreateFollowupPushButton->setEnabled(true);

    //Switch to consultation tab and disable other tabs
    ui->DisplayTabsWidget->setTabEnabled(1, true);
    ui->DisplayTabsWidget->setCurrentIndex(1);
    ui->DisplayTabsWidget->setTabEnabled(0, false);
    ui->DisplayTabsWidget->setTabEnabled(2, false);

    ui->ConsultationPhysicianSelectComboBox->setCurrentIndex(ui->ConsultationPhysicianSelectComboBox->findData(tempConsult->getPhysicianId(), Qt::UserRole));

    ui->ReasonTextEdit->setText(QString::fromStdString(tempConsult->getReason()));

    ui->DiagnosisTextEdit->setText(QString::fromStdString(tempConsult->getDiagnosis()));

    ui->ConsultationCommentsTextEdit->setText(QString::fromStdString(tempConsult->getComments()));

    ui->ConsultationDateTimeEdit->setDateTime(QDateTime(QDate(tempConsult->getYear(),
                                                              tempConsult->getMonth(),
                                                              tempConsult->getDay()),
                                                        QTime(tempConsult->getHour(),
                                                              tempConsult->getMinute())));

    Consultation::ConsultationStatus cStat = (Consultation::ConsultationStatus)tempConsult->getCStatus();
    switch(cStat) {
    case Consultation::CSTAT_PENDING:
        ui->ConsultationStatusComboBox->setCurrentIndex(ui->ConsultationStatusComboBox->findText("Pending"));
        break;
    case Consultation::CSTAT_OCCURED:
        ui->ConsultationStatusComboBox->setCurrentIndex(ui->ConsultationStatusComboBox->findText("Occured"));
        break;
    case Consultation::CSTAT_COMPLETED:
        ui->ConsultationStatusComboBox->setCurrentIndex(ui->ConsultationStatusComboBox->findText("Completed"));
        break;
    default:
        ui->StatusLabel->setText(QString::fromStdString(string("Consultation status error.")));
    }
}

void PatientViewWindow::showFollowupInfo(int fid)
{
    Followup *tempFollowup = NULL;

    try {
        tempFollowup = patientData->getFollowup(fid);
    }
    catch (char const * err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }
    catch (string err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }

    clearFollowupInfo();

    //Switch to followup tab and disable other tabs
    ui->DisplayTabsWidget->setTabEnabled(2, true);
    ui->DisplayTabsWidget->setCurrentIndex(2);
    ui->DisplayTabsWidget->setTabEnabled(0, false);
    ui->DisplayTabsWidget->setTabEnabled(1, false);

    //Hide buttons/fields for specific followup types
    ui->FollowupInfoLabel->hide();
    ui->FollowupInfoTextEdit->hide();
    ui->FollowupInfoLabel2->hide();
    ui->FollowupInfoTextEdit2->hide();

    ui->FollowupReceivedCheckBox->setCheckState(Qt::Unchecked);
    ui->FollowupCompletedCheckBox->setCheckState(Qt::Unchecked);
    ui->ReceivedDateEdit->setEnabled(false);
    ui->CompletedDateEdit->setEnabled(false);

    Followup::FollowupStatus fStat = (Followup::FollowupStatus)tempFollowup->getFStatus();
    switch(fStat) {
    case Followup::FSTAT_PENDING:
        followupBaseStatus = 0;
        ui->FollowupStatusComboBox->setCurrentIndex(0);
        break;
    case Followup::FSTAT_OVERDUE:
        followupBaseStatus = 1;
        ui->FollowupStatusComboBox->setCurrentIndex(1);
        break;
    case Followup::FSTAT_RECEIVED:
        followupBaseStatus = 0;
        ui->FollowupStatusComboBox->setCurrentIndex(2);
        break;
    case Followup::FSTAT_COMPLETED:
        followupBaseStatus = 0;
        ui->FollowupStatusComboBox->setCurrentIndex(3);
        break;
    default:
        ui->StatusLabel->setText(QString::fromStdString(string("Followup status error.")));
    }

    ui->DueDateEdit->setDate(QDate(tempFollowup->getYear(),
                                   tempFollowup->getMonth(),
                                   tempFollowup->getDay()));
    if (tempFollowup->getDateReceived().getYear() != 0) {
        ui->ReceivedDateEdit->setEnabled(true);
        ui->ReceivedDateEdit->setDate(QDate(tempFollowup->getYear1(),
                                            tempFollowup->getMonth1(),
                                            tempFollowup->getDay1()));
        ui->FollowupReceivedCheckBox->setChecked(true);
    }
    if (tempFollowup->getDateCompleted().getYear() != 0) {
        ui->CompletedDateEdit->setEnabled(true);
        ui->CompletedDateEdit->setDate(QDate(tempFollowup->getYear2(),
                                             tempFollowup->getMonth2(),
                                             tempFollowup->getDay2()));
        ui->FollowupCompletedCheckBox->setChecked(true);
    }

    switch(tempFollowup->getObjectType()) {
    case ModelObject::MEDICALTEST: //Medical Test
        ui->FollowupTypeComboBox->setCurrentIndex(0);

        ui->FollowupInfoLabel->setText("Test Type:");
        ui->FollowupInfoLabel->show();
        ui->FollowupInfoTextEdit->setText(QString::fromStdString(tempFollowup->getTestType()));
        ui->FollowupInfoTextEdit->show();

        ui->FollowupInfoLabel2->setText("Results:");
        ui->FollowupInfoLabel2->show();
        ui->FollowupInfoTextEdit2->setText(QString::fromStdString(tempFollowup->getResults()));
        ui->FollowupInfoTextEdit2->show();
        break;

    case ModelObject::MEDICATIONRENEWAL: //Medication Renewal
        ui->FollowupTypeComboBox->setCurrentIndex(1);

        ui->FollowupInfoLabel->setText("Medication:");
        ui->FollowupInfoLabel->show();
        ui->FollowupInfoTextEdit->setText(QString::fromStdString(tempFollowup->getMedication()));
        ui->FollowupInfoTextEdit->show();

        ui->FollowupInfoLabel2->hide();
        ui->FollowupInfoTextEdit2->hide();
        break;

    case ModelObject::REFERRAL: //Referral
        ui->FollowupTypeComboBox->setCurrentIndex(2);

        ui->FollowupInfoLabel->setText("Specialist Name:");
        ui->FollowupInfoLabel->show();
        ui->FollowupInfoTextEdit->setText(QString::fromStdString(tempFollowup->getSpecialistName()));
        ui->FollowupInfoTextEdit->show();

        ui->FollowupInfoLabel2->setText("Results:");
        ui->FollowupInfoLabel2->show();
        ui->FollowupInfoTextEdit2->setText(QString::fromStdString(tempFollowup->getResults()));
        ui->FollowupInfoTextEdit2->show();
        break;

    case ModelObject::RETURNCONSULTATION: //ReturnConsultation
        ui->FollowupTypeComboBox->setCurrentIndex(3);

        ui->FollowupInfoLabel->hide();
        ui->FollowupInfoTextEdit->hide();
        ui->FollowupInfoLabel2->hide();
        ui->FollowupInfoTextEdit2->hide();
        break;

    default:
        throw "Followup object type error";

    }
}

void PatientViewWindow::populatePatientTree()
{
    if (currentPatientId == -1) //no patient selected
        return;

    ui->PatientTreeWidget->clear();

    QTreeWidgetItem *pPatientWidget = new QTreeWidgetItem(ui->PatientTreeWidget);
    Patient *pTempPatient = NULL;
    QTreeWidgetItem *pTempWidget;
    QTreeWidgetItem *pTempWidget2;

    try {
        pTempPatient = patientData->getFullPatient(currentPatientId);
    }
    catch (char const * err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
        return;
    }
    catch (string err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
        return;
    }

    pPatientWidget->setText(0, QString::fromStdString(pTempPatient->getLastName() + string(", ") + pTempPatient->getFirstName()));
    pPatientWidget->setData(0, Qt::UserRole, 0); //Patient

    for (list<int>::iterator it = pTempPatient->getConsultationIds()->begin() ; it != pTempPatient->getConsultationIds()->end() ; it++) {
    //for (unsigned int i = 0 ; i < pTempPatient->getConsultationIds()->size() ; i++) {
        pTempWidget = new QTreeWidgetItem(pPatientWidget);
        try {
            pTempWidget->setText(0, QString::fromStdString(string("(C) ")
                                                           + intToString(patientData->getConsultation(*it)->getDay())
                                                           + string("/")
                                                           + intToString(patientData->getConsultation(*it)->getMonth())
                                                           + string("/")
                                                           + intToString(patientData->getConsultation(*it)->getYear())
                                                           + string(" ")
                                                           + intToString(patientData->getConsultation(*it)->getHour())
                                                           + string(":")
                                                           + intToString(patientData->getConsultation(*it)->getMinute())));
        }
        catch (char const * err) {
            ui->StatusLabel->setText(QString::fromStdString(err));
        }
        catch (string err) {
            ui->StatusLabel->setText(QString::fromStdString(err));
        }
        pTempWidget->setData(0, Qt::UserRole, 1); //Consultation
        pTempWidget->setData(1, Qt::UserRole, *it);

        for (list<int>::iterator jt = patientData->getConsultation(*it)->getFollowupIds()->begin() ; jt != patientData->getConsultation(*it)->getFollowupIds()->end() ; jt++) {
        //for (unsigned int j = 0 ; j < patientData->getConsultation(pTempPatient->getConsultationIds()->at(i))->getFollowupIds()->size() ; j++) {
            pTempWidget2 =  new QTreeWidgetItem(pTempWidget);
            try {
                pTempWidget2->setText(0, QString::fromStdString(string("(F) ")
                                                                + intToString(patientData->getFollowup(*jt)->getDay())
                                                                + string("/")
                                                                + intToString(patientData->getFollowup(*jt)->getMonth())
                                                                + string("/")
                                                                + intToString(patientData->getFollowup(*jt)->getYear())));
            }
            catch (char const * err) {
                ui->StatusLabel->setText(QString::fromStdString(err));
            }
            catch (string err) {
                ui->StatusLabel->setText(QString::fromStdString(err));
            }
            pTempWidget2->setData(0, Qt::UserRole, 2); //Followup
            pTempWidget2->setData(1, Qt::UserRole, *jt);

            pTempWidget->addChild(pTempWidget2);
        }

        pPatientWidget->addChild(pTempWidget);
    }

    ui->PatientTreeWidget->addTopLevelItem(pPatientWidget);
}

void PatientViewWindow::populatePhysicianLists()
{
    list<Physician *> pPhysicianList;

    try {
        pPhysicianList = patientData->getPhysicianList();
    }
    catch (char const * err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }
    catch (string err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }

    while(pPhysicianList.size() != 0) {
        ui->ConsultationPhysicianSelectComboBox->addItem(QString::fromStdString(pPhysicianList.front()->getLastName() + string(", ") + pPhysicianList.front()->getFirstName()), pPhysicianList.front()->getPhysicianId());
        ui->PatientPhysicianSelectComboBox->addItem(QString::fromStdString(pPhysicianList.front()->getLastName() + string(", ") + pPhysicianList.front()->getFirstName()), pPhysicianList.front()->getPhysicianId());
        pPhysicianList.pop_front();
    }
}

void PatientViewWindow::clearStatus()
{
    ui->StatusLabel->clear();
}

string PatientViewWindow::intToString(int x)
{
    stringstream tempStream;
    tempStream << x;
    return tempStream.str();
}
