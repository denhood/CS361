#include <iostream>
#include<stack>
using namespace std;

void printStack(stack<int> stackin)
{
    for(int i=0; i < stackin.size(); i++)
    {
        cout<<stackin(i)<<endl;
    }
    return;
}



int main()
{
    stack <int> first;
    stack <int> second;
    stack <int> third;

    for(int i =10; i>= 0; i--)
    {
        first.push(i);
    }


    return 0;
}
