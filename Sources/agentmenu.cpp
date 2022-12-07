#include "agentmenu.h"
#include <iostream>
using namespace std;

void AgentMenu::enterToContinue()
{
    cout << "Press Enter to continue...";
    getchar();
}

void AgentMenu::mainMenu()
{
    int opc;
    bool repetir = true;
    system("cls");
    system("color CF");
    cout << "   __________________________________________________________________________________________________________________" << endl;
    cout << ".'  ________________________________________________________________________________________________________________  '." <<endl;
    cout << ": .'                                                                                                                '. :" << endl;
    cout << "||   __________  _________                           _________  ________   _________   _________  ________  ________  ||"<<endl;
    cout << "||  |           |         | |           |           |          |          |         |      |     |         |       |  ||"<<endl;
    cout << "||  |           |         | |           |           |          |          |         |      |     |         |       |  ||"<<endl;
    cout << "||  |           |         | |           |           |          |          |         |      |     |         |       |  ||"<<endl;
    cout << "||  |           |_________| |           |           |          |_______   |         |      |     |______   |_______|  ||"<<endl;
    cout << "||  |           |         | |           |           |          |          |         |      |     |         |      |   ||"<<endl;
    cout << "||  |           |         | |           |           |          |          |         |      |     |         |      |   ||"<<endl;
    cout << "||  |__________ |         | |_________  |________   |_________ |_________ |         |      |     |________ |      |   ||"<<endl;
    cout << "||                                                                                                                    ||" <<endl;
    cout << ":'.__________________________________________________________________________________________________________________.':" <<endl;
    cout << "'.____________________________________________________________________________________________________________________.'\n\n" <<endl;
    cout << "                                      _.._                                           " <<endl;
    cout << "                                    .' .-'`    _ __ ___   ___   ___  _ __       " <<endl;
    cout << "                                   F  F       |  _ ` _  |/ _ | / _ ||  _  |      " <<endl;
    cout << "                                  |  |        | | | | | | (_) | (_) | | | |     " <<endl;
    cout << "                                   L  L       |_| |_| |_||___/  ___/|_| |_|     " <<endl;
    cout << "                                    '._'-._                                     " <<endl;
    cout << "                                       ```                                      " <<endl;
    cout << "\n                                                   A system that fits you     " <<endl;
    cout << "\n\n\n ©2021 Anahi Chavez. All Rights Reserved." <<endl;
    cout << "  "; enterToContinue();
    do{
        system("cls");
        cout << "\t\t---------------------------------------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t      |              AGENT MENU            |\n";
		cout << "\t\t\t\t   -----------------------------------------------------------\n";
		cout << "\t\t\t\t   |  1.- Add agent             |  2.- Delete agent          |\n";
		cout << "\t\t\t\t   -----------------------------------------------------------\n";
		cout << "\t\t\t\t   |  3.- View agents           |  4.- Delete all            |\n";
		cout << "\t\t\t\t   -----------------------------------------------------------\n";
		cout << "\t\t\t\t   |  5.- Organize agent        |  6.- Search agent          |\n";
		cout << "\t\t\t\t   -----------------------------------------------------------\n";
        cout << "\t\t\t\t   |  7.- Write to disk         |  8.- Read from disk        |\n";
		cout << "\t\t\t\t   -----------------------------------------------------------\n";
		cout << "\t\t\t\t   |                         9.- Exit                        |\n";
		cout << "\t\t\t\t   -----------------------------------------------------------\n";
		cout << "\t\t---------------------------------------------------------------------------------------------------\n";
		cout << "\n -Choose the option you wish to perform: ";
		cin >> opc;
		cin.ignore();
		switch(opc){
            case 1:
                    addAgent();
                    break;
                case 2:
                    deleteAgent();
                    break;
                case 3:
                    showAgent();
                    break;
                case 4:
                    deleteAllAgent();
                    break;
                case 5:
                    sortAgent();
                    break;
                case 6:
                    findAgent();
                    break;
                case 7:
                    writeToDisk();
                    break;
                case 8:
                    readFromDisk();
                    break;
                case 9:
                    cout << "\n - ...Ending program... -" << endl;
                    system("cls");
                    cout << "\n\t\t\t\t\t\t      [END OF PROGRAM]\n";
                    cout << "\n\n\n ©2021 Anahi Chavez. All Rights Reserved." <<endl;
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    enterToContinue();
                    repetir = false;
                    break;
                default:
                    cout << "\n - Invalid option  -\n";
                    enterToContinue();
		}
    }while(repetir);
}

void AgentMenu::addAgent()
{
    string str;
    Agent agente;
    Name nombre;
    Time tiempo;
    AgentNode* pos;
    int dias;
    char sn;

    system("cls");
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "Enter the following data to add an agent \n\n";
    cout << "\tAgent name: ";
    getline(cin, str);
    nombre.setFirst(str);

    cout << "\tAgent last name: ";
    getline(cin, str);
    nombre.setLast(str);

    agente.setName(nombre);

    pos = agentListRef->findData(agente);
    if(pos != nullptr){
        cout << "\nThis agent has already been registered.\n";
        cout << " - Back to menu... -\n";
        enterToContinue();
        return;
    }

    cout << "\tAgent number: ";
    getline(cin, str);
    agente.setEmpNum(str);

    cout << "\tSpecialty: ";
    getline(cin, str);
    agente.setSpecialty(str);

    cout << "\tSchedule: ";
    getline(cin, str);
    agente.setShift(str);

    cout << "\tHow many days of work: ";
    cin >> dias;
    if(dias==5){
        agente.setDays("Mon-Fri");
    }else{
        agente.setDays("Sat-Sun");
    }
    cin.ignore();

    cout << "\tExtension number: ";
    getline(cin, str);
    agente.setExtenNum(str);

    cout << "\tOvertime (HH:MM): ";
    getline(cin, str, ':');
    tiempo.setHour(stoi(str));
    getline(cin, str);
    tiempo.setMinute(stoi(str));
    agente.setExtHours(tiempo);

    cout << endl << endl;
    do{
        cout << "\n\tDo you want to add calls to the agent? (Y/N): ";
        cin >> sn;
        cin.ignore();
        sn=toupper(sn);
    } while(sn != 'S' && sn != 'N');
    cout << endl << endl;
    if(sn == 'S'){
        new CallMenu(&agente.getCallList());
    } try{
        agentListRef->insertData(agentListRef->getLastPos(), agente);
    } catch(ListException ex){
        cout << "A problem occurred" << endl;
        cout << "The system found that: " << ex.what() << endl;
        cout << "If it is a recurring problem, please report it to the systems area";
        enterToContinue();
        return;
    }
    system("cls");
    system("color CF");
    cout << "\n-------------------------------------------------------------------------";
    cout << "\n- Agent successfully registered - \n\n";
    enterToContinue();
}

void AgentMenu::showAgent()
{
    char sn;
    system("cls");
    cout << "\n-------------------------------------------------------------------------";
    do{
        cout << "\n\tDo you want to visualize the agent with your calls? (Y/N): ";
        cin >> sn;
        cin.ignore();
        sn=toupper(sn);
    } while(sn != 'S' && sn != 'N');
    if(sn == 'S'){
        cout << agentListRef->toString(true);
    }else{
        cout << agentListRef->toString(false);
    }
    cout << endl << endl;
    enterToContinue();
}

void AgentMenu::deleteAgent()
{
    string str;
    Agent agente;
    Name nombre;
    AgentNode* pos;
    system("cls");
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "Enter the name of the agent to delete \n\n";
    cout << "\tAgent name: ";
    getline(cin, str);
    nombre.setFirst(str);

    cout << "\tAgent last name: ";
    getline(cin, str);
    nombre.setLast(str);

    agente.setName(nombre);

    pos = agentListRef->findData(agente);
    if(pos == nullptr){
        cout << "\nThis agent was not registered.\n";
        enterToContinue();
        return;
    }

    cout << "\n" << agentListRef->retrieve(pos).toString(true);

    agentListRef->deleteData(pos);
    cout << "\n\n- Agent eliminated -\n\n";
    enterToContinue();

}

void AgentMenu::deleteAllAgent()
{
    system("cls");
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "Eliminating agents...\n";
    cout << "\n\n- Agents eliminated -\n\n";
    agentListRef->deleteAll();
    enterToContinue();
}

void AgentMenu::findAgent()
{
    string str;
    Agent agente;
    Name nombre;
    AgentNode* pos;
    system("cls");
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "Enter the name of the agent you wish to search for \n\n";
    cout << "\tAgent name: ";
    getline(cin, str);
    nombre.setFirst(str);

    cout << "\tAgent last name: ";
    getline(cin, str);
    nombre.setLast(str);

    agente.setName(nombre);

    pos = agentListRef->findData(agente);
    if(pos == nullptr){
        cout << "\nThis agent was not registered.\n";
        enterToContinue();
        return;
    }

    cout << "\n" << agentListRef->retrieve(pos).toString(true);

    cout << "\n\n";
    enterToContinue();
}

void AgentMenu::sortAgent()
{
    int opc;
    system("cls");
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "Order agents \n\n";
    do{
        cout << "\tDo you want to sort by specialty or by name?";
        cout << "\n\t--------------------------------------------------" << endl;
        cout << "\t   1.-Specialty          | \t 2.-Name";
        cout << "\n\t--------------------------------------------------" << endl;
        cout << "\tEleccion: ";
        cin >> opc;
    } while(opc != 1 && opc != 2);
    cout << endl << endl;
    if(opc==1){
        agentListRef->sortBySpecialty();
    }else {
        agentListRef->sortByName();
    }
    cout << endl << endl;
}

void AgentMenu::writeToDisk()
{
    system("cls");
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "Writing to disk \n\n";

    try{
        agentListRef->writeToDisk("agents-list");
    }   catch(ListException ex){
        cout << "A problem occurred" << endl;
        cout << ex.what() << endl;

        enterToContinue();
        return;
    }

    cout << "\n- It was successfully written - \n\n";
    enterToContinue();
}

void AgentMenu::readFromDisk()
{
    system("cls");
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "Reading from disk... \n\n";

    try{
        agentListRef->readFromDisk("agents-list");
    }   catch(ListException ex){
        cout << "A problem occurred" << endl;
        cout << ex.what() << endl;

        enterToContinue();
        return;
    }

    cout << "\n- It was successfully read - \n\n";
    enterToContinue();
}

AgentMenu::AgentMenu(AgentList* ptr) : agentListRef(ptr)
{
    mainMenu();
}
