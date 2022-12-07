#include "agentlist.h"
#include <iostream>
using namespace std;

bool AgentList::isValidPos(AgentNode* p)
{
    AgentNode* temp(header->getNext());

    while(temp != header){
        if(p == temp){
            return true;
        }

        temp = temp->getNext();
    }

    return false;
}

void AgentList::copyAll(const AgentList& lis)
{
    AgentNode* temp(lis.header->getNext());
    AgentNode* newNode;
    while(temp != nullptr){
        newNode = new AgentNode(temp->getData());

        if(newNode == nullptr){
            throw ListException("Memory not available copyAll");
        }

        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        temp = temp->getNext();
    }
}

void AgentList::swapPtr(AgentNode* ptr1, AgentNode* ptr2)
{
    if(ptr1 != ptr2){
        Agent* temp(ptr1->getDataPtr());
        ptr1->setDataPtr(ptr2->getDataPtr());
        ptr2->setDataPtr(temp);
    }
}

void AgentList::sortByName(AgentNode* leftE, AgentNode* rightE)
{
    if(leftE == rightE){
        return;
    }
    if(leftE->getNext() == rightE){
        if(leftE->getData().getName() > rightE->getData().getName()){
            swapPtr(leftE, rightE);
        }
    }

    AgentNode* i(leftE);
    AgentNode* j(rightE);

    while(i != j){
        while(i != j && i->getData().getName() <= rightE->getData().getName()){
            i = i->getNext();
        }

        while(i != j && j->getData().getName() >= rightE->getData().getName()){
            j = j->getPrev();
        }
        swapPtr(i,j);
    }
    swapPtr(i, rightE);
    if(i != leftE){
        sortByName(leftE, i->getPrev());
    }
    if(i != rightE){
        sortByName(i->getNext(), rightE);
    }
}

void AgentList::sortBySpecialty(AgentNode* leftE, AgentNode* rightE)
{
    if(leftE == rightE){
        return;
    }
    if(leftE->getNext() == rightE){
        if(leftE->getData().getSpecialty() > rightE->getData().getSpecialty()){
            swapPtr(leftE, rightE);
        }
    }

    AgentNode* i(leftE);
    AgentNode* j(rightE);

    while(i != j){
        while(i != j && i->getData().getSpecialty() <= rightE->getData().getSpecialty()){
            i = i->getNext();
        }

        while(i != j && j->getData().getSpecialty() >= rightE->getData().getSpecialty()){
            j = j->getPrev();
        }
        swapPtr(i,j);
    }
    swapPtr(i, rightE);
    if(i != leftE){
        sortBySpecialty(leftE, i->getPrev());
    }
    if(i != rightE){
        sortBySpecialty(i->getNext(), rightE);
    }
}

AgentList::AgentList() : header(new AgentNode)
{
    if(header == nullptr){
        throw ListException("Memory not available, initialize list");
    }
    header->setPrev(header);
    header->setNext(header);
}

AgentList::AgentList(const AgentList& lis) : AgentList()
{
    copyAll(lis);
}

AgentList::~AgentList()
{
    deleteAll();
    delete header;
}

bool AgentList::isEmpty()
{
    return header->getNext() == header;
}

void AgentList::insertData(AgentNode* p, const Agent& e)
{
    if(p != nullptr && !isValidPos(p)){
        throw ListException("Invalid position, insertData");
    }

    if(p == nullptr){
        p = header;
    }

    AgentNode* temp(new AgentNode(e));
    if(temp == nullptr){
        throw ListException("Memory not available, insertData");
    }

    temp->setPrev(p);
    temp->setNext(p->getNext());

    p->getNext()->setPrev(temp);
    p->setNext(temp);
}

void AgentList::deleteData(AgentNode* pos)
{
    if(!isValidPos(pos)){
        throw ListException("Invalid position, deleteData");
    }

    pos->getPrev()->setNext(pos->getNext());
    pos->getNext()->setPrev(pos->getPrev());

    delete pos;
}

AgentNode* AgentList::getFirstPos()
{
    if(isEmpty()){
        return nullptr;
    }
    return header->getNext();
}

AgentNode* AgentList::getLastPos()
{
    if(isEmpty()){
        return nullptr;
    }
    return header->getPrev();
}

AgentNode* AgentList::getPrevPos(AgentNode* pos)
{
    if(pos == header->getNext() || !isValidPos(pos)){
        return nullptr;
    }
    return pos->getPrev();
}

AgentNode* AgentList::getNextPos(AgentNode* pos)
{
    if(pos == header->getPrev() || !isValidPos(pos)){
        return nullptr;
    }
    return pos->getNext();
}
AgentNode* AgentList::findData(const Agent& agen)
{
    AgentNode* temp(header->getNext());
    while(temp != header){
        if(temp->getData() == agen){
        return temp;
        }
     temp = temp->getNext();
    }
    return nullptr;
}

Agent AgentList::retrieve(AgentNode* pos)
{
    if(!isValidPos(pos)){
        throw ListException("Invalid position, retrieve");
    }
    return pos->getData();
}

void AgentList::sortByName()
{
    sortByName(getFirstPos(), getLastPos());
    cout << "- Calls ordered by name - \n\n";
    system("pause");
}

void AgentList::sortBySpecialty()
{
    sortBySpecialty(getFirstPos(), getLastPos());
    cout << "- Calls ordered by specialty - \n\n";
    system("pause");
}

string AgentList::toString(const bool& withAgentList)
{
    AgentNode* temp(header->getNext());
    string finalstr;

    while(temp != header){
        finalstr += temp->getData().toString(withAgentList);
        finalstr += "\n";

        temp = temp->getNext();
    }

    return finalstr;
}

void AgentList::deleteAll()
{
    AgentNode* temp;
    while(header->getNext() != header){
        temp = header->getNext();
        header->setNext(temp->getNext());
        delete temp;
    }
    header->setPrev(header);
}

AgentList& AgentList::operator=(const AgentList& lis)
{
    deleteAll();
    copyAll(lis);
    return *this;
}

void AgentList::writeToDisk(const std::string& file)
{
    ofstream myFile;
    myFile.open(file, myFile.trunc);

    if(!myFile.is_open()){
        string msg;
        msg = "Error opening the file ";
        msg += file;
        msg += " when trying to write";

        throw ListException(msg);
    }

    AgentNode* aux(header->getNext());
    system("del *-calls");
    while(aux != header){
        myFile << aux->getData() << endl;

        try{
            aux->getData().getCallList().writeToDisk(aux->getData().getEmpNum() + "-calls");
        } catch(ListException ex){
            cout << ex.what() << endl;
        }
    aux = aux->getNext();
    }
   myFile.close();
}

void AgentList::readFromDisk(const std::string& file)
{
    ifstream myFile;
    myFile.open(file);

    if(!myFile.is_open()){
        string msg;
        msg = "Error opening the file ";
        msg += file;
        msg += " when trying to read";

        throw ListException(msg);
    }

    Agent agente;
    AgentNode* aux;

    deleteAll();

    while(myFile >> agente){
        try{
            agente.getCallList().readFromDisk(agente.getEmpNum() + "-calls");
        }   catch(ListException ex){
            cout << ex.what() << endl;
        }

        if((aux = new AgentNode(agente)) == nullptr){
            myFile.close();

            throw ListException("Memory not available, readFromDisk");
        }

        aux->setPrev(header->getPrev());
        aux->setNext(header);

        header->getPrev()->setNext(aux);
        header->setPrev(aux);
    }
    myFile.close();
}
