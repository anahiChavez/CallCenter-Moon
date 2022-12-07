#include "calllist.h"
#include <iostream>
using namespace std;


CallList::CallList() : anchor(nullptr)
{

}

CallList::CallList(const CallList& lst) : CallList()
{
    copyAll(lst);
}

bool CallList::isValidPos(CallNode* pos)
{
    CallNode* temp(anchor);
    while(temp != nullptr){
        if(temp==pos){
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}

void CallList::copyAll(const CallList& lst)
{
   CallNode* temp(lst.anchor);
   CallNode* last(nullptr);
   CallNode* newNode;

   while(temp != nullptr){
        newNode = new CallNode(temp->getData());
        if(newNode == nullptr){
            throw ListException("Memory not available, copyAll");
        }
        if(last == nullptr){
            anchor = newNode;
        }
        else{
            last->setNext(newNode);
        }

        last = newNode;
        temp = temp->getNext();
   }
}

CallList::~CallList()
{
    deleteAll();
}

bool CallList::isEmpty()
{
    return anchor == nullptr;
}

void CallList::insertData(CallNode* pos, const Call& cll)
{
    if(pos!=nullptr && !isValidPos(pos)){
        throw ListException("Invalid position");
    }

    CallNode* temp(new CallNode(cll));

    if(temp==nullptr){
        throw ListException("Memory not available");
    }

    if(pos == nullptr){
        temp->setNext(anchor);

        anchor = temp;
    }
    else{
        temp->setNext(pos->getNext());
        pos->setNext(temp);
    }
}

void CallList::insertOrdered(const Call& cll)
{
    CallNode* temp(anchor);
    CallNode* pos(nullptr);
    while(temp != nullptr && cll > temp->getData()){
        pos = temp;
        temp = temp->getNext();
    }
    insertData(pos, cll);
}

CallNode* CallList::findData(const Call& cll)
{
    CallNode* temp(anchor);
    while(temp != nullptr && temp->getData() != cll){
        temp = temp->getNext();
    }
    return temp;
}
void CallList::deleteData(CallNode* pos)
{
    if(!isValidPos(pos)){
        throw ListException("Invalid position, deleteData");
    }

    if(pos == anchor){
        anchor = pos->getNext();
    }
    else{
        getPrevPos(pos)->setNext(pos->getNext());
    }
    delete pos;
}

CallNode* CallList::getFirstPos()
{
    return anchor;
}

CallNode* CallList::getLastPos()
{
    if(isEmpty()){
        return nullptr;
    }

    CallNode* temp(anchor);
    while(temp->getNext() != nullptr){
        temp = temp->getNext();
    }
    return temp;
}

CallNode* CallList::getPrevPos(CallNode* pos)
{
    if(pos == anchor || !isValidPos(pos)){
        return nullptr;
    }
    CallNode* temp(anchor);
    while(temp->getNext() != pos){
        temp = temp->getNext();
    }
    return temp;
}

CallNode* CallList::getNextPos(CallNode* pos)
{
    if(!isValidPos(pos)){
        return nullptr;
    }
    return pos->getNext();
}

Call& CallList::retrieve(CallNode* pos)
{
   if(!isValidPos(pos)){
        throw ListException("Invalid position, retrieve");
   }

   return pos->getData();
}

string CallList::toString() const
{
    CallNode* temp(anchor);
    string  listResult;

    while(temp!=nullptr){
        listResult += temp->getData().toString();
        listResult += "\n";

        temp = temp->getNext();
    }
    return listResult;
}

void CallList::deleteAll()
{
    CallNode* temp;
    while(anchor != nullptr){
        temp = anchor;
        anchor = anchor->getNext();
        delete temp;
    }
}

CallList& CallList::operator=(const CallList& lst)
{
   deleteAll();
   copyAll(lst);

   return *this;
}
void CallList::writeToDisk(const std::string& file)
{
    ofstream myFile;
    myFile.open(file, myFile.trunc);

    if(!myFile.is_open()){
        string msg;
        msg = "Error opening the file ";
        msg += file;
        msg += " while trying to write";

        throw ListException(msg);
    }

    CallNode* aux(anchor);
    while(aux != nullptr){
        myFile << aux->getData() << endl;
        aux = aux->getNext();
    }

    myFile.close();
}

void CallList::readFromDisk(const std::string& file)
{
    ifstream myFile;

    myFile.open(file);

    if(!myFile.is_open()){
        string msg;
        msg = "Error pening the file ";
        msg += file;
        msg += " while trying to read";

        throw(ListException(msg));
    }

    deleteAll();

    Call llamada;
    CallNode* last(nullptr);
    CallNode* newNode;

     while(myFile >> llamada){
        if((newNode = new CallNode(llamada)) == nullptr){
            myFile.close();
            throw ListException("Memory not available, readFromDisk");
        }

        if(last == nullptr){
            anchor = newNode;
        }
        else{
            last->setNext(newNode);
        }

        last = newNode;
     }
     myFile.close();
}


