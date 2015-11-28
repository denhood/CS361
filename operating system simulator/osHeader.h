#ifndef OS_HEADER_H
#define OS_HEADER_H
#include<iostream>
#include<deque>
#include<string>
#include<sstream>
#include<cstdlib>
#define OSVERSION 2.0

//enum command{quit, version, date, help};
enum command{VERSION, DATE, HELP, CREATE, DELETE, BLOCK, UNBLOCK, SUSPEND, RESUME, PRIORITY, SHOWPCB,
             SHOWALL, SHOWREADY, SHOWBLOCKED, ERROR, QUIT};
enum state{RUNNING,READY,BLOCKED};

//command hashIt (string const& input);
//command hashIt (std::string const& input);
class PCB{
    private:
        std::string p_name;
        char p_class;
        int p_priority;
        state p_state;
        int p_memory;
    public:
        void allocatePCB(){
            p_name = "";
            p_class = ' ';
            p_priority = 0;
            p_state = READY;
            p_memory = 0;
            return;}
        void setupPCB(std::string name_in, int priority_in, char class_in){
            p_name = name_in;
            p_priority=priority_in;
            p_class = class_in;
            p_state = READY;
            return;}
        void printPCB()
        {
            std::cout<<p_name<<","<<p_class<<","<<p_priority;}
            std::string getname(){
            return p_name;}
        state getState(){
            return p_state;}
        void updatePriority(int new_priority){
            p_priority = new_priority;}
        void showAll(){
            std::cout<<"name: "<<p_name<<"\nclass: "<<p_class
                     <<"\npriority: "<<p_priority<<"\nstate: "
                     <<p_state<<"\nmemory: "<<p_memory;}
        void blockPCB(){p_state = BLOCKED;}
        void unblockPCB(){p_state = READY;}

};
class PCBqueue{
    public:
        std::deque<PCB*> PCB_ready_queue;
        std::deque<PCB*> PCB_blocked_queue;
        int number_of_nodes;
        void enqueuePCB(PCB* processIn){
            processIn = new PCB;
            if(processIn->getState() == READY){//state is ready
                PCB_ready_queue.push_back(processIn);}
            if(processIn->getState() == BLOCKED){//process is blocked
                PCB_blocked_queue.push_back(processIn);}

            number_of_nodes++;}
        void erasePCB(std::string nameIn){
            PCB* temp = new PCB;
            int location = 0;
            while(location < PCB_ready_queue.size()){
                temp = PCB_ready_queue.at(location);
                if(temp->getname() == nameIn){
                    PCB_ready_queue.erase(PCB_ready_queue.begin()+location);}
                else{location++;}}
            if(location == PCB_ready_queue.size()){//look in blocked queue
                location = 0;
                while(location < PCB_blocked_queue.size()){
                    temp = PCB_blocked_queue.at(location);
                    if(temp->getname() == nameIn){
                        PCB_blocked_queue.erase(PCB_blocked_queue.begin()+location);}
                    else{location++;}}}}

        PCB* findPCB(std::string processName){
            PCB* temp = new PCB;
            int location = 0;
            bool PCBfound = false;
            while(location < PCB_ready_queue.size()){
                temp = PCB_ready_queue.at(location);
                if(temp->getname() == processName){PCBfound = true; return temp;}
                else{location++;}}
            if(PCBfound == false){
                location = 0;
                while(location < PCB_blocked_queue.size()){
                    temp = PCB_blocked_queue.at(location);
                    if(temp->getname() == processName){PCBfound = true; return temp;}
                    else{location++;}}}
                return NULL;}
        int getReadyQueueSize(){
            return PCB_ready_queue.size();}
        PCB* getPCBReadyQueueAt(int location){
            PCB* tempNode;
            tempNode=PCB_ready_queue.at(location);
            return tempNode;}
        void setupPCB(){
            PCB* PCBin = new(PCB);
            std::string rawData = "";
            std::string nameIn = "";
            char classIn = ' ';
            int priorityIn = 0;
            //lineIn.str("");
            PCBin->allocatePCB();
            //prompt user for input
            std::cout<<"\tenter Process ID: ";
            //std::getline(std::cin, rawData);
            std::cin>>nameIn;
            std::cout<<"\tenter priority: ";
            std::cin.clear();
            std::cin>>priorityIn;
            std::cin.clear();
            //while(classIn != 'A' || classIn != 'S'){
            std::cout<<"\tenter class: ";
            std::cin>>classIn;
            //parse string
            PCBin->setupPCB(nameIn,priorityIn, classIn);
            PCB_ready_queue.push_back(PCBin);}
        void PCBshow(){
            std::string nameIn = "";
            PCB* currPCB = new(PCB);
            std::cout<<"\tenter name of PCB you wish to see:";
            std::cin>>nameIn;
            currPCB = findPCB(nameIn);
            if(currPCB != NULL){
                currPCB->showAll();}}
        void setpriority(){
            PCB* currPCB;
            std::string nameIn = "";
            int newpriority;
            std::cout<<"\tenter name of PCB you wish to modify:";
            std::cin>>nameIn;
            std::cout<<"\tenter new priority:";
            std::cin>>newpriority;
            currPCB = findPCB(nameIn);
            currPCB->updatePriority(newpriority);}
        void printReadyQueue(){
            PCB* currProcess = new(PCB);
            if(PCB_ready_queue.size()>0){
            for(int i =0; i< PCB_ready_queue.size(); i++)
            {
                currProcess = PCB_ready_queue.at(i);
                currProcess->printPCB();
                std::cout<<std::endl;}}}
        void printBlockedQueue(){
            PCB* currProcess = new(PCB);
            if(PCB_blocked_queue.size()>0){
            for(int i =0; i< PCB_blocked_queue.size(); i++)
            {
                currProcess = PCB_blocked_queue.at(i);
                currProcess->printPCB();
                std::cout<<std::endl;}}}
        void showAll(){
            PCB* currProcess = new(PCB);
            if(PCB_ready_queue.size()>0){
                std::cout<<"ready queue:\n";
                for(int i =0; i< PCB_ready_queue.size(); i++){
                    currProcess = PCB_ready_queue.at(i);
                    currProcess->printPCB();
                    std::cout<<std::endl;}}
            if(PCB_blocked_queue.size()>0){
                std::cout<<"blocked queue:\n";
                for(int i= 0; i< PCB_blocked_queue.size(); i++){
                    currProcess = PCB_blocked_queue.at(i);
                    currProcess->printPCB();
                    std::cout<<std::endl;}}}
        void block(){
            PCB* currProcess = new(PCB);
            std::string pName;
            std::cout<<"enter name of process to block:";
            std::cin>>pName;
            currProcess = findPCB(pName);
            if(currProcess!=NULL){
                erasePCB(pName);
                currProcess->blockPCB();//change PCB state to blocked
                PCB_blocked_queue.push_back(currProcess); // NOTE: need to remove PCB from readyQ
                }
             else{
                std::cout<<"PCB not found!";}}
        void unblock(){
            PCB* currProcess = new(PCB);
            std::string pName;
            std::cout<<"enter name of process to unblock:";
            std::cin>>pName;
            currProcess = findPCB(pName);
            if(currProcess!=NULL){
                erasePCB(pName);
                currProcess->unblockPCB();//change PCB state to blocked
                PCB_ready_queue.push_back(currProcess); // NOTE: need to remove PCB from readyQ
                }
            else{
                std::cout<<"PCB not found!";}}
};
command parseString(std::string input);
void printfOSVersion(void);
void printStartUp(void);
bool exitSimulator();
void getDate(void);


#endif
