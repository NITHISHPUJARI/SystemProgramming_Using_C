#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char buff[15];
    bool pass = false;

    printf("\r\nEnter the password :\r\n");
    fgets(buff,15,stdin);

    if(strcmp(buff, "MySafePassword"))
    {
        printf ("Wrong Password \r\n");
    }
    else
    {
        printf ("Correct Password\r\n");
        pass = true;
    }

    if(pass)
    {
       /* Now Give root or admin rights to user*/
        printf ("Root privileges given to the user\r\n");
    }

    return 0;
}
