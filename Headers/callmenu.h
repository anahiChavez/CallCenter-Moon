#ifndef CALLMENU_H_INCLUDED
#define CALLMENU_H_INCLUDED
#pragma once
#include <iostream>
#include <string>

//Incluir las clases y listas
#include "calllist.h"
#include "callnode.h"
#include "call.h"
#include "time.h"
#include "name.h"

class CallMenu{
private:
    //Attributes
    CallList* callListRef; //List pointer

    //Methods
    void enterToContinue();
    void mainMenu();
    void addCall();
    void showCall();
    void modifyCallDuration();
    void deleteCall();
    void deleteAllCall();

public:
    //Builders
    CallMenu(CallList*); //There are no base constructs because it is necessary to have a reference
};


#endif // CALLMENU_H_INCLUDED
