#ifndef CUCARE_H
#define CUCARE_H

#include <QMainWindow>

namespace Ui {
class CuCare;
}

class CuCare : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CuCare(QWidget *parent = 0);
    ~CuCare();
    
private:
    Ui::CuCare *ui;
};

#endif // CUCARE_H
