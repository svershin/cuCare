#ifndef PATIENTVIEWWINDOW_H
#define PATIENTVIEWWINDOW_H

#include <QDialog>
#include <QTreeWidget>
#include "patientselectdialogwindow.h"
#include "../CuCareModel/ModelFiles.h"
#include "../GuiServices/AccessControl.h"
#include "../GuiServices/PatientData.h"

namespace Ui {
class PatientViewWindow;
}

class PatientViewWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit PatientViewWindow(AccessControl *accessControlParam,
                               PatientData *patientDataParam, QWidget *parent = 0);
    ~PatientViewWindow();
    
private slots:
    void on_NewPatientPushButton_clicked();

    void on_SelectPatientPushButton_clicked();

    void on_CreateConsultationPushButton_clicked();

    void on_LogOutPushButton_clicked();

    void on_ResetFormsPushButton_clicked();

    void on_SubmitChangesPushButton_clicked();

    void on_CreateFollowupPushButton_clicked();

    void on_FollowupTypeComboBox_currentIndexChanged(int index);

    void on_FollowupReceivedCheckBox_stateChanged(int arg1);

    void on_FollowupCompletedCheckBox_stateChanged(int arg1);

    void on_PatientTreeWidget_itemClicked(QTreeWidgetItem *item);

private:
    Ui::PatientViewWindow *ui;
    AccessControl *accessControl;
    PatientData *patientData;

    int currentPatientId;
    int currentConsultationId;

    int prevStatusIndex;

    bool newPatient;
    bool newConsultation;
    bool newFollowup;

    void initializeUi();

    void enablePatientEditing();
    void disablePatientEditing();

    void clearPatientInfo();
    void clearConsultationInfo();
    void clearFollowupInfo();

    void showPatientInfo();
    void showConsultationInfo(int cid);
    void showFollowupInfo(int fid);

    void populatePatientTree();
    void populatePhysicianLists();

    void clearStatus();
    string intToString(int x);
};

#endif // PATIENTVIEWWINDOW_H
