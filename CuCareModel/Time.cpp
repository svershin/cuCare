// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Time.h - Declaration of base class Time
// Member functions are defined in Time.cpp

#include "Time.h"

// Constructor
Time::Time
(   int hourParam,
    int minuteParam)
    : hour (hourParam),
      minute (minuteParam)
{
}

Time::Time(){}

// Destructor
Time::~Time()
{
}

int Time::getHour() { return hour; }
void Time::setHour(const int value) { hour = value; }

int Time::getMinute() { return minute; }
void Time::setMinute(const int value) { minute = value; }

// EOF
