#include "agent.h"
using namespace std;

Agent::Agent()
{

}

Agent::Agent(const Agent& agen) : specialty(agen.specialty), name(agen.name), shift(agen.shift), days(agen.days), empNum(agen.empNum), extenNum(agen.extenNum), extHours(agen.extHours), callList(agen.callList)
{

}

string Agent::getSpecialty() const
{
    return specialty;
}

Name Agent::getName() const
{
    return name;
}

string Agent::getShift() const
{
    return shift;
}

string Agent::getDays() const
{
    return days;
}

string Agent::getEmpNum() const
{
    return empNum;
}

string Agent::getExtenNum() const
{
    return extenNum;
}

Time Agent::getExtHours() const
{
    return extHours;
}

CallList& Agent::getCallList()
{
    return callList;
}

void Agent::setSpecialty(const string& sp)
{
    specialty = sp;
}

void Agent::setName(const Name& na)
{
    name = na;
}

void Agent::setShift(const string& sh)
{
    shift = sh;
}

void Agent::setDays(const string& da)
{
    days = da;
}

void Agent::setEmpNum(const string& emp)
{
    empNum = emp;
}

void Agent::setExtenNum(const string& exNum)
{
    extenNum = exNum;
}

void Agent::setExtHours(const Time& exHou)
{
    extHours = exHou;
}

void Agent::setCallList(const CallList& li )
{
    callList = li;
}

string Agent::toString(const bool& subList = false) const
{
    string finalResult;
    finalResult += "\t\t^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-\n";
    finalResult += "\t\t\t\t      -                  AGENT                   -\n";
    finalResult += "\t\t^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^\n";
    finalResult += "\t\t\t";
    finalResult += specialty;
    finalResult += " | ";
    finalResult += name.toString();
    finalResult += " | ";
    finalResult += empNum;
    finalResult += " | ";
    finalResult += extenNum;
    finalResult += " | ";
    finalResult += extHours.toString();
    finalResult += " hrs";
    finalResult += " | ";
    finalResult += shift;
    finalResult += " | ";
    finalResult += days;

    if(subList){
        finalResult += "\n";
        finalResult += "\t\t-------------------------------------------------------------------------------------------\n";
        finalResult += "\t\t\t\t      -               List of calls              -\n";
        finalResult += "\t\t-------------------------------------------------------------------------------------------\n";
        finalResult += "\t\t    Start time    |   Call duration  |               Name                 |      Phone   \n";
        finalResult += callList.toString();
        finalResult += "\t\t-------------------------------------------------------------------------------------------\n";
    }
    return finalResult;
}

Agent& Agent::operator=(const Agent& agen)
{
    specialty = agen.specialty;
    name = agen.name;
    shift = agen.shift;
    days = agen.days;
    empNum = agen.empNum;
    extenNum = agen.extenNum;
    extHours = agen.extHours;
    callList = agen.callList;
    return *this;
}

bool Agent::operator==(const Agent& agen) const
{
    return name == agen.name;
}

bool Agent::operator!=(const Agent& agen) const
{
    return name != agen.name;
}

bool Agent::operator<(const Agent& agen) const
{
    return name < agen.name;
}

bool Agent::operator<=(const Agent& agen) const
{
    return name <= agen.name;
}

bool Agent::operator>(const Agent& agen) const
{
    return name > agen.name;
}

bool Agent::operator>=(const Agent& agen) const
{
    return name >= agen.name;
}

ostream& operator << (ostream& os, const Agent& agen){
    os << agen.specialty << endl;
    os << agen.name << endl;
    os << agen.shift << endl;
    os << agen.days << endl;
    os << agen.empNum << endl;
    os << agen.extenNum << endl;
    os << agen.extHours;

    return os;
}

istream& operator >> (std::istream& is, Agent& agen){
    string str;
    getline(is, agen.specialty);
    is >> agen.name;
    getline(is, agen.shift);
    getline(is, agen.days);
    getline(is, agen.empNum);
    getline(is, agen.extenNum);
    is >> agen.extHours;
    return is;
}



