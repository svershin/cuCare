#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

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

    void on_ResetFormsPushButton_clicked();

    void on_PatientTreeWidget_itemClicked(QTreeWidgetItem *item);

    void on_SubmitChangesPushButton_clicked();

    void on_FollowupReceivedCheckBox_stateChanged(int arg1);

    void on_FollowupCompletedCheckBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    MasterController *controller;

    vector<Physician*> *pPhysicians;

    void enablePatientEditing();
    void disablePatientEditing();

    void showPatientInfo();
    void showConsultationInfo(int cid);

    void showFollowup(int fid, int cid);
    void showMedicalTest(MedicalTest *pMedicalTest);
    void showMedicationRenewal(MedicationRenewal *pMedicationRenewal);
    void showReferral(Referral *pReferral);
    void showReturnConsultation(ReturnConsultation *pReturnConsultation);

    void clearConsultationTab();
    void clearFollowupTab();

    void populatePhysicians();
    void populatePatientTree();

    bool newPatient;
    bool newConsultation;
    bool newFollowup;
};

#endif // MAINWINDOW_H
