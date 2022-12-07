#ifndef AGENTLIST_H_INCLUDED
#define AGENTLIST_H_INCLUDED
#pragma once
#include <string>
#include <fstream>

#include "agentnode.h"
#include "agent.h"

class AgentList{
private:
    //Attributes
    AgentNode* header;

    bool isValidPos(AgentNode*);

    void copyAll(const AgentList&);
    void swapPtr(AgentNode*, AgentNode*);
    void sortByName(AgentNode*, AgentNode*);
    void sortBySpecialty(AgentNode*, AgentNode*);

public:
    //Builders
    AgentList();
    AgentList(const AgentList&);

    //Destroctor
    ~AgentList();

    //Methods
    bool isEmpty();
    void insertData(AgentNode*, const Agent&);
    void deleteData(AgentNode*);

    //Getters
    AgentNode* getFirstPos();
    AgentNode* getLastPos();
    AgentNode* getPrevPos(AgentNode*);
    AgentNode* getNextPos(AgentNode*);


    //Search
    AgentNode* findData(const Agent&);

    //Retrive
    Agent retrieve(AgentNode*);

    //Sort
    void sortByName();
    void sortBySpecialty();

    std::string toString(const bool&);

    void deleteAll();

    //Write and read
    void writeToDisk(const std::string&);
    void readFromDisk(const std::string&);

    //Method for assignment
    AgentList& operator = (const AgentList&);
};


#endif // AGENTLIST_H_INCLUDED
