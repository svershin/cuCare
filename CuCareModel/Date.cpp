// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Date.h - Declaration of base class Date
// Member functions are defined in Date.cpp

#include "Date.h"

// Constructor
Date::Date
(   int DayParam,
    int MonthParam,
    int YearParam)
    : day (DayParam),
      month (MonthParam),
      year (YearParam)
{
}

// Destructor
Date::~Date()
{
}

int Date::getDay() { return day; }
void Date::setDay(const int value) { day = value; }

int Date::getMonth() { return month; }
void Date::setMonth(const int value) { month = value; }

int Date::getYear() { return year; }
void Date::setYear(const int value) { year = value; }

// EOF
