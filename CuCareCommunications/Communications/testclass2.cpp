#include "testclass2.h"

TestClass2::TestClass2(const TestClass2& origin) :
    QObject(),
    m_name (origin.m_name),
    m_phoneNumber (origin.m_phoneNumber),
    m_dob (origin.m_dob)
{}

TestClass2& TestClass2::operator =(const TestClass2 &origin)
{
    m_name = origin.m_name;
    m_phoneNumber = origin.m_phoneNumber;
    m_dob = origin.m_dob;
    return *this;
}


TestClass2::TestClass2(string s, int i1, QDate date) :
    QObject()
{
    m_name = s;
    m_phoneNumber = i1;
    m_dob = date;
}

    QString TestClass2::qName(){return QString::fromStdString(m_name);}
void TestClass2::qSetName(const QString& name){m_name = name.toStdString();return;}
string TestClass2::name(){return m_name;}
void TestClass2::setName(const string& name){m_name = name;return;}


int TestClass2::phoneNumber() {return m_phoneNumber;}
void TestClass2::setPhoneNumber(const int  phoneNumber){m_phoneNumber = 7; return;}

QDate TestClass2::dob() {return m_dob;}
void TestClass2::setDob(const QDate& dob){m_dob = dob; return;}
