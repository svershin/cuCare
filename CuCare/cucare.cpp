#include "cucare.h"
#include "ui_cucare.h"

CuCare::CuCare(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CuCare)
{
    ui->setupUi(this);
}

CuCare::~CuCare()
{
    delete ui;
}
