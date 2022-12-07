#include "agentnode.h"

AgentNode::AgentNode() : dataPtr(nullptr), prev(nullptr), next(nullptr)
{

}

AgentNode::AgentNode(const Agent& e) : dataPtr(new Agent(e)), prev(nullptr), next(nullptr)
{
    if(dataPtr == nullptr){
        throw AgentNodeException("Memory not available, while creating CallNode");
    }
}

AgentNode::~AgentNode()
{
    delete dataPtr;
}

Agent AgentNode::getData()
{
    if(dataPtr == nullptr){
        throw AgentNodeException("The data does not exist, getData");
    }
    return *dataPtr;
}

Agent* AgentNode::getDataPtr()
{
    return dataPtr;
}

AgentNode* AgentNode::getPrev()
{
    return prev;
}

AgentNode* AgentNode::getNext()
{
    return next;
}

void AgentNode::setDataPtr(Agent* ptr)
{
    dataPtr = ptr;
}

void AgentNode::setData(const Agent& e)
{
    delete dataPtr;
    dataPtr = new Agent(e);
    if(dataPtr == nullptr){
        throw AgentNodeException("Memory not available, setData");
    }
}

void AgentNode::setPrev(AgentNode* ptr)
{
    prev = ptr;
}

void AgentNode::setNext(AgentNode* ptr)
{
    next = ptr;
}
