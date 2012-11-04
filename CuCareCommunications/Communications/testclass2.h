#ifndef TESTCLASS2_H
#define TESTCLASS2_H

#include <QObject>
#include <QtGlobal>
#include "commsinclude.h"

class TestClass2 : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString m_name READ qName WRITE qSetName)
    Q_PROPERTY(int m_phoneNumber READ phoneNumber WRITE setPhoneNumber)
    Q_PROPERTY(QDate m_dob READ dob WRITE setDob)

public:

    TestClass2(string, int, QDate);

    TestClass2(const TestClass2&);
    TestClass2& operator=(const TestClass2&);

    string name();
    void setName(const string& name);
    QString qName();
    void qSetName(const QString& name);

    int phoneNumber();
    void setPhoneNumber(const int  phoneNumber);

    QDate dob();
    void setDob(const QDate& dob);

    private:
    string m_name;
    int m_phoneNumber;
    QDate m_dob;

};

#endif // TESTCLASS2_H
