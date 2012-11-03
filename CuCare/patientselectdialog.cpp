#include "patientselectdialog.h"
#include "ui_patientselectdialog.h"

PatientSelectDialog::PatientSelectDialog(MasterController *controllerParam, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientSelectDialog),
    controller(controllerParam)
{
    ui->setupUi(this);
}

PatientSelectDialog::~PatientSelectDialog()
{
    delete ui;
}
