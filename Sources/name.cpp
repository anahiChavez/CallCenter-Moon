#include "name.h"
#include <iostream>
using namespace std;

Name::Name()
{

}

Name::Name(const Name& nm) : last(nm.last), first(nm.first)
{

}

Name::Name(const std::string& lst, const std::string& fst)
{
    last = lst;
    first = fst;
}

string Name::getLast() const
{
   return last;
}

string Name::getFirst() const
{
    return first;
}

void Name::setLast(const std::string& lst)
{
    last = lst;
}

void Name::setFirst(const std::string& fst)
{
    first = fst;
}

string Name::toString() const
{
    return last + " " + first;
}

Name& Name::operator=(const Name& nm)
{
    last = nm.last;
    first = nm.first;
}

bool Name::operator==(const Name& nm) const
{
    return toString() == nm.toString();
}

bool Name::operator!=(const Name& nm) const
{
    return toString() != nm.toString();
}

bool Name::operator<(const Name& nm) const
{
    return toString() < nm.toString();
}

bool Name::operator<=(const Name& nm) const
{
    return toString() <= nm.toString();
}

bool Name::operator>(const Name& nm) const
{
    return toString() > nm.toString();
}

bool Name::operator>=(const Name& nm) const
{
    return toString() >= nm.toString();
}

ostream& operator << (ostream& os, const Name& nm){
    os << nm.toString();
    return os;
}

istream& operator >> (istream& is, Name& nm){
    getline(is, nm.last, ' ');
    getline(is, nm.first, ' ');
    getline(is, nm.first);
    return is;
}
