#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "MasterController/MasterController.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(MasterController *controllerParam, QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    MasterController *controller;
};

#endif // MAINWINDOW_H
