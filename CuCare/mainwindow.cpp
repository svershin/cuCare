#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(MasterController *controllerParam, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    controller(controllerParam)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
