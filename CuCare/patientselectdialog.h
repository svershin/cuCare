#ifndef PATIENTSELECTDIALOG_H
#define PATIENTSELECTDIALOG_H

#include <QDialog>

#include "MasterController/MasterController.h"
#include "../CuCareModel/Patient.h"
#include <vector>


namespace Ui {
class PatientSelectDialog;
}

class PatientSelectDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PatientSelectDialog(MasterController *controllerParam, QWidget *parent = 0);
    ~PatientSelectDialog();
    
private slots:
    void on_SelectPushButton_clicked();

    void on_CancelPushButton_clicked();

    void on_PatientListWidget_currentRowChanged(int currentRow);

private:
    Ui::PatientSelectDialog *ui;
    MasterController *controller;

    vector<Patient *> *pPatientList;
};

#endif // PATIENTSELECTDIALOG_H
