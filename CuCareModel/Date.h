// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Date.h - Declaration of base class Date
// Member functions are defined in Date.cpp

#ifndef DATE_H
#define DATE_H

#include <QObject>

class Date : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int day READ getDay WRITE setDay)
    Q_PROPERTY(int month READ getMonth WRITE setMonth)
    Q_PROPERTY(int year READ getYear WRITE setYear)

public:

    // Constructor
    Date (int DayParam,
          int MonthParam,
          int YearParam);

    //Blank constructor
    Date();

    //Copy Constructor
    Date(const Address& origin);

    //Assignment operator
    Date& operator=(const Consultation& origin);


    // Destructor
    ~Date();

    int getDay();
    void setDay(const int value);

    int getMonth();
    void setMonth(const int value);

    int getYear();
    void setYear(const int value);

protected:
private:
    int day;
    int month;
    int year;
};

#endif

// EOF

