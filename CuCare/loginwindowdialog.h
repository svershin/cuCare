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
    
private slots:
    void on_LogInPushButton_clicked();

private:
    Ui::LoginWindowDialog *ui;
    MasterController *controller;

    bool checkUsername();
};

#endif // LOGINWINDOWDIALOG_H
