#include<iostream>
#include<deque>
#include<string>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include"osHeader.h"

using namespace std;

int main(void)
{
    PCB* newProcess; // = new PCB;
    PCB* currProcess;
    PCBqueue systemQueues; //an object to contain our queues and their respective functions

    int userInput;
    std::string command, nameIn, rawData;
    std::stringstream lineIn;
    char classIn;
    int priorityIn, offset;
    bool continueinput = true;
    bool isGood = true;
    string input = "";
    bool terminate = false;

    printStartUp();
    printfOSVersion();
    while(terminate != true)
    {
        std::cout<<"\n>";
        std::getline(std::cin,command);
        userInput = parseString(command);
        switch(userInput)
        {
            case QUIT:
                    if(exitSimulator() == true)
                    {
                        terminate = true;
                    }
                    else
                    {
                        terminate = false;
                    }
                    break;
            case VERSION:
                    printfOSVersion();
                    break;
            case DATE:
                    getDate();
                    break;
            case HELP:
                    cout<<"This is a simulation of an Operating System.\n";
                    break;
            case CREATE:
                systemQueues.setupPCB();
                std::cin.ignore(); //ignore "\n" left in cin input buffer
                break;
            case DELETE:
                std::cout<<"enter name of process to erase: ";
                std::cin>>nameIn;
                systemQueues.erasePCB(nameIn);
                std::cin.ignore(); //ignore "\n" left in cin input buffer
                break;
            case BLOCK:
                systemQueues.block();
                std::cin.ignore(); //ignore "\n" left in cin input buffer
                break;
            case UNBLOCK:
                systemQueues.unblock();
                std::cin.ignore(); //ignore "\n" left in cin input buffer
                break;
            case SUSPEND:
                std::cout<<"sus"<<std::endl;
                break;
            case RESUME:
                std::cout<<"res"<<std::endl;
                break;
            case PRIORITY:
                systemQueues.setpriority();
                std::cin.ignore(); //ignore "\n" left in cin input buffer
                break;
            case SHOWPCB:
                systemQueues.PCBshow();
                std::cin.ignore(); //ignore "\n" left in cin input buffer
                break;
            case SHOWALL:
                systemQueues.showAll();
                break;
            case SHOWREADY:
                systemQueues.printReadyQueue();
                //std::cin.ignore();
                break;
            case SHOWBLOCKED:
                systemQueues.printBlockedQueue();
                break;
            case ERROR:
                std::cout<<"ERROR!";
                break;
            default:
                    cout<<"Bad command or filename\n";
                    break;

        }
    }std::cout<<"\nProgram terminated!\n";

    return 0;
}
