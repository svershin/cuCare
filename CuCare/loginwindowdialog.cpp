#include "loginwindowdialog.h"
#include "ui_loginwindowdialog.h"

LoginWindowDialog::LoginWindowDialog(MasterController *controllerParam, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindowDialog),
    controller(controllerParam)
{
    ui->setupUi(this);
}

LoginWindowDialog::~LoginWindowDialog()
{
    delete ui;
}

bool LoginWindowDialog::checkUsername()
{
    MasterController::AccessControlStatus loginStatus;
    string *pErrorString = NULL;

    loginStatus = controller->loginUser(ui->UsernameLineEdit->text().toStdString(), pErrorString);

    if (loginStatus == MasterController::AC_LOGGED_IN_AS_PHYSICIAN
            || loginStatus == MasterController::AC_LOGGED_IN_AS_ADMINASSISTANT
            || loginStatus == MasterController::AC_LOGGED_IN_AS_SYSADMIN) {
        if (pErrorString != NULL)
            delete pErrorString;
        return true;
    }

    if (pErrorString != NULL)
        delete pErrorString;
    return false;
}

void LoginWindowDialog::on_LogInPushButton_clicked()
{
    if (checkUsername())
        accept();
}
