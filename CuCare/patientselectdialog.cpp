#include "patientselectdialog.h"
#include "ui_patientselectdialog.h"

PatientSelectDialog::PatientSelectDialog(MasterController *controllerParam, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientSelectDialog),
    controller(controllerParam),
    pPatientList(NULL)
{
    ui->setupUi(this);

    //Disable UI elements for features not yet implemented
    ui->FilterComboBox->setEnabled(false);
    ui->FilterLineEdit->setEnabled(false);
    ui->FilterPushButton->setEnabled(false);

    //Disable 'select' button until a patient has been selected
    ui->SelectPushButton->setEnabled(false);

    //Populate the list with patient names.
    string *pErrorString = NULL;
    QListWidgetItem *tempListItem;

    if ( controller->getPatientList(pPatientList, pErrorString) ) {
        ui->PatientListWidget->setSortingEnabled(true);
        for (unsigned int i = 0 ; i < pPatientList->size() ; i++) {
            //Skip the patient if they are marked as deleted
            if (pPatientList->at(i)->isDeleted())
                continue;
            //Build the list item in the format "Lastname, Firstname"
            //Populate the list item, also storing the patient ID for simple patient selection.
            tempListItem = new QListWidgetItem(QString::fromStdString(pPatientList->at(i)->getLastName() + string(", ") + pPatientList->at(i)->getFirstName()));
            tempListItem->setData(Qt::UserRole, pPatientList->at(i)->getId());

            ui->PatientListWidget->addItem(tempListItem);
        }
    }
    if (pErrorString != NULL)
        delete pErrorString;
    if (tempListItem != NULL)
        delete tempListItem;
}

PatientSelectDialog::~PatientSelectDialog()
{
    while (!pPatientList->empty()) {
        delete pPatientList->back();
        pPatientList->pop_back();
    }
    if (pPatientList != NULL)
        delete pPatientList;
    delete ui;
}

void PatientSelectDialog::on_SelectPushButton_clicked()
{
    int lookupId = ui->PatientListWidget->currentItem()->data(Qt::UserRole).toInt();
    string *pErrorString = NULL;

    if (controller->setCurrentPatient(lookupId, pErrorString)) {
        if (pErrorString != NULL)
            delete pErrorString;
        accept();
    }
    if (pErrorString != NULL)
        delete pErrorString;
}

void PatientSelectDialog::on_CancelPushButton_clicked()
{
    reject();
}

void PatientSelectDialog::on_PatientListWidget_currentRowChanged()
{
    //enable the 'Select' button
    ui->SelectPushButton->setEnabled(true);
}
