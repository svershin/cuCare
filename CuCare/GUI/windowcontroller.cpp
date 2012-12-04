#include "windowcontroller.h"

WindowController::WindowController(AccessControl *accessControlParam, PatientData *patientDataParam) :
    accessControl(accessControlParam),
    patientData(patientDataParam)
{
}

WindowController::~WindowController()
{
}

int WindowController::start()
{
    while (true) {
        loginWindow = new LoginDialogWindow(accessControl);
        if (loginWindow->exec() != 1)
            break;
        delete loginWindow;
        patientWindow = new PatientViewWindow(accessControl, patientData);
        if (patientWindow->exec() != 1)
            break;
        delete patientWindow;
    }

    return 0;
}
