// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Date.h - Declaration of base class Date
// Member functions are defined in Date.cpp

#ifndef DATE_H
#define DATE_H

class Date : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int READ getDay WRITE setDay)
    Q_PROPERTY(int READ getMonth WRITE setMonth)
    Q_PROPERTY(int READ getYear WRITE setYear)

public:

    // Constructor
    Date (int DayParam,
          int MonthParam,
          int YearParam);

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

