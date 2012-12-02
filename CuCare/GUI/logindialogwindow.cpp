#include "logindialogwindow.h"
#include "ui_logindialogwindow.h"

LoginDialogWindow::LoginDialogWindow(AccessControl *accessControlParam, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialogWindow),
    accessControl(accessControlParam)
{
    ui->setupUi(this);
}

LoginDialogWindow::~LoginDialogWindow()
{
    delete ui;
}

void LoginDialogWindow::on_LogInPushButton_clicked()
{
    clearStatus();

    if (checkUsername())
        accept();
}

bool LoginDialogWindow::checkUsername()
{
    AccessControl::LoginStatus status = AccessControl::AC_LOGGED_OUT;

    try {
        status = accessControl->verifyUsername(ui->UsernameLineEdit->text().toStdString());
    }
    catch (char * err) {
        ui->StatusLabel->setText(QString::fromStdString(err));
    }

    if (status == AccessControl::AC_LOGGED_IN_AS_PHYSICIAN
            || status == AccessControl::AC_LOGGED_IN_AS_ADMINASSISTANT)
        return true;

    ui->StatusLabel->setText("Invalid Username.");
    return false;
}

void LoginDialogWindow::clearStatus()
{
    ui->StatusLabel->clear();
}
