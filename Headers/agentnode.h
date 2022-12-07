#ifndef AGENTNODE_H_INCLUDED
#define AGENTNODE_H_INCLUDED
#pragma once
#include <exception>
#include <string>

#include "agent.h"

class AgentNodeException : public std::exception{
private:
    //Attributes
    std::string msg;

public:
    //Methods
    explicit AgentNodeException(const char* message) : msg(message){ }
    explicit AgentNodeException(const std::string& message) : msg(message) { }
    virtual ~AgentNodeException() throw () { }
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

class AgentNode{
private:
    //Attributes
    Agent* dataPtr;
    AgentNode* prev;
    AgentNode* next;

public:
    //Builders
    AgentNode();
    AgentNode(const Agent&);

    //Destructor
    ~AgentNode();

    //Getters y Setters
    Agent* getDataPtr();
    Agent getData();
    AgentNode* getPrev();
    AgentNode* getNext();

    void setDataPtr(Agent*);
    void setData(const Agent&);
    void setPrev(AgentNode*);
    void setNext(AgentNode*);

};

#endif // AGENTNODE_H_INCLUDED
