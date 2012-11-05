#include "testclass2.h"

TestClass2::TestClass2(string s, int i1, Address addr) :
    QObject()
{
    m_name = s;
    m_phoneNumber = i1;
    m_addr = addr;
}

TestClass2::TestClass2(const TestClass2& origin) :
    QObject(),
    m_name (origin.m_name),
    m_phoneNumber (origin.m_phoneNumber),
    m_addr (origin.m_addr)
{}

TestClass2& TestClass2::operator =(const TestClass2 &origin)
{
    m_name = origin.m_name;
    m_phoneNumber = origin.m_phoneNumber;
    m_addr = origin.m_addr;
    return *this;
}



string TestClass2::name(){return m_name;}
void TestClass2::setName(const string& name){m_name = name;return;}

QString TestClass2::qName(){return QString::fromStdString(m_name);}
void TestClass2::qSetName(const QString& name){m_name = name.toStdString();return;}

int TestClass2::phoneNumber() {return m_phoneNumber;}
void TestClass2::setPhoneNumber(const int  phoneNumber){m_phoneNumber = 7; return;}

Address TestClass2::getAddr() {return m_addr;}
void TestClass2::setAddr(const Address& addr){m_addr = addr; return;}


QVariantMap TestClass2::qGetAddr()
{
    return QJson::QObjectHelper::qobject2qvariant(&m_addr);
}
//void TestClass2::qSetAddr(const QVariantMap& addr){m_addr = addr; return;}

