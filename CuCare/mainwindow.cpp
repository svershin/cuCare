#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(MasterController *controllerParam, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    controller(controllerParam),
    pPhysicians(NULL),
    newPatient(false),
    newConsultation(false),
    newMedicalTest(false),
    newMedicationRenewal(false),
    newReferral(false),
    newReturnConsultation(false),
    currentConsultationId(-1)
{
    ui->setupUi(this);

    //Disable UI elements for features not yet implemented
    ui->LogOutPushButton->hide();
    ui->RunReportsPushButton->setEnabled(false);
    ui->CreateConsultationPushButton->setEnabled(false);
    ui->SubmitProgressBar->hide();

    //Initially, only the patient tab is displayed.
    ui->DisplayTabsWidget->setTabEnabled(1, false);
    ui->DisplayTabsWidget->setTabEnabled(2, false);

    //All of the elements of the patient tab are grayed out until one is
    //selected, or until a new one is to be created
    disablePatientEditing();

    //Populate list of physicians in consultation tab
    populatePhysicians();

    //Followup received and completed dates are not set/editable by default
    ui->ReceivedDateEdit->setEnabled(false);
    ui->CompletedDateEdit->setEnabled(false);

    ui->statusbar->showMessage("Welcome to CuCare v0.0.1");
}

MainWindow::~MainWindow()
{
    while (!pPhysicians->empty()) {
        delete pPhysicians->back();
        pPhysicians->pop_back();
    }
    if (pPhysicians != NULL)
        delete pPhysicians;
    delete ui;
}

void MainWindow::on_NewPatientPushButton_clicked()
{
    newPatient = true;
    ui->DeletePatientPushButton->setEnabled(false);
    enablePatientEditing();
}

void MainWindow::on_SelectPatientPushButton_clicked()
{
    PatientSelectDialog patientWindow(controller);

    if (patientWindow.exec() == 1) {
        enablePatientEditing();
        ui->CreateConsultationPushButton->setEnabled(true);

        //Populate patient tree view
        populatePatientTree();

        //Populate patient info tab
        showPatientInfo();
    }
}

void MainWindow::enablePatientEditing()
{
    ui->FirstNameLineEdit->setEnabled(true);
    ui->FirstNameLineEdit->clear();
    ui->LastNameLineEdit->setEnabled(true);
    ui->LastNameLineEdit->clear();


    ui->WorkPhoneLineEdit->setEnabled(true);
    ui->WorkPhoneLineEdit->clear();
    ui->CellPhoneLineEdit->setEnabled(true);
    ui->CellPhoneLineEdit->clear();
    ui->EmailLineEdit->setEnabled(true);
    ui->EmailLineEdit->clear();
    ui->WorkEmailLineEdit->setEnabled(true);
    ui->WorkEmailLineEdit->clear();

    ui->Address1LineEdit->setEnabled(true);
    ui->Address1LineEdit->clear();
    ui->Address2LineEdit->setEnabled(true);
    ui->Address2LineEdit->clear();
    ui->CityLineEdit->setEnabled(true);
    ui->CityLineEdit->clear();
    ui->CountryLineEdit->setEnabled(true);
    ui->CountryLineEdit->clear();
    ui->PostalCodeLineEdit->setEnabled(true);
    ui->PostalCodeLineEdit->clear();

    ui->DOBDateEdit->setEnabled(true);
    ui->DOBDateEdit->setDate(QDate(2000,1,1));
    ui->AddedDateEdit->setEnabled(true);
    ui->AddedDateEdit->setDate(QDate(2000,1,1));
    ui->CardNumberLineEdit->setEnabled(true);
    ui->CardNumberLineEdit->clear();
    ui->CardExpirationDateEdit->setEnabled(true);
    ui->CardExpirationDateEdit->setDate(QDate(2000,1,1));

    ui->DeletePatientPushButton->setEnabled(true);
    ui->PatientNotesTextEdit->setEnabled(true);
    ui->PatientNotesTextEdit->clear();

	ui->SubmitChangesPushButton->setEnabled(true);
    ui->ResetFormsPushButton->setEnabled(true);
}

void MainWindow::disablePatientEditing()
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

    ui->DOBDateEdit->setEnabled(false);
    ui->AddedDateEdit->setEnabled(false);
    ui->CardNumberLineEdit->setEnabled(false);
    ui->CardExpirationDateEdit->setEnabled(false);

    ui->DeletePatientPushButton->setEnabled(false);
    ui->PatientNotesTextEdit->setEnabled(false);

    ui->SubmitChangesPushButton->setEnabled(false);
    ui->ResetFormsPushButton->setEnabled(false);
}

void MainWindow::showPatientInfo()
{
    //Switch to patient tab and disable other tabs
    ui->DisplayTabsWidget->setTabEnabled(0, true);
    ui->DisplayTabsWidget->setCurrentIndex(0);
    ui->DisplayTabsWidget->setTabEnabled(1, false);
    ui->DisplayTabsWidget->setTabEnabled(2, false);

    ui->DeletePatientPushButton->setEnabled(true);

    //Populate fields with patient info
    ui->FirstNameLineEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getFirstName()));
    ui->LastNameLineEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getLastName()));

    ui->WorkPhoneLineEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getContact().getWorkPhone()));
    ui->CellPhoneLineEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getContact().getCellPhone()));
    ui->EmailLineEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getContact().getEmail()));
    ui->WorkEmailLineEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getContact().getWorkEmail()));

    ui->Address1LineEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getAddress().getLineOne()));
    ui->Address2LineEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getAddress().getLineTwo()));
    ui->CityLineEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getAddress().getCity()));
    ui->CountryLineEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getAddress().getCountry()));
    ui->PostalCodeLineEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getAddress().getPostalCode()));

    ui->DOBDateEdit->setDate(QDate(controller->getCurrentPatient()->getDateOfBirth().getYear(),
                                       controller->getCurrentPatient()->getDateOfBirth().getMonth(),
                                       controller->getCurrentPatient()->getDateOfBirth().getDay()));
    ui->AddedDateEdit->setDate(QDate(controller->getCurrentPatient()->getDateAddedToSystem().getYear(),
                                         controller->getCurrentPatient()->getDateAddedToSystem().getMonth(),
                                         controller->getCurrentPatient()->getDateAddedToSystem().getDay()));

    ui->CardNumberLineEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getHealthCard().getNumber()));
    ui->CardExpirationDateEdit->setDate(QDate(controller->getCurrentPatient()->getHealthCard().getExpiry().getYear(),
                                                  controller->getCurrentPatient()->getHealthCard().getExpiry().getMonth(),
                                                  controller->getCurrentPatient()->getHealthCard().getExpiry().getDay()));

    ui->PatientNotesTextEdit->setText(QString::fromStdString(controller->getCurrentPatient()->getNotes()));
}

void MainWindow::showConsultationInfo(int cid)
{

    Consultation *pConsultation = NULL;

    for (unsigned int i = 0 ; i < controller->getCurrentPatient()->getConsultations()->size() ; i++) {
        if (controller->getCurrentPatient()->getConsultations()->at(i)->getConsultID() == cid) {
            pConsultation = controller->getCurrentPatient()->getConsultations()->at(i);
            break;
        }
    }

    if (pConsultation == NULL)
        return;

    //Switch to consultation tab and disable other tabs
    ui->DisplayTabsWidget->setTabEnabled(1, true);
    ui->DisplayTabsWidget->setCurrentIndex(1);
    ui->DisplayTabsWidget->setTabEnabled(0, false);
    ui->DisplayTabsWidget->setTabEnabled(2, false);

    ui->DeleteConsultationPushButton->setEnabled(true);

    //select the proper physician
    ui->PhysicianSelectComboBox->setCurrentIndex(ui->PhysicianSelectComboBox->findData(pConsultation->getConsultingPhys()->getId(), Qt::UserRole));

    ui->ReasonTextEdit->setText(QString::fromStdString(pConsultation->getReason()));

    ui->DiagnosisTextEdit->setText(QString::fromStdString(pConsultation->getDiagnosis()));

    ui->ConsultationCommentsTextEdit->setText(QString::fromStdString(pConsultation->getComments()));

    ui->ConsultationDateTimeEdit->setDateTime(QDateTime(QDate(pConsultation->getDate().getYear(),
                                                              pConsultation->getDate().getMonth(),
                                                              pConsultation->getDate().getDay()),
                                                        QTime(pConsultation->getTime().getHour(),
                                                              pConsultation->getTime().getMinute())));

    Consultation::ConsultationStatus cStat = pConsultation->getStatus();
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
    case Consultation::CSTAT_ERROR:
        //handle error case here
        ui->ConsultationStatusComboBox->setCurrentIndex(ui->ConsultationStatusComboBox->findText("Pending"));
        break;
    }

    if (controller->loginStatus() == MasterController::AC_LOGGED_IN_AS_PHYSICIAN) { //disable editing of certain fields if not logged in as physician
        ui->ReasonTextEdit->setEnabled(true);
        ui->ReasonTextEdit->setEnabled(true);
        ui->CreateFollowupPushButton->setEnabled(true);
    }
    else {
        ui->ReasonTextEdit->setEnabled(false);
        ui->ReasonTextEdit->setEnabled(false);
        ui->CreateFollowupPushButton->setEnabled(false);
    }

    if (pConsultation != NULL)
        delete pConsultation;
}

void MainWindow::showFollowup(int fid, int cid)
{
    for (unsigned int i = 0 ; i < controller->getCurrentPatient()->getConsultations()->size() ; i++) {
        if (controller->getCurrentPatient()->getConsultations()->at(i)->getConsultID() == cid) {
            for (unsigned int j = 0 ; j < controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->size() ; j++) {
                if (controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j)->getId() == fid) {

                    ui->DeleteFollowupPushButton->setEnabled(true);

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

                    if (controller->loginStatus() == MasterController::AC_LOGGED_IN_AS_PHYSICIAN) //disable editing of certain fields if not logged in as physician
                        ui->FollowupCompletedCheckBox->setEnabled(true);
                    else
                        ui->FollowupCompletedCheckBox->setEnabled(false);

                    switch(controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j)->getType()) {
                    case 1: //Medical Test
                        showMedicalTest((MedicalTest*)controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j));
                        break;
                    case 2: //Medication Renewal
                        showMedicationRenewal((MedicationRenewal*)controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j));
                        break;
                    case 3: //Referral
                        showReferral((Referral*)controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j));
                        break;
                    case 4: //ReturnConsultation
                        showReturnConsultation((ReturnConsultation*)controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j));
                        break;
                    }
                    break;
                }
            }
            break;
        }
    }


}

void MainWindow::showMedicalTest(MedicalTest *pMedicalTest)
{
    Followup::FollowupStatus fStat = pMedicalTest->getStatus();
    switch(fStat) {
    case Followup::FSTAT_PENDING:
        ui->FollowupStatusComboBox->setCurrentIndex(0);
        break;
    case Followup::FSTAT_OVERDUE:
        ui->FollowupStatusComboBox->setCurrentIndex(1);
        break;
    case Followup::FSTAT_RECEIVED:
        ui->FollowupStatusComboBox->setCurrentIndex(2);
        break;
    case Followup::FSTAT_COMPLETED:
        ui->FollowupStatusComboBox->setCurrentIndex(3);
        break;
    case Followup::FSTAT_ERROR:
        //handle error case here
        ui->FollowupStatusComboBox->setCurrentIndex(0);
        break;
    }

    ui->DueDateEdit->setDate(QDate(pMedicalTest->getDateDue().getYear(),
                                   pMedicalTest->getDateDue().getMonth(),
                                   pMedicalTest->getDateDue().getDay()));
    if (pMedicalTest->getDateReceived().getYear() != 0) {
        ui->ReceivedDateEdit->setEnabled(true);
        ui->ReceivedDateEdit->setDate(QDate(pMedicalTest->getDateReceived().getYear(),
                                            pMedicalTest->getDateReceived().getMonth(),
                                            pMedicalTest->getDateReceived().getDay()));
        ui->FollowupReceivedCheckBox->setChecked(true);
    }
    if (pMedicalTest->getDateCompleted().getYear() != 0) {
        ui->CompletedDateEdit->setEnabled(true);
        ui->CompletedDateEdit->setDate(QDate(pMedicalTest->getDateCompleted().getYear(),
                                             pMedicalTest->getDateCompleted().getMonth(),
                                             pMedicalTest->getDateCompleted().getDay()));
        ui->FollowupCompletedCheckBox->setChecked(true);
    }


    ui->FollowupInfoLabel->setText("Test Type:");
    ui->FollowupInfoLabel->show();
    ui->FollowupInfoTextEdit->setText(QString::fromStdString(pMedicalTest->getTestType()));
    ui->FollowupInfoTextEdit->show();

    ui->FollowupInfoLabel2->setText("Results:");
    ui->FollowupInfoLabel2->show();
    ui->FollowupInfoTextEdit2->setText(QString::fromStdString(pMedicalTest->getResults()));
    ui->FollowupInfoTextEdit2->show();
}

void MainWindow::showMedicationRenewal(MedicationRenewal *pMedicationRenewal)
{
    Followup::FollowupStatus fStat = pMedicationRenewal->getStatus();
    switch(fStat) {
    case Followup::FSTAT_PENDING:
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Pending"));
        break;
    case Followup::FSTAT_OVERDUE:
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Overdue"));
        break;
    case Followup::FSTAT_RECEIVED:
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Received"));
        break;
    case Followup::FSTAT_COMPLETED:
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Completed"));
        break;
    case Followup::FSTAT_ERROR:
        //handle error case here
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Pending"));
        break;
    }

    ui->DueDateEdit->setDate(QDate(pMedicationRenewal->getDateDue().getYear(),
                                   pMedicationRenewal->getDateDue().getMonth(),
                                   pMedicationRenewal->getDateDue().getDay()));
    if (pMedicationRenewal->getDateReceived().getYear() != 0) {
        ui->ReceivedDateEdit->setEnabled(true);
        ui->ReceivedDateEdit->setDate(QDate(pMedicationRenewal->getDateReceived().getYear(),
                                            pMedicationRenewal->getDateReceived().getMonth(),
                                            pMedicationRenewal->getDateReceived().getDay()));
        ui->FollowupReceivedCheckBox->setChecked(true);
    }
    if (pMedicationRenewal->getDateCompleted().getYear() != 0) {
        ui->CompletedDateEdit->setEnabled(true);
        ui->CompletedDateEdit->setDate(QDate(pMedicationRenewal->getDateCompleted().getYear(),
                                             pMedicationRenewal->getDateCompleted().getMonth(),
                                             pMedicationRenewal->getDateCompleted().getDay()));
        ui->FollowupCompletedCheckBox->setChecked(true);
    }

    ui->FollowupInfoLabel->setText("Medication:");
    ui->FollowupInfoLabel->show();
    ui->FollowupInfoTextEdit->setText(QString::fromStdString(pMedicationRenewal->getMedication()));
    ui->FollowupInfoTextEdit->show();
}

void MainWindow::showReferral(Referral *pReferral)
{
    Followup::FollowupStatus fStat = pReferral->getStatus();
    switch(fStat) {
    case Followup::FSTAT_PENDING:
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Pending"));
        break;
    case Followup::FSTAT_OVERDUE:
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Overdue"));
        break;
    case Followup::FSTAT_RECEIVED:
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Received"));
        break;
    case Followup::FSTAT_COMPLETED:
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Completed"));
        break;
    case Followup::FSTAT_ERROR:
        //handle error case here
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Pending"));
        break;
    }

    ui->DueDateEdit->setDate(QDate(pReferral->getDateDue().getYear(),
                                   pReferral->getDateDue().getMonth(),
                                   pReferral->getDateDue().getDay()));
    if (pReferral->getDateReceived().getYear() != 0) {
        ui->ReceivedDateEdit->setEnabled(true);
        ui->ReceivedDateEdit->setDate(QDate(pReferral->getDateReceived().getYear(),
                                            pReferral->getDateReceived().getMonth(),
                                            pReferral->getDateReceived().getDay()));
        ui->FollowupReceivedCheckBox->setChecked(true);
    }
    if (pReferral->getDateCompleted().getYear() != 0) {
        ui->CompletedDateEdit->setEnabled(true);
        ui->CompletedDateEdit->setDate(QDate(pReferral->getDateCompleted().getYear(),
                                             pReferral->getDateCompleted().getMonth(),
                                             pReferral->getDateCompleted().getDay()));
        ui->FollowupCompletedCheckBox->setChecked(true);
    }

    ui->FollowupInfoLabel->setText("Specialist Name:");
    ui->FollowupInfoLabel->show();
    ui->FollowupInfoTextEdit->setText(QString::fromStdString(pReferral->getSpecialistName()));
    ui->FollowupInfoTextEdit->show();

    ui->FollowupInfoLabel2->setText("Results:");
    ui->FollowupInfoLabel2->show();
    ui->FollowupInfoTextEdit2->setText(QString::fromStdString(pReferral->getResults()));
    ui->FollowupInfoTextEdit2->show();
}

void MainWindow::showReturnConsultation(ReturnConsultation *pReturnConsultation)
{
    Followup::FollowupStatus fStat = pReturnConsultation->getStatus();
    switch(fStat) {
    case Followup::FSTAT_PENDING:
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Pending"));
        break;
    case Followup::FSTAT_OVERDUE:
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Overdue"));
        break;
    case Followup::FSTAT_RECEIVED:
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Received"));
        break;
    case Followup::FSTAT_COMPLETED:
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Completed"));
        break;
    case Followup::FSTAT_ERROR:
        //handle error case here
        ui->FollowupStatusComboBox->setCurrentIndex(ui->FollowupStatusComboBox->findText("Pending"));
        break;
    }

    ui->DueDateEdit->setDate(QDate(pReturnConsultation->getDateDue().getYear(),
                                   pReturnConsultation->getDateDue().getMonth(),
                                   pReturnConsultation->getDateDue().getDay()));
    if (pReturnConsultation->getDateReceived().getYear() != 0) {
        ui->ReceivedDateEdit->setEnabled(true);
        ui->ReceivedDateEdit->setDate(QDate(pReturnConsultation->getDateReceived().getYear(),
                                            pReturnConsultation->getDateReceived().getMonth(),
                                            pReturnConsultation->getDateReceived().getDay()));
        ui->FollowupReceivedCheckBox->setChecked(true);
    }
    if (pReturnConsultation->getDateCompleted().getYear() != 0) {
        ui->CompletedDateEdit->setEnabled(true);
        ui->CompletedDateEdit->setDate(QDate(pReturnConsultation->getDateCompleted().getYear(),
                                             pReturnConsultation->getDateCompleted().getMonth(),
                                             pReturnConsultation->getDateCompleted().getDay()));
        ui->FollowupCompletedCheckBox->setChecked(true);
    }
}

void MainWindow::clearConsultationTab()
{
    ui->ReasonTextEdit->clear();
    ui->DiagnosisTextEdit->clear();
    ui->ConsultationCommentsTextEdit->clear();
    ui->PhysicianSelectComboBox->setCurrentIndex(0);
    ui->ConsultationStatusComboBox->setCurrentIndex(0);
    ui->ConsultationDateTimeEdit->setDateTime(QDateTime(QDate(2000,1,1), QTime(0,0)));
}

void MainWindow::clearFollowupTab()
{
    ui->FollowupInfoTextEdit->clear();
    ui->FollowupInfoTextEdit2->clear();
    ui->FollowupStatusComboBox->setCurrentIndex(0);
    ui->DueDateEdit->setDate(QDate(2000,1,1));
    ui->ReceivedDateEdit->setDate(QDate(2000,1,1));
    ui->CompletedDateEdit->setDate(QDate(2000,1,1));
    ui->FollowupReceivedCheckBox->setCheckState(Qt::Unchecked);
    ui->FollowupCompletedCheckBox->setCheckState(Qt::Unchecked);
    ui->ReceivedDateEdit->setEnabled(false);
    ui->CompletedDateEdit->setEnabled(false);
}

void MainWindow::populatePhysicians()
{
    string *pErrorString = NULL;
    pPhysicians = NULL;
    if (controller->getPhysicianList(pPhysicians, pErrorString) && pPhysicians != NULL) {
        for (unsigned int i = 0 ; i < pPhysicians->size() ; i++) {
            ui->PhysicianSelectComboBox->addItem(QString::fromStdString(pPhysicians->at(i)->getLastName() + string(", ") + pPhysicians->at(i)->getFirstName()), pPhysicians->at(i)->getId());
        }
    }
    else
        ui->statusbar->showMessage(QString::fromStdString(*pErrorString));

    if (pErrorString != NULL)
        delete pErrorString;
}

void MainWindow::populatePatientTree()
{
    ui->PatientTreeWidget->clear();

    QTreeWidgetItem *pPatientWidget = new QTreeWidgetItem(ui->PatientTreeWidget);
    vector<Consultation *> *pConsultations = new vector<Consultation *>();
    vector<Followup *> *pFollowups = new vector<Followup *>();
    QTreeWidgetItem *pTempWidget;
    QTreeWidgetItem *pTempWidget2;

    pPatientWidget->setText(0, QString::fromStdString(controller->getCurrentPatient()->getLastName() + string(", ") + controller->getCurrentPatient()->getFirstName()));
    pPatientWidget->setData(0, Qt::UserRole, 0); //Patient

    pConsultations = controller->getCurrentPatient()->getConsultations();

    for (unsigned int i = 0 ; i < pConsultations->size() ; i++) {
        //Skip object if marked as deleted
        if (pConsultations->at(i)->isDeleted())
            continue;
        pTempWidget = new QTreeWidgetItem(pPatientWidget);
        pTempWidget->setText(0, QString::fromStdString(string("Consult ") + intToString(pConsultations->at(i)->getDate().getMonth())
                                                       + string("/") + intToString(pConsultations->at(i)->getDate().getDay())));
        pTempWidget->setData(0, Qt::UserRole, 1); //Consultation
        pTempWidget->setData(1, Qt::UserRole, pConsultations->at(i)->getConsultID());

        pFollowups = pConsultations->at(i)->getFollowups();
        for (unsigned int j = 0 ; j < pFollowups->size() ; j++) {
            //Skip object if marked as deleted
            if (pFollowups->at(i)->isDeleted())
                continue;
            pTempWidget2 = new QTreeWidgetItem(pTempWidget);
            pTempWidget2->setText(0, QString::fromStdString(string("Followup ") + intToString(pFollowups->at(j)->getDateDue().getMonth())
                                                            + string("/") + intToString(pFollowups->at(j)->getDateDue().getDay())));
            pTempWidget2->setData(0, Qt::UserRole, 2); //Followup
            pTempWidget2->setData(1, Qt::UserRole, pFollowups->at(j)->getId());

            pTempWidget->addChild(pTempWidget2);
        }

        pPatientWidget->addChild(pTempWidget);
    }

    ui->PatientTreeWidget->addTopLevelItem(pPatientWidget);

    while (!pConsultations->empty()) {
        delete pConsultations->back();
        pConsultations->pop_back();
    }
    if (pConsultations != NULL)
        delete pConsultations;
    while (!pFollowups->empty()) {
        delete pFollowups->back();
        pFollowups->pop_back();
    }
    if (pFollowups != NULL)
        delete pFollowups;
}

void MainWindow::on_ResetFormsPushButton_clicked()
{
    int currentTab = ui->DisplayTabsWidget->currentIndex();

    switch(currentTab){
    case 0: //Patient tab
        if (newPatient)
            enablePatientEditing();
        else
            showPatientInfo();
        break;
    case 1: //Consultation Tab
        if (newConsultation)
            clearConsultationTab();
        else
            showConsultationInfo(ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt());
        break;
    case 2:
        if (newMedicalTest || newMedicationRenewal || newReferral || newReturnConsultation)
            clearFollowupTab();
        else
            showFollowup(ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt(),
                         ui->PatientTreeWidget->currentItem()->parent()->data(1, Qt::UserRole).toInt());
        break;
    }
}

void MainWindow::on_PatientTreeWidget_itemClicked(QTreeWidgetItem *item)
{
    int itemType = item->data(0, Qt::UserRole).toInt();

    switch(itemType){
    case 0: //Patient has been selected
        showPatientInfo();
        break;
    case 1: //Consultation has been selected
        showConsultationInfo(item->data(1, Qt::UserRole).toInt());
        break;
    case 2: //Followup has been selected
        showFollowup(item->data(1, Qt::UserRole).toInt(), item->parent()->data(1, Qt::UserRole).toInt());
        break;
    }
}

void MainWindow::on_SubmitChangesPushButton_clicked()
{
    int currentTab = ui->DisplayTabsWidget->currentIndex();
    string *pError = NULL;
    Consultation::ConsultationStatus cStatus = Consultation::CSTAT_ERROR;
    Followup::FollowupStatus fStatus = Followup::FSTAT_ERROR;
    Physician *pConsultPhysician = NULL;
    vector<Physician *> *pTempPhysicians = NULL;
    Date tempReceivedDate(0,0,0);
    Date tempCompletedDate(0,0,0);
    unsigned int i, j;

    switch(currentTab) {
    case 0: //Patient tab
        if (newPatient) { //create patient
            Patient *pNewPatient = new Patient(NULL,
                                               ui->FirstNameLineEdit->text().toStdString(), ui->LastNameLineEdit->text().toStdString(), ui->PatientNotesTextEdit->toPlainText().toStdString(),
                                               ContactInfo(ui->WorkPhoneLineEdit->text().toStdString(), ui->CellPhoneLineEdit->text().toStdString(),
                                                           ui->EmailLineEdit->text().toStdString(), ui->WorkEmailLineEdit->text().toStdString()),
                                               Address(ui->CountryLineEdit->text().toStdString(), ui->CityLineEdit->text().toStdString(), ui->Address1LineEdit->text().toStdString(),
                                                       ui->Address2LineEdit->text().toStdString(), ui->PostalCodeLineEdit->text().toStdString()),
                                               Date(ui->DOBDateEdit->date().year(), ui->DOBDateEdit->date().month(), ui->DOBDateEdit->date().day()),
                                               Date(ui->AddedDateEdit->date().year(), ui->AddedDateEdit->date().month(), ui->AddedDateEdit->date().day()),
                                               NULL, //not storing patient's physician
                                               HealthCard(ui->CardNumberLineEdit->text().toStdString(), Date(ui->CardExpirationDateEdit->date().year(),
                                                                                                             ui->CardExpirationDateEdit->date().month(),
                                                                                                             ui->CardExpirationDateEdit->date().day())),
                                               false);
            if (controller->createPatient(pNewPatient, NULL, pError)) {
                newPatient = false;
                populatePatientTree();
                showPatientInfo();
            }
            else
                ui->statusbar->showMessage(QString::fromStdString(*pError));

        }
        else { //modify patient
            controller->getCurrentPatient()->setFirstName(ui->FirstNameLineEdit->text().toStdString());
            controller->getCurrentPatient()->setLastName(ui->LastNameLineEdit->text().toStdString());
            controller->getCurrentPatient()->setNotes(ui->PatientNotesTextEdit->toPlainText().toStdString());
            controller->getCurrentPatient()->setContact(ContactInfo(ui->WorkPhoneLineEdit->text().toStdString(), ui->CellPhoneLineEdit->text().toStdString(),
                                                                    ui->EmailLineEdit->text().toStdString(), ui->WorkEmailLineEdit->text().toStdString()));
            controller->getCurrentPatient()->setAddress(Address(ui->CountryLineEdit->text().toStdString(), ui->CityLineEdit->text().toStdString(), ui->Address1LineEdit->text().toStdString(),
                                                                ui->Address2LineEdit->text().toStdString(), ui->PostalCodeLineEdit->text().toStdString()));
            controller->getCurrentPatient()->setDateOfBirth(Date(ui->DOBDateEdit->date().year(), ui->DOBDateEdit->date().month(), ui->DOBDateEdit->date().day()));
            controller->getCurrentPatient()->setDateAddedToSystem(Date(ui->AddedDateEdit->date().year(), ui->AddedDateEdit->date().month(), ui->AddedDateEdit->date().day()));
            controller->getCurrentPatient()->setHealthCard(HealthCard(ui->CardNumberLineEdit->text().toStdString(), Date(ui->CardExpirationDateEdit->date().year(),
                                                                                                                         ui->CardExpirationDateEdit->date().month(),
                                                                                                                         ui->CardExpirationDateEdit->date().day())));

            if (controller->modifyPatient(pError)) {
                populatePatientTree();
                showPatientInfo();
            }
            else
                ui->statusbar->showMessage(QString::fromStdString(*pError));
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

        //Find the corresponding physician object
        if (controller->getPhysicianList(pTempPhysicians, pError)) {
            for (i = 0 ; i < pTempPhysicians->size() ; i++) {
                if (pTempPhysicians->at(i)->getId() == ui->PhysicianSelectComboBox->itemData(ui->PhysicianSelectComboBox->currentIndex(), Qt::UserRole)) {
                    pConsultPhysician = pTempPhysicians->at(i);
                    break;
                }
            }
        }
        else {
            ui->statusbar->showMessage(QString::fromStdString(*pError));
            break;
        }

        if (newConsultation) { //create Consultation
            Consultation *pNewConsultation = new Consultation(NULL,
                                                              ui->ReasonTextEdit->toPlainText().toStdString(), ui->DiagnosisTextEdit->toPlainText().toStdString(),
                                                              ui->ConsultationCommentsTextEdit->toPlainText().toStdString(), cStatus,
                                                              Date(ui->ConsultationDateTimeEdit->date().year(),
                                                                   ui->ConsultationDateTimeEdit->date().month(),
                                                                   ui->ConsultationDateTimeEdit->date().day()),
                                                              Time(ui->ConsultationDateTimeEdit->time().hour(),
                                                                   ui->ConsultationDateTimeEdit->time().minute()),
                                                              pConsultPhysician,
                                                              false);

            if (controller->createConsultation(pNewConsultation, pError)) {
                newConsultation = false;
                populatePatientTree();
                showPatientInfo();
            }
            else
                ui->statusbar->showMessage(QString::fromStdString(*pError));
        }
        else { //modify Consultation
            for (i = 0 ; i < controller->getCurrentPatient()->getConsultations()->size() ; i++) {
                if (controller->getCurrentPatient()->getConsultations()->at(i)->getConsultID() == ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt())
                    break;
            }

            controller->getCurrentPatient()->getConsultations()->at(i)->setReason(ui->ReasonTextEdit->toPlainText().toStdString());
            controller->getCurrentPatient()->getConsultations()->at(i)->setDiagnosis(ui->DiagnosisTextEdit->toPlainText().toStdString());
            controller->getCurrentPatient()->getConsultations()->at(i)->setComments(ui->ConsultationCommentsTextEdit->toPlainText().toStdString());
            controller->getCurrentPatient()->getConsultations()->at(i)->setStatus(cStatus);
            controller->getCurrentPatient()->getConsultations()->at(i)->setDate(Date(ui->ConsultationDateTimeEdit->date().year(),
                                                                                     ui->ConsultationDateTimeEdit->date().month(),
                                                                                     ui->ConsultationDateTimeEdit->date().day()));
            controller->getCurrentPatient()->getConsultations()->at(i)->setTime(Time(ui->ConsultationDateTimeEdit->time().hour(),
                                                                                     ui->ConsultationDateTimeEdit->time().minute()));
            controller->getCurrentPatient()->getConsultations()->at(i)->setConsultingPhys(pConsultPhysician);

            if (controller->modifyConsultation(controller->getCurrentPatient()->getConsultations()->at(i)->getConsultID(), pError)) {
                populatePatientTree();
                showPatientInfo();
            }
            else
                ui->statusbar->showMessage(QString::fromStdString(*pError));
        }
        break;
    case 2: //Followup tab
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

        if (newMedicalTest) { //create Medical Test
            MedicalTest *pNewMedicalTest = new MedicalTest(NULL,
                                                           fStatus,
                                                           Date(ui->DueDateEdit->date().year(),
                                                                ui->DueDateEdit->date().month(),
                                                                ui->DueDateEdit->date().day()),
                                                           tempReceivedDate,
                                                           tempCompletedDate,
                                                           ui->FollowupInfoTextEdit2->toPlainText().toStdString(),
                                                           ui->FollowupInfoTextEdit->toPlainText().toStdString(),
                                                           false);

            if (controller->createFollowup((Followup *)pNewMedicalTest, currentConsultationId, pError)) {
                newMedicalTest = false;
                populatePatientTree();
                showPatientInfo();
            }
            else
                ui->statusbar->showMessage(QString::fromStdString(*pError));
        }
        else if (newMedicationRenewal) { //create Medication Renewal
            MedicationRenewal *pNewMedicationRenewal = new MedicationRenewal(NULL,
                                                                             fStatus,
                                                                             Date(ui->DueDateEdit->date().year(),
                                                                                  ui->DueDateEdit->date().month(),
                                                                                  ui->DueDateEdit->date().day()),
                                                                             tempReceivedDate,
                                                                             tempCompletedDate,
                                                                             ui->FollowupInfoTextEdit->toPlainText().toStdString(),
                                                                             false);

            if (controller->createFollowup((Followup *)pNewMedicationRenewal, currentConsultationId, pError)) {
                newMedicationRenewal = false;
                populatePatientTree();
                showPatientInfo();
            }
            else
                ui->statusbar->showMessage(QString::fromStdString(*pError));
        }
        else if (newReferral) { //create Referral
            Referral *pNewReferral = new Referral(NULL,
                                                  fStatus,
                                                  Date(ui->DueDateEdit->date().year(),
                                                       ui->DueDateEdit->date().month(),
                                                       ui->DueDateEdit->date().day()),
                                                  tempReceivedDate,
                                                  tempCompletedDate,
                                                  ui->FollowupInfoTextEdit2->toPlainText().toStdString(),
                                                  ui->FollowupInfoTextEdit->toPlainText().toStdString(),
                                                  false);

            if (controller->createFollowup((Followup *)pNewReferral, currentConsultationId, pError)) {
                newReferral = false;
                populatePatientTree();
                showPatientInfo();
            }
            else
                ui->statusbar->showMessage(QString::fromStdString(*pError));
        }
        else if (newReturnConsultation) { //create Return Consultation
            ReturnConsultation *pNewReturnConsultation = new ReturnConsultation(NULL,
                                                                                fStatus,
                                                                                Date(ui->DueDateEdit->date().year(),
                                                                                     ui->DueDateEdit->date().month(),
                                                                                     ui->DueDateEdit->date().day()),
                                                                                tempReceivedDate,
                                                                                tempCompletedDate,
                                                                                NULL,
                                                                                false);

            if (controller->createFollowup((Followup *)pNewReturnConsultation, currentConsultationId, pError)) {
                newReturnConsultation = false;
                populatePatientTree();
                showPatientInfo();
            }
            else
                ui->statusbar->showMessage(QString::fromStdString(*pError));
        }
        else { //modify Followup
            //find the current followup
            for (i = 0 ; i < controller->getCurrentPatient()->getConsultations()->size() ; i++) {
                if (controller->getCurrentPatient()->getConsultations()->at(i)->getConsultID() == ui->PatientTreeWidget->currentItem()->parent()->data(1, Qt::UserRole).toInt()) {
                    for (j = 0 ; j < controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->size() ; j++) {
                        if (controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j)->getId() == ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt())
                            break;
                    }
                    break;
                }
            }

            controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j)->setStatus(fStatus);
            controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j)->setDateDue(Date(ui->DueDateEdit->date().year(),
                                                                                                               ui->DueDateEdit->date().month(),
                                                                                                               ui->DueDateEdit->date().day()));
            if (ui->FollowupReceivedCheckBox->isChecked())
                controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j)->setDateReceived(Date(ui->ReceivedDateEdit->date().year(),
                                                                                                                        ui->ReceivedDateEdit->date().month(),
                                                                                                                        ui->ReceivedDateEdit->date().day()));
            if (ui->FollowupCompletedCheckBox->isChecked())
                controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j)->setDateCompleted(Date(ui->CompletedDateEdit->date().year(),
                                                                                                                         ui->CompletedDateEdit->date().month(),
                                                                                                                         ui->CompletedDateEdit->date().day()));
            switch(controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j)->getType()) {
            case 1: //Medical Test
                ((MedicalTest *)controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j))->setTestType(ui->FollowupInfoTextEdit->toPlainText().toStdString());
                ((MedicalTest *)controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j))->setResults(ui->FollowupInfoTextEdit2->toPlainText().toStdString());
                break;
            case 2: //Medication Renewal
                ((MedicationRenewal *)controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j))->setMedication(ui->FollowupInfoTextEdit->toPlainText().toStdString());
                break;
            case 3: //Referral
                ((Referral*)controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j))->setSpecialistName(ui->FollowupInfoTextEdit->toPlainText().toStdString());
                ((Referral*)controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j))->setResults(ui->FollowupInfoTextEdit2->toPlainText().toStdString());
                break;
            case 4: //Return Consultation
                //Nothing extra to do here
                break;
            }

            if ( controller->modifyFollowup(controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j)->getId(),
                                       controller->getCurrentPatient()->getConsultations()->at(i)->getConsultID(),
                                       pError) ) {
                populatePatientTree();
                showPatientInfo();
            }
            else
                ui->statusbar->showMessage(QString::fromStdString(*pError));
        }
        break;
    }

    if (pError != NULL)
        delete pError;
    if (pConsultPhysician != NULL)
        delete pConsultPhysician;
    while (!pTempPhysicians->empty()) {
        delete pTempPhysicians->back();
        pTempPhysicians->pop_back();
    }
    if (pTempPhysicians != NULL)
        delete pTempPhysicians;
}

void MainWindow::on_FollowupReceivedCheckBox_stateChanged(int arg1)
{
    if (arg1 == 0)
        ui->ReceivedDateEdit->setEnabled(false);
    else
        ui->ReceivedDateEdit->setEnabled(true);
}

void MainWindow::on_FollowupCompletedCheckBox_stateChanged(int arg1)
{
    if (arg1 == 0)
        ui->CompletedDateEdit->setEnabled(false);
    else
        ui->CompletedDateEdit->setEnabled(true);
}

void MainWindow::on_CreateConsultationPushButton_clicked()
{
    newConsultation = true;
    ui->DeleteConsultationPushButton->setEnabled(false);
    clearConsultationTab();
    ui->DisplayTabsWidget->setTabEnabled(1, true);
    ui->DisplayTabsWidget->setCurrentIndex(1);
    ui->DisplayTabsWidget->setTabEnabled(0, false);
    ui->DisplayTabsWidget->setTabEnabled(2, false);
}

void MainWindow::on_CreateFollowupPushButton_clicked()
{
    int fType = 1;
    FollowupTypeSelectDialog fTypeDialog(&fType);
    if (fTypeDialog.exec()) {
        switch(fType) {
        case 1:
            newMedicalTest = true;
            ui->FollowupInfoLabel->setText("Test Type:");
            ui->FollowupInfoLabel->show();
            ui->FollowupInfoLabel2->setText("Results:");
            ui->FollowupInfoLabel2->show();
            ui->FollowupInfoTextEdit->show();
            ui->FollowupInfoTextEdit2->show();
            break;
        case 2:
            newMedicationRenewal = true;
            ui->FollowupInfoLabel->setText("Medication:");
            ui->FollowupInfoLabel->show();
            ui->FollowupInfoLabel2->hide();
            ui->FollowupInfoTextEdit->show();
            ui->FollowupInfoTextEdit2->hide();
            break;
        case 3:
            newReferral = true;
            ui->FollowupInfoLabel->setText("Specialist Name:");
            ui->FollowupInfoLabel->show();
            ui->FollowupInfoLabel2->setText("Results:");
            ui->FollowupInfoLabel2->show();
            ui->FollowupInfoTextEdit->show();
            ui->FollowupInfoTextEdit2->show();
            break;
        case 4:
            newReturnConsultation = true;
            ui->FollowupInfoLabel->hide();
            ui->FollowupInfoLabel2->hide();
            ui->FollowupInfoTextEdit->hide();
            ui->FollowupInfoTextEdit2->hide();
            break;
        }

        currentConsultationId = ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole).toInt();
        ui->DeleteFollowupPushButton->setEnabled(false);
        clearFollowupTab();
        ui->DisplayTabsWidget->setTabEnabled(2, true);
        ui->DisplayTabsWidget->setCurrentIndex(2);
        ui->DisplayTabsWidget->setTabEnabled(0, false);
        ui->DisplayTabsWidget->setTabEnabled(1, false);
    }

}

void MainWindow::on_DeletePatientPushButton_clicked()
{
    string *pError = NULL;

    controller->getCurrentPatient()->markDeleted();

    if (controller->modifyPatient(pError)) {
        enablePatientEditing(); //called since it clears the fields
        disablePatientEditing();
        ui->PatientTreeWidget->clear();
        ui->CreateConsultationPushButton->setEnabled(false);
    }
    else
        ui->statusbar->showMessage(QString::fromStdString(*pError));

    if (pError != NULL)
        delete pError;
}

void MainWindow::on_DeleteConsultationPushButton_clicked()
{
    string *pError = NULL;
    unsigned int i;

    for (i= 0 ; i < controller->getCurrentPatient()->getConsultations()->size() ; i++) {
        if (controller->getCurrentPatient()->getConsultations()->at(i)->getConsultID() == ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole)) {
            controller->getCurrentPatient()->getConsultations()->at(i)->markDeleted();
            break;
        }
    }

    if (controller->modifyConsultation(controller->getCurrentPatient()->getConsultations()->at(i)->getConsultID(), pError)) {
        populatePatientTree();
        showPatientInfo();
    }
    else
        ui->statusbar->showMessage(QString::fromStdString(*pError));

    if (pError != NULL)
        delete pError;
}

void MainWindow::on_DeleteFollowupPushButton_clicked()
{
    string *pError = NULL;
    unsigned int i, j;

    for (i= 0 ; i < controller->getCurrentPatient()->getConsultations()->size() ; i++) {
        if (controller->getCurrentPatient()->getConsultations()->at(i)->getConsultID() == ui->PatientTreeWidget->currentItem()->parent()->data(1, Qt::UserRole)) {
            for (j = 0 ; j < controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->size() ; j++) {
                if (controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j)->getId() == ui->PatientTreeWidget->currentItem()->data(1, Qt::UserRole)) {
                    controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j)->markDeleted();
                    break;
                }
            }
            break;
        }
    }

    if (controller->modifyFollowup(controller->getCurrentPatient()->getConsultations()->at(i)->getFollowups()->at(j)->getId(),
                                   controller->getCurrentPatient()->getConsultations()->at(i)->getConsultID(), pError)) {
        populatePatientTree();
        showPatientInfo();
    }
    else
        ui->statusbar->showMessage(QString::fromStdString(*pError));

    if (pError != NULL)
        delete pError;
}

string MainWindow::intToString(int x)
{
    stringstream tempStream;
    tempStream << x;
    return tempStream.str();
}
