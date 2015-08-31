#include <ctime>
#include <iostream>
using namespace std;

int main() {
    char junk;
    //for(int i= 0; i<3; i++)
    {
    time_t t = time(0);   // get time now'
    int valueYear = t;
    int valueMonth = t;
    valueYear = (valueYear/31536000)+1970;
    valueMonth = (valueMonth/2628000)-540;
    cout<<valueMonth<<"-"<<valueYear<<endl;

    cout<<"time: "<<t<<endl;
    struct tm * now = localtime( & t );
    cout << now->tm_year<<endl
         << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday << "  "
         <<  now->tm_hour << ":"
         <<  now->tm_min
         << endl;
    cin>>junk;
    }
}
