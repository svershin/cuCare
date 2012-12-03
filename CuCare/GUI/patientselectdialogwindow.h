#ifndef PATIENTSELECTDIALOGWINDOW_H
#define PATIENTSELECTDIALOGWINDOW_H

#include <QDialog>
#include <list>
#include "../CuCareModel/Patient.h"
#include "../CuCareModel/Physician.h"
#include "../GuiServices/PatientData.h"

namespace Ui {
class PatientSelectDialogWindow;
}

class PatientSelectDialogWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit PatientSelectDialogWindow(PatientData *patientDataParam, QWidget *parent = 0);
    ~PatientSelectDialogWindow();

    int getSelectedPid();
    
private slots:
    void on_FilterPushButton_clicked();

    void on_PatientListWidget_currentRowChanged();

    void on_SelectPushButton_clicked();

    void on_CancelPushButton_clicked();

private:
    Ui::PatientSelectDialogWindow *ui;
    PatientData *patientData;

    int selectedPid;

    void refreshList();

    void clearStatus();
};

#endif // PATIENTSELECTDIALOGWINDOW_H
