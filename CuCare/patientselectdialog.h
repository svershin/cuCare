#ifndef PATIENTSELECTDIALOG_H
#define PATIENTSELECTDIALOG_H

#include <QDialog>

#include "MasterController/MasterController.h"
#include "../CuCareModel/Patient.h"

namespace Ui {
class PatientSelectDialog;
}

class PatientSelectDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PatientSelectDialog(MasterController *controllerParam, Patient *patientParam,
                                 QWidget *parent = 0);
    ~PatientSelectDialog();
    
private slots:
    void on_SelectPushButton_clicked();

    void on_CancelPushButton_clicked();

private:
    Ui::PatientSelectDialog *ui;
    MasterController *controller;
    Patient *returnPatient;
};

#endif // PATIENTSELECTDIALOG_H
