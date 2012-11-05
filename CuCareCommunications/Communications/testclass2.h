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
    Q_PROPERTY(QVariantMap m_addr READ qGetAddr)

public:

    TestClass2(string, int, Address);
    TestClass2(const TestClass2&);
    TestClass2& operator=(const TestClass2&);

    string name();
    void setName(const string& name);
    QString qName();
    void qSetName(const QString& name);

    int phoneNumber();
    void setPhoneNumber(const int  phoneNumber);

    Address getAddr();
    void setAddr(const Address& Address);

    QVariantMap qGetAddr();

    private:
    string m_name;
    int m_phoneNumber;
    Address m_addr;

};

#endif // TESTCLASS2_H
