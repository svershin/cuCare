#include "patientselectdialogwindow.h"
#include "ui_patientselectdialogwindow.h"

PatientSelectDialogWindow::PatientSelectDialogWindow(PatientData *patientDataParam, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientSelectDialogWindow),
    patientData(patientDataParam),
    selectedPid(-1)
{
    list<Physician *> pPhysicianList;

    ui->setupUi(this);

    //Populate the list of physicians
    try {
        pPhysicianList = patientData->getPhysicianList();
    }
    catch (char * err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }

    while(pPhysicianList.size() != 0) {
        ui->PhysicianFilterComboBox->addItem(QString::fromStdString(pPhysicianList.front()->getLastName() + string(", ") + pPhysicianList.front()->getFirstName()), pPhysicianList.front()->getPhysicianId());
        pPhysicianList.pop_front();
    }

    //Ensure both filter types are currently not enabled
    ui->PhysicianFilterComboBox->setCurrentIndex(0);
    ui->FollowupStatusFilterComboBox->setCurrentIndex(0);

    //Populate the list, initially unfiltered
    ui->PatientListWidget->setSortingEnabled(true);
    refreshList();
}

PatientSelectDialogWindow::~PatientSelectDialogWindow()
{
    delete ui;
}

int PatientSelectDialogWindow::getSelectedPid()
{
    return selectedPid;
}

void PatientSelectDialogWindow::on_FilterPushButton_clicked()
{
    clearStatus();
    refreshList();
}

void PatientSelectDialogWindow::on_PatientListWidget_currentRowChanged()
{
    clearStatus();
    //enable the 'Select' button
    ui->SelectPushButton->setEnabled(true);
}

void PatientSelectDialogWindow::on_SelectPushButton_clicked()
{
    selectedPid = ui->PatientListWidget->currentItem()->data(Qt::UserRole).toInt();

    accept();
}

void PatientSelectDialogWindow::on_CancelPushButton_clicked()
{
    reject();
}

void PatientSelectDialogWindow::refreshList()
{
    list<Patient *> pPatientList;
    PatientData::FilterType filterType = PatientData::NO_FILTER;
    ModelObject::FollowupStatus followupStatus = ModelObject::FSTAT_ERROR;

    QListWidgetItem *tempListItem = NULL;

    //disable the 'Select' button until a patient has been selected
    ui->SelectPushButton->setEnabled(false);

    //Clear the previous contents
    ui->PatientListWidget->clear();

    //Determine if any filters are to be applied
    if (ui->PhysicianFilterComboBox->currentIndex() != 0
            && ui->FollowupStatusFilterComboBox->currentIndex() != 0)
        filterType = PatientData::FILTER_BY_PHYSICIAN_AND_FOLLOWUP_STATUS;
    else if (ui->PhysicianFilterComboBox->currentIndex() != 0)
        filterType = PatientData::FILTER_BY_PHYSICIAN;
    else if (ui->FollowupStatusFilterComboBox->currentIndex() != 0)
        filterType = PatientData::FILTER_BY_FOLLOWUP_STATUS;
    else
        filterType = PatientData::NO_FILTER;

    //Determine the followup status if it is selected as a filter
    if (ui->FollowupStatusFilterComboBox->currentIndex() != 0)
    {
        switch(ui->FollowupStatusFilterComboBox->currentIndex()) {
        case 1:
            followupStatus = ModelObject::FSTAT_PENDING;
            break;
        case 2:
            followupStatus = ModelObject::FSTAT_OVERDUE;
            break;
        case 3:
            followupStatus = ModelObject::FSTAT_RECEIVED;
            break;
        case 4:
            followupStatus = ModelObject::FSTAT_COMPLETED;
            break;
        }
    }

    //Populate the patient list
    try {
        pPatientList = patientData->getPatientList(filterType,
                                                   ui->PhysicianFilterComboBox->itemData(ui->PhysicianFilterComboBox->currentIndex(), Qt::UserRole).toInt(),
                                                   followupStatus);
    }
    catch (char * err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }

    while (pPatientList.size() != 0) {
        tempListItem = new QListWidgetItem(QString::fromStdString(pPatientList.front()->getLastName() + string(", ") + pPatientList.front()->getFirstName()));
        tempListItem->setData(Qt::UserRole, pPatientList.front()->getId());

        ui->PatientListWidget->addItem(tempListItem);
        pPatientList.pop_front();
    }
//    if (tempListItem != NULL) //TODO: What is this?  We delete the last item?  This was causing one item to be missing from the patient select dialog
//        delete tempListItem;
}

void PatientSelectDialogWindow::clearStatus()
{
    ui->StatusLabel->clear();
}
