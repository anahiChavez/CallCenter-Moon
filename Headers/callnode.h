#ifndef CALLNODE_H_INCLUDED
#define CALLNODE_H_INCLUDED
#pragma once
#include "call.h"

class CallNode {
private:
    //Attributes
    Call data;
    CallNode* next;

public:
    //Builders
    CallNode();
    CallNode(const Call&);

    //Getters y Setters
    Call& getData();
    CallNode* getNext();

    void setData(const Call&);
    void setNext(CallNode*);
};

#endif // CALLNODE_H_INCLUDED
