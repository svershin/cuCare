#ifndef ACCESSCONTROL_H
#define ACCESSCONTROL_H

#include <string>
#include <list>
using namespace std;

#include "../ClientDataStorage/ClientData.h"
#include "../../CuCareModel/ModelFiles.h"

class AccessControl
{
public:
    AccessControl();

    enum LoginStatus {
        AC_FAILED,
        AC_LOGGED_OUT,
        AC_LOGGED_IN_AS_PHYSICIAN,
        AC_LOGGED_IN_AS_ADMINASSISTANT,
        AC_LOGGED_IN_AS_SYSADMIN
    };

    LoginStatus verifyUsername(string username);

    LoginStatus getLoginStatus();

    void logOut();

private:
    void setupFilter(ModelObject *filterObject);

    LoginStatus status;
};

#endif // ACCESSCONTROL_H
