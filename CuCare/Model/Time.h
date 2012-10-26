// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Time.h - Declaration of base class Time
// Member functions are defined in Time.cpp

#ifndef TIME_H
#define TIME_H

class Time
{
public:

    // Constructor
    Time (int hourParam,
          int minuteParam);

    // Destructor
    ~Time();

    int getHour();
    void setHour(const int value);

    int getMinute();
    void setMinute(const int value);

protected:
private:
    int hour;
    int minute;
};


#endif

// EOF
