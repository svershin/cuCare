#include "loginwindowdialog.h"
#include "ui_loginwindowdialog.h"

LoginWindowDialog::LoginWindowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindowDialog)
{
    ui->setupUi(this);
}

LoginWindowDialog::~LoginWindowDialog()
{
    delete ui;
}
