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
