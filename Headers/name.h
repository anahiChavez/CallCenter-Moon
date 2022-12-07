#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED
#pragma once
#include <iostream>
#include <string>

class Name {
private:
    //Attributes
    std::string last;
    std::string first;

public:
    //Builders
    Name();
    Name(const Name&);
    Name(const std::string&, const std::string&);

    //Getters y Setters
    std::string getLast() const;
    std::string getFirst() const;
    void setLast(const std::string&);
    void setFirst(const std::string&);

    std::string toString() const;

    //Assignment and relational operators
    Name& operator = (const Name&);

    bool operator ==(const Name&) const;
    bool operator !=(const Name&) const;
    bool operator <(const Name&) const;
    bool operator <=(const Name&) const;
    bool operator >(const Name&) const;
    bool operator >=(const Name&) const;

    //Flow operators
    friend std::ostream& operator << (std::ostream&, const Name&);
    friend std::istream& operator >> (std::istream&, Name&);
};

#endif // NAME_H_INCLUDED
