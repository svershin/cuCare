#ifndef TESTCLASS2_H
#define TESTCLASS2_H

#include <QObject>
#include <QtGlobal>
#include "commsinclude.h"

class TestClass2 : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(int phoneNumber READ phoneNumber WRITE setPhoneNumber)
    Q_PROPERTY(Gender gender READ gender WRITE setGender)
    Q_PROPERTY(QDate dob READ dob WRITE setDob)
    Q_ENUMS(Gender)

public:
    TestClass2(QObject *parent = 0);

    QString name() const;
    void setName(const QString& name);

    int phoneNumber() const;
    void setPhoneNumber(const int  phoneNumber);

    enum Gender {Male, Female};
    void setGender(Gender gender);
    Gender gender() const;

    QDate dob() const;
    void setDob(const QDate& dob);

    private:
    QString m_name;
    int m_phoneNumber;
    Gender m_gender;
    QDate m_dob;

};

#endif // TESTCLASS2_H
