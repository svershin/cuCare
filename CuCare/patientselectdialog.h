#ifndef PATIENTSELECTDIALOG_H
#define PATIENTSELECTDIALOG_H

#include <QDialog>

#include "MasterController/MasterController.h"

namespace Ui {
class PatientSelectDialog;
}

class PatientSelectDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PatientSelectDialog(MasterController *controllerParam, QWidget *parent = 0);
    ~PatientSelectDialog();
    
private:
    Ui::PatientSelectDialog *ui;
    MasterController *controller;
};

#endif // PATIENTSELECTDIALOG_H
