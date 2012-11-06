#include "followuptypeselectdialog.h"
#include "ui_followuptypeselectdialog.h"

FollowupTypeSelectDialog::FollowupTypeSelectDialog(int *typeParameter, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FollowupTypeSelectDialog),
    followupType(typeParameter)
{
    ui->setupUi(this);
}

FollowupTypeSelectDialog::~FollowupTypeSelectDialog()
{
    delete ui;
}

void FollowupTypeSelectDialog::on_SelectPushButton_clicked()
{
    if (ui->MedicalTestRadioButton->isChecked())
        *followupType = 1;
    else if (ui->MedicationRenewalRadioButton->isChecked())
        *followupType = 2;
    else if (ui->ReferralRadioButton->isChecked())
        *followupType = 3;
    else
        *followupType = 4;

    accept();
}

void FollowupTypeSelectDialog::on_CancelPushButton_clicked()
{
    reject();
}
