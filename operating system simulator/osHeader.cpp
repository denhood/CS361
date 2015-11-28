#include<iostream>
#include<deque>
#include<string>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include"osHeader.h"

//enum command{quit, version, date, rreadMe};

//command hashIt (string const& input)
command parseString(std::string input){
    if(input == "version"){return VERSION;}
    if(input == "date"){return DATE;}
    if(input == "help"){return HELP;}
    if(input == "createPCB"){return CREATE;}
    if(input == "deletePCB"){return DELETE;}
    if(input == "block"){return BLOCK;}
    if(input == "unblock"){return UNBLOCK;}
    if(input == "suspend"){return SUSPEND;}
    if(input == "resume"){return RESUME;}
    if(input == "set priority"){return PRIORITY;}
    if(input == "show PCB"){return SHOWPCB;}
    if(input == "show all"){return SHOWALL;}
    if(input == "show ready"){return SHOWREADY;}
    if(input == "show blocked"){return SHOWBLOCKED;}
    if(input == "quit"){return QUIT;}
    //else{return ERROR;}
    }

void printfOSVersion(void)
{
    std::cout<<"OS Version "<<OSVERSION<<std::endl;
    return;
}
void printStartUp(void)
{
    std::cout<<"Welcome to the DENIX operating system."<<std::endl;
    return;
}
bool exitSimulator()
{
    std::string answer = "";
    std::cout<<"Are you sure you wish to exit the simulator?"<<std::endl;
    std::cin>>answer;
    if(answer == "Yes" || answer == "Y" || answer == "yes" || answer == "y")
    {
        return true;
    }
    else
    {
        return false;
    }
}
void getDate(void)
{
    time_t t = time(0);   // get time now'
    int valueYear = t;
    int valueMonth = t;
    int valueDay = t;
    valueYear = (valueYear/31536000)+1970;
    valueMonth = (valueMonth/2628000)-540;
    //valueDay = (valueDay/)

    std::cout<<valueMonth<<"-"<<valueDay<<"-"<<valueYear<<std::endl;
    return; // (valueMonth+"-"+valueYear);
}
