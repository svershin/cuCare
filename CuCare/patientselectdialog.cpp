#include "patientselectdialog.h"
#include "ui_patientselectdialog.h"

PatientSelectDialog::PatientSelectDialog(MasterController *controllerParam,
                                         Patient *patientParam, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientSelectDialog),
    controller(controllerParam),
    returnPatient(patientParam)
{
    ui->setupUi(this);

    //Disable UI elements for features not yet implemented
    ui->FilterComboBox->setEnabled(false);
    ui->FilterLineEdit->setEnabled(false);
    ui->FilterPushButton->setEnabled(false);
}

PatientSelectDialog::~PatientSelectDialog()
{
    delete ui;
}

void PatientSelectDialog::on_SelectPushButton_clicked()
{

}

void PatientSelectDialog::on_CancelPushButton_clicked()
{
    reject();
}
