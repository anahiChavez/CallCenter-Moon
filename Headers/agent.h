#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED
#pragma once
#include <iostream>
#include <string>

#include "calllist.h"
#include "name.h"
#include "time.h"

class Agent {
private:
    //Attributes
    std::string specialty;
    Name name;
    std::string shift;
    std::string days;
    std::string empNum;
    std::string extenNum;
    Time extHours ;
    CallList callList;

public:
    //Builders
    Agent();
    Agent(const Agent&);

    //Getters y Setters
    std::string getSpecialty() const;
    Name getName() const;
    std::string getShift() const;
    std::string getDays() const;
    std::string getEmpNum() const;
    std::string getExtenNum() const;
    Time getExtHours() const ;
    CallList& getCallList();

    void setSpecialty(const std::string&);
    void setName(const Name&);
    void setShift(const std::string&);
    void setDays(const std::string&);
    void setEmpNum(const std::string&);
    void setExtenNum(const std::string&);
    void setExtHours(const Time&);
    void setCallList(const CallList&);

    std::string toString(const bool&) const;

    //Assignment and relational operators
    Agent& operator = (const Agent&);

    bool operator ==(const Agent&) const;
    bool operator !=(const Agent&) const;
    bool operator <(const Agent&) const;
    bool operator <=(const Agent&) const;
    bool operator >(const Agent&) const;
    bool operator >=(const Agent&) const;

    //Flow operators
    friend std::ostream& operator << (std::ostream&, const Agent&);
    friend std::istream& operator >> (std::istream&, Agent&);

};

#endif // AGENT_H_INCLUDED
