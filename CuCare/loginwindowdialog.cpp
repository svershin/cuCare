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
    QString userString = ui->UsernameLineEdit->text();
    MasterController::AccessControlStatus loginStatus;

    loginStatus = controller->loginUser(userString.toStdString());

    if (loginStatus == MasterController::AC_LOGGED_IN_AS_PHYSICIAN
            || loginStatus == MasterController::AC_LOGGED_IN_AS_ADMINASSISTANT
            || loginStatus == MasterController::AC_LOGGED_IN_AS_SYSADMIN)
        return true;

    return false;
}

void LoginWindowDialog::on_LogInPushButton_clicked()
{
    if (checkUsername())
        accept();
}
