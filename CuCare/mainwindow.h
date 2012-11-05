#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "MasterController/MasterController.h"
#include "patientselectdialog.h"
#include "../CuCareModel/ModelFiles.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(MasterController *controllerParam, QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_NewPatientPushButton_clicked();

    void on_SelectPatientPushButton_clicked();

private:
    Ui::MainWindow *ui;
    MasterController *controller;

    void enablePatientEditing();
    void disablePatientEditing();

    void showPatientInfo();
    void showConsultationInfo(Consultation *pConsultation);

    void showFollowup();
    void showMedicalTest(MedicalTest *pMedicalTest);
    void showMedicationRenewal(MedicationRenewal *pMedicationRenewal);
    void showReferral(Referral *pReferral);
    void showResultantFollowup(ResultantFollowup *pResultantFollowup);
    void showReturnConsultation(ReturnConsultation *pReturnConsultation);

    void populatePhysicians();
};

#endif // MAINWINDOW_H
