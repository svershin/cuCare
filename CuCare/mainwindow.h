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

    void on_PatientTreeWidget_itemClicked(QTreeWidgetItem *item, int column);

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
    void showResultantFollowup(ResultantFollowup *pResultantFollowup);
    void showReturnConsultation(ReturnConsultation *pReturnConsultation);

    void populatePhysicians();
    void populatePatientTree();

    bool newPatient;
    bool newConsultation;
    bool newFollowup;
};

#endif // MAINWINDOW_H
