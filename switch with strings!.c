#include<stdio.h>
#include<string.h>

int main()
{
char *str = "foo";
switch(*str)
{
case 'f':
    //do something for foo
    cout<<"Foo";
    break;
case 'b':
    //do something for bar
    break;
case 'c':
    if(strcmp(str, "cat") == 0)
    {
        //do something for cat
    }
    else if(strcmp(str, "camel") == 0)
    {
        //do something for camel
    }
}
return 0;
}