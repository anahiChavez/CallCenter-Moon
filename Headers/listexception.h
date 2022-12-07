#ifndef LISTEXCEPTION_H_INCLUDED
#define LISTEXCEPTION_H_INCLUDED
#pragma once
#include<exception>
#include<string>

class ListException : public std::exception {
private:
    //Attribute
    std::string msg;

public:
    //Methods
    explicit ListException(const char* message) : msg(message){ }
    explicit ListException(const std::string& message) : msg(message) { }
    virtual ~ListException() throw () { }
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

#endif // LISTEXCEPTION_H_INCLUDED
