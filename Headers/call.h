#ifndef CALL_H_INCLUDED
#define CALL_H_INCLUDED
#pragma once
#include <string>
#include <iostream>
#include "time.h"
#include "name.h"

class Call {
private:
    //Attributes
    Name name;
    Time startTime;
    Time endTime;
    std::string number;

public:
    //Builders
    Call();
    Call(const Call&);

    //Getters y Setters
    Name getName() const;
    Time getStartTime() const;
    Time getEndTime() const;
    std::string getNumber() const;

    //Methods
    void setName(const Name&);
    void setStartTime(const Time&);
    void setEndTime(const Time&);
    void setNumber(const std::string&);

    std::string toString() const;

    //Assignment and relational operators
    Call& operator = (const Call&);

    bool operator ==(const Call&) const;
    bool operator !=(const Call&) const;
    bool operator <(const Call&) const;
    bool operator <=(const Call&) const;
    bool operator >(const Call&) const;
    bool operator >=(const Call&) const;

    //Flow operators
    friend std::ostream& operator << (std::ostream&, const Call&);
    friend std::istream& operator >> (std::istream&, Call&);

};

#endif // CALL_H_INCLUDED
