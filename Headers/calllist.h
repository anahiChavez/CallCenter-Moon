#ifndef CALLTLIST_H_INCLUDED
#define CALLLIST_H_INCLUDED
#pragma once
#include <string>
#include <fstream>

#include "listexception.h"
#include "callnode.h"

#pragma once
class CallList{
private:
    //Attributes
    CallNode* anchor;

    bool isValidPos(CallNode*);
    void copyAll(const CallList&);

public:
    //Builders
    CallList();
    CallList(const CallList&);

    //Destructor
    ~CallList();

    //Methods
    bool isEmpty();
    void insertData(CallNode*, const Call&);
    void insertOrdered(const Call&);
    void deleteData(CallNode*);
    CallNode* findData(const Call&);

    //Getters
    CallNode* getFirstPos();
    CallNode* getLastPos();
    CallNode* getPrevPos(CallNode*);
    CallNode* getNextPos(CallNode*);

    //Retrive
    Call& retrieve(CallNode*);

    std::string toString() const;

    void deleteAll();

    //Write and read
    void writeToDisk(const std::string&);
    void readFromDisk(const std::string&);

    //Method for assignment
    CallList& operator = (const CallList&);
};
#endif // CALLLIST_H_INCLUDED
