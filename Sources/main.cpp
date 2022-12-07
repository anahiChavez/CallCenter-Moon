//Made By: Magali Anahi Meza Chavez

/*
Uncommet if want to view just the CallMenu
#include "calllist.h"
#include "callmenu.h"
*/
#include"agentmenu.h"
#include <iostream>
using namespace std;

int main(){
    system("color CF");
    //new CallMenu(new CallList); Uncommet if want to view just the CallMenu
    new AgentMenu(new AgentList);
    return 0;
}

