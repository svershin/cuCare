#ifndef LOGINWINDOWDIALOG_H
#define LOGINWINDOWDIALOG_H

#include <QDialog>

#include "MasterController/MasterController.h"

namespace Ui {
class LoginWindowDialog;
}

class LoginWindowDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginWindowDialog(MasterController *controllerParam, QWidget *parent = 0);
    ~LoginWindowDialog();
    
private:
    Ui::LoginWindowDialog *ui;
    MasterController *controller;
};

#endif // LOGINWINDOWDIALOG_H
