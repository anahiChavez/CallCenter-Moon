#ifndef AGENTMENU_H_INCLUDED
#define AGENTMENU_H_INCLUDED
#pragma once
#include "agentlist.h"
#include "agent.h"
#include "name.h"
#include "name.h"
#include "calllist.h"
#include "callmenu.h"

class AgentMenu{
private:
    //Atributo
    AgentList* agentListRef;

    //Metodos
    void enterToContinue();
    void mainMenu();
    void showAgent();
    void addAgent();
    void deleteAgent();
    void deleteAllAgent();
    //void modifyAgent();
    void findAgent();
    void sortAgent();

    void writeToDisk();
    void readFromDisk();

public:
    //Constructor
    AgentMenu(AgentList*);
};


#endif // AGENTMENU_H_INCLUDED
