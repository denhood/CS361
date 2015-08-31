//intake command strings
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
void clearInput(void)
{
    char c;
while((c = getchar()) != EOF)
    if (c == '\n')
        break;
}

int main()
{
    char input[10];
    bool exit = false;
    while(exit != true)
    {
        printf(">");
        //scanf("%c",&input);
        fgets(input, 10 ,stdin);
        switch(input)
        {
        case "quit":
            printf("are you sure you wish to quit?");
            clearInput();
            scanf("%c",&input);
            if(input == 'y')
            {
                printf("program exited");
                exit = true;
            }
            else if(input == 'n')
            {
                printf("program not exited\n");
            }
            else
            {
                printf("bad command\n");
            }
            break;
        default:
            printf("something happened");
            break;
            }

    }


    return 0;
}

