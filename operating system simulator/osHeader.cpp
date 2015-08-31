#include<iostream>
#include<ctime>
//#include<cstdbool>
#include<string>
#include"osHeader.h"
using namespace std;
//enum command{quit, version, date, rreadMe};

//command hashIt (string const& input)
command hashIt (std::string const& input)
{
    if (input == "quit" || input == "Quit")
        {return quit;}
    if (input == "version")
        {return version;}
    if (input == "date")
        {return date;}
    if (input == "help")
        {return help;}

}

void printfOSVersion(void)
{
    cout<<"OS Version "<<OSVERSION<<endl;
    return;
}
void printStartUp(void)
{
    cout<<"Welcome to the DENIX operating system."<<endl;
    return;
}
bool exitSimulator()
{
    string answer = "";
    cout<<"Are you sure you wish to exit the simulator?"<<endl;
    cin>>answer;
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

    cout<<valueMonth<<"-"<<valueDay<<"-"<<valueYear<<endl;
    return; // (valueMonth+"-"+valueYear);
}
