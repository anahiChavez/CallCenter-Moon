#include "time.h"
using namespace std;

bool Time::isValid(const int& hrs, const int& minu) const
{
    return hrs >= 0 and hrs < 24 && minu >= 0 and minu < 60;
}

int Time::toInt() const
{
   return hour * 100 + minute;
}

Time::Time()
{
    chrono::system_clock::time_point today = chrono::system_clock::now();
    time_t tt;
    tt = chrono::system_clock::to_time_t (today);
    struct tm* timeinfo;
    timeinfo = localtime(&tt);

    hour = timeinfo->tm_hour;
    minute = timeinfo->tm_min;
}

Time::Time(const Time& t) : hour(t.hour), minute(t.minute){ }

Time::Time(const int& hrs, const int& minu)
{
    if(isValid(hrs,minu)){
        hour = hrs;
        minute = minu;
    }
}

int Time::getHour() const
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}

void Time::setHour(const int& hrs)
{
    if(isValid(hrs, minute)){
        hour = hrs;
    }
}

void Time::setMinute(const int& minu)
{
    if(isValid(hour, minu)){
        minute = minu;
    }
}

string Time::toString() const
{
    char finalTime[6];
    sprintf(finalTime, "%02i:%02i", hour, minute);
    return finalTime;
}

Time& Time::operator=(const Time& t)
{
    hour = t.hour;
    minute = t.minute;
    return *this;
}

bool Time::operator==(const Time& t) const
{
    return toInt() == t.toInt();
}

bool Time::operator!=(const Time& t) const
{
    return toInt() != t.toInt();
}

bool Time::operator<(const Time& t) const
{
    return toInt() < t.toInt();
}

bool Time::operator<=(const Time& t) const
{
    return toInt() <= t.toInt();
}

bool Time::operator>(const Time& t) const
{
    return toInt() > t.toInt();
}

bool Time::operator>=(const Time& t) const
{
    return toInt() >= t.toInt();
}

ostream& operator << (std::ostream& os, const Time& t)
{
    os << t.toString();

    return os;
}
istream& operator >> (std::istream& is, Time& t)
{
    string anStr;

    getline(is, anStr, ':');
    t.hour = atoi(anStr.c_str());

    getline(is, anStr);
    t.minute = atoi(anStr.c_str());

    return is;
}


