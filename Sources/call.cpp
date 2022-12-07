#include "call.h"
#include <iostream>
using namespace std;

Call::Call()
{

}

Call::Call(const Call& call) : name(call.name), startTime(call.startTime), endTime(call.endTime), number(call.number)
{

}

Name Call::getName() const
{
    return name;
}

Time Call::getStartTime() const
{
    return startTime;
}

Time Call::getEndTime() const
{
    return endTime;
}

string Call::getNumber() const
{
    return number;
}

void Call::setName(const Name& n)
{
    name = n;
}

void Call::setStartTime(const Time& st)
{
    startTime = st;
}

void Call::setEndTime(const Time& et)
{
    endTime = et;
}

void Call::setNumber(const string& n)
{
    number = n;
}

string Call::toString() const
{
    string finalString;
    finalString += "\t\t\t";
    finalString += startTime.toString();
    finalString += " \t ";
    finalString += " | ";
    finalString += " \t ";
    finalString += endTime.toString();
    finalString += " \t    ";
    finalString += " |        ";
    finalString += name.toString();
    finalString += " \t ";
    finalString += " | ";
    finalString += " \t";
    finalString += number;
    finalString += "\t\t";
    return finalString;
}

Call& Call::operator=(const Call& call)
{
    name = call.name;
    startTime = call.startTime;
    endTime = call.endTime;
    number = call.number;
    return *this;
}

bool Call::operator==(const Call& call) const
{
    return startTime == call.startTime;
}

bool Call::operator!=(const Call& call) const
{
    return startTime != call.startTime;
}

bool Call::operator<(const Call& call) const
{
    return startTime < call.startTime;
}

bool Call::operator<=(const Call& call) const
{
    return startTime <= call.startTime;
}

bool Call::operator>(const Call& call) const
{
    return startTime > call.startTime;
}

bool Call::operator>=(const Call& call) const
{
    return startTime >= call.startTime;
}

ostream& operator << (ostream& os, const Call& call){
    os << call.name << endl;
    os << call.startTime << endl;
    os << call.endTime << endl;
    os << call.number;
    return os;
}

istream& operator >> (istream& is, Call& call){
    is >> call.name;
    is >> call.startTime;
    is >> call.endTime;
    getline(is, call.number);
    return is;
}


