#ifndef LOGINWINDOWDIALOG_H
#define LOGINWINDOWDIALOG_H

#include <QDialog>

namespace Ui {
class LoginWindowDialog;
}

class LoginWindowDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginWindowDialog(QWidget *parent = 0);
    ~LoginWindowDialog();
    
private:
    Ui::LoginWindowDialog *ui;
};

#endif // LOGINWINDOWDIALOG_H
