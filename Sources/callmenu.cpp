#include "callmenu.h"
#include <iostream>
using namespace std;

void CallMenu::enterToContinue()
{
    cout << "Press Enter to continue...";
    getchar();
}

CallMenu::CallMenu(CallList* ptr) : callListRef(ptr)
{
    mainMenu();
}

void CallMenu::mainMenu()
{
    int opc;
    bool repetir = true;
    do{
        system("cls");
        system("color 8F");
		cout << "\t\t---------------------------------------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t      |              CALL MENU             |\n";
		cout << "\t\t\t\t   -----------------------------------------------------------\n";
		cout << "\t\t\t\t   |  1.- Add call              |  2.- Delete call           |\n";
		cout << "\t\t\t\t   -----------------------------------------------------------\n";
		cout << "\t\t\t\t   |  3.- Modify call           |  4.- View calls            |\n";
		cout << "\t\t\t\t   -----------------------------------------------------------\n";
		cout << "\t\t\t\t   |  5.- Delete all            |  6.- Exit                  |\n";
		cout << "\t\t\t\t   -----------------------------------------------------------\n";
		cout << "\t\t---------------------------------------------------------------------------------------------------\n";
		cout << "\n -Choose the option you wish to perform: ";

		cin >> opc;
		cin.ignore();

            switch(opc){
                case 1:
                    addCall();
                    cout << "\n-------------------------------------------------------------------------\n";
                    break;
                case 2:
                    deleteCall();
                    break;
                case 3:
                    modifyCallDuration();
                    break;
                case 4:
                    showCall();
                    break;
                case 5:
                    deleteAllCall();
                    break;
                case 6:
                    cout << "\n - Exiting Menu... -" << endl;
                    repetir = false;
                    break;
                default:
                    cout << "\n - Invalid option -\n";
                    enterToContinue();
                }
		}while(repetir);
}

void CallMenu::addCall()
{
    string str;
    CallNode* pos;
    Call llamada;
    Name nombre;
    Time tiempo;

    system("cls");
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "Enter the following data to add a call \n\n";

    cout << "\tStart time (HH:MM): ";
    getline(cin, str, ':');
    tiempo.setHour(stoi(str));
    getline(cin, str);
    tiempo.setMinute(stoi(str));
    llamada.setStartTime(tiempo);

    //Search if this name has already been entered
    pos = callListRef->findData(llamada);
    if(pos != nullptr){
        cout << "\nThis name has already been registered, no two can be alike\n";
        enterToContinue();
        return;
    }

    cout << "\tCall duration (HH:MM): ";
    getline(cin, str, ':');
    tiempo.setHour(stoi(str));
    getline(cin, str);
    tiempo.setMinute(stoi(str));
    llamada.setEndTime(tiempo);

    cout << "\tCustomer number: ";
    getline(cin, str);
    llamada.setNumber(str);

    cout << "\tCustomer name: ";
    getline(cin, str);
    nombre.setFirst(str);

    cout << "\tCustomer last name: ";
    getline(cin, str);
    nombre.setLast(str);

    llamada.setName(nombre);

    try{
        callListRef->insertOrdered(llamada);
    } catch (ListException ex){
        cout << "A problem occurred" << endl;
        cout << "The system found that: " << ex.what() << endl;
        cout << "If it is a recurring problem, please report it to the systems area.";
        enterToContinue();
        return;
    }
    cout << "\n- Call successfully registered -\n\n";
    enterToContinue();
    //cout << "\n-------------------------------------------------------------------------\n";
    //return;
}

void CallMenu::deleteCall()
{
    string str;
    Time tiempo;
    Call llamada;
    CallNode* pos;

    system("cls");
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "Delete call\n\n";
    cout << "\tStart time (HH:MM): ";
    getline(cin, str, ':');
    tiempo.setHour(stoi(str));
    getline(cin, str);
    tiempo.setMinute(stoi(str));
    llamada.setStartTime(tiempo);

    //Search if this name has already been entered
    pos = callListRef->findData(llamada);
    if(pos == nullptr){
        cout << "\nNo call registered at that time\n\n";
        enterToContinue();
        return;
    }

    cout << "\nCall found: \n";
    cout << callListRef->retrieve(pos).toString();


    callListRef->deleteData(pos);
    cout << "\n\n- Deleted call -\n\n";
    enterToContinue();
}

void CallMenu::deleteAllCall(){
    system("cls");
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "Eliminating calls...\n";
    cout << "\n\n- Deleted calls -\n\n";
    callListRef->deleteAll();
    enterToContinue();
}

void CallMenu::showCall()
{
    system("cls");
    cout << "\t\t-------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t      -                 Call list                -\n";
    cout << "\t\t-------------------------------------------------------------------------------------------\n";
    cout << "\t\t    Start time    |   Call duration  |              Name                |      Phone   \n";
    cout << callListRef->toString();
    cout << "\t\t-------------------------------------------------------------------------------------------\n";
    cout << endl << endl;
    enterToContinue();
}

void CallMenu::modifyCallDuration()
{
    string str;
    Call llamada;
    CallNode* pos;
    Time tiempo;

    system("cls");
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "Modify call duration\n\n";
    cout << "\tStart time (HH:MM): ";
    getline(cin, str, ':');
    tiempo.setHour(stoi(str));
    getline(cin, str);
    tiempo.setMinute(stoi(str));
    llamada.setStartTime(tiempo);

    //Search if this name has already been entered
    pos = callListRef->findData(llamada);
    if(pos == nullptr){
        cout << "\nThis customer was not registered\n";
        enterToContinue();
        return;
    }else{
        cout << "\nThe call... " << endl;
        cout << callListRef->retrieve(pos).toString();
        cout << "\n\nCall duration (HH:MM): ";
        getline(cin, str, ':');
        tiempo.setHour(stoi(str));
        getline(cin, str);
        tiempo.setMinute(stoi(str));
        pos->getData().setEndTime(tiempo);
    }

    callListRef->retrieve(pos).setEndTime(tiempo);


     cout << "\n";
     enterToContinue();
}



