#include "patientselectdialog.h"
#include "ui_patientselectdialog.h"

PatientSelectDialog::PatientSelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientSelectDialog)
{
    ui->setupUi(this);
}

PatientSelectDialog::~PatientSelectDialog()
{
    delete ui;
}
