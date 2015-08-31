#include<iostream>
#include<ctime>
//#include<cstdbool>
#include<string>
#include"osHeader.h"

using namespace std;

int main(void)
{
    string input = "";
    bool terminate = false;

    printStartUp();
    printfOSVersion();
    while(terminate != true)
    {
        cout<<">";
        input = ""; //clear input buffer
        cin>>input;

        switch(hashIt(input))
        {
            case quit:
                    if(exitSimulator() == true)
                    {
                        terminate = true;
                    }
                    else
                    {
                        terminate = false;
                    }
                    break;
            case version:
                    printfOSVersion();
                    break;
            case date:
                    getDate();
                    break;
            case help:
                    cout<<"This is a simulation of an Operating System.\n";
                    break;
            default:
                    cout<<"Bad command or filename\n";
                    break;

        }
    }
    return 0;
}
