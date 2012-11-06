#ifndef FOLLOWUPTYPESELECTDIALOG_H
#define FOLLOWUPTYPESELECTDIALOG_H

#include <QDialog>

namespace Ui {
class FollowupTypeSelectDialog;
}

class FollowupTypeSelectDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit FollowupTypeSelectDialog(int *typeParameter, QWidget *parent = 0);
    ~FollowupTypeSelectDialog();
    
private slots:
    void on_SelectPushButton_clicked();

    void on_CancelPushButton_clicked();

private:
    Ui::FollowupTypeSelectDialog *ui;
    int *followupType;
};

#endif // FOLLOWUPTYPESELECTDIALOG_H
