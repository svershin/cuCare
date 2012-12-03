#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include "logindialogwindow.h"
#include "patientviewwindow.h"
//include access control and patientdata

class WindowController
{
public:
    WindowController(AccessControl *accessControlParam, PatientData *patientDataParam);
    ~WindowController();

    int start();

private:
    AccessControl *accessControl;
    PatientData *patientData;

    LoginDialogWindow *loginWindow;
    PatientViewWindow *patientWindow;
};

#endif // WINDOWCONTROLLER_H
