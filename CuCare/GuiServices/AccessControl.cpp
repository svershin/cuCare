#include "AccessControl.h"

AccessControl::AccessControl()
    : status(AC_LOGGED_OUT) {
}

AccessControl::LoginStatus AccessControl::verifyUsername(string username)
{
    ClientData& clientData = ClientData::getInstance();

    list<int> users;

    Physician physician;
    physician.setUsername(username);
    setupFilter(&physician);

    users = clientData.pull(&physician);
    if(!users.empty()) {
        status = AC_LOGGED_IN_AS_PHYSICIAN;
        return status;
    }

    AdminAssistant adminAssistant;
    adminAssistant.setUsername(username);
    setupFilter(&adminAssistant);

    users = clientData.pull(&adminAssistant);
    if(!users.empty()) {
        status = AC_LOGGED_IN_AS_ADMINASSISTANT;
        return status;
    }

    SysAdmin sysAdmin;
    sysAdmin.setUsername(username);
    setupFilter(&sysAdmin);

    users = clientData.pull(&sysAdmin);
    if(!users.empty()) {
        status = AC_LOGGED_IN_AS_SYSADMIN;
        return status;
    }

    return AC_FAILED;
}

AccessControl::LoginStatus AccessControl::getLoginStatus() {
    return status;
}

void AccessControl::logOut()
{
    status = AC_LOGGED_OUT;
}

void AccessControl::setupFilter(ModelObject* filterObject) {
    list<Property*> *filters = filterObject->getProperties();
    Property *idProp = NULL;
    for(list<Property*>::iterator it = filters->begin(); it != filters->end(); ++it)
        if((*it)->getName() == "username")
            idProp = (*it);
    filters->clear();
    filters->push_back(idProp);
}

