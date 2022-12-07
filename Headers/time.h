#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <cstdio>
#include <cstdlib>

class Time {
private:
    //Attributes
    int hour;
    int minute;

    bool isValid(const int&, const int&) const;
    int toInt() const;

public:
    //Builders
    Time();
    Time(const Time&);
    Time(const int&, const int&);

    //Getters y Setters
    int getHour() const;
    int getMinute() const;

    void setHour(const int&);
    void setMinute(const int&);

    std::string toString() const;

    //Assignment and relational operators
    Time& operator = (const Time&);

    bool operator ==(const Time&) const;
    bool operator !=(const Time&) const;
    bool operator <(const Time&) const;
    bool operator <=(const Time&) const;
    bool operator >(const Time&) const;
    bool operator >=(const Time&) const;

    //Flow operators
    friend std::ostream& operator << (std::ostream&, const Time&);
    friend std::istream& operator >> (std::istream&, Time&);
};

#endif // TIME_H_INCLUDED
