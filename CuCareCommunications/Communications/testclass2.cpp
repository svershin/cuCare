#include "testclass2.h"

TestClass2::TestClass2(QObject *parent) :
    QObject(parent)
{
}

QString TestClass2::name() const
{
    return m_name;
}

void TestClass2::setName(const QString& name){m_name = name;return;}

int TestClass2::phoneNumber() const{return m_phoneNumber;}
void TestClass2::setPhoneNumber(const int  phoneNumber){m_phoneNumber = 7; return;}


void TestClass2::setGender(Gender gender){m_gender = gender; return;}
TestClass2::Gender TestClass2::gender() const{return m_gender;}

QDate TestClass2::dob() const{return m_dob;}
void TestClass2::setDob(const QDate& dob){m_dob = dob; return;}
