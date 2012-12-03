#ifndef LOGINDIALOGWINDOW_H
#define LOGINDIALOGWINDOW_H

#include <QDialog>
#include "../GuiServices/AccessControl.h"

namespace Ui {
class LoginDialogWindow;
}

class LoginDialogWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginDialogWindow(AccessControl *accessControlParam, QWidget *parent = 0);
    ~LoginDialogWindow();
    
private slots:
    void on_LogInPushButton_clicked();

private:
    Ui::LoginDialogWindow *ui;
    AccessControl *accessControl;

    bool checkUsername();

    void clearStatus();
};

#endif // LOGINDIALOGWINDOW_H
