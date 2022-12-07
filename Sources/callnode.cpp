#include "callnode.h"
#include <iostream>
using namespace std;

CallNode::CallNode(): next(nullptr)
{

}

CallNode::CallNode(const Call& nd) : data(nd), next(nullptr)
{

}

Call& CallNode::getData()
{
    return data;
}

CallNode* CallNode::getNext()
{
   return next;
}

void CallNode::setData(const Call& nd)
{
    data = nd;
}

void CallNode::setNext(CallNode* pos)
{
    next = pos;
}

