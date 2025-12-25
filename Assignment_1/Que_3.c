/*
 Header file: 
    #include <unistd.h>

 Funcation Prototype:
    int access(const char *path, int mode);

 return value:
    On success (all requested permissions granted, or mode is F_OK and
    the file exists), zero is returned.
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    char filename[50];
    char mode;
    int result;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter mode (R / W / X): ");
    scanf(" %c", &mode);

    switch (mode)
    {
        case 'R':
            result = access(filename, R_OK);
            break;

        case 'W':
            result = access(filename, W_OK);
            break;

        case 'X':
            result = access(filename, X_OK);
            break;

        default:
            printf("Invalid mode\n");
            return -1;
    }

    if (result == 0)
    {
        printf("Accessible\n");
    }
    else
    {
        printf("Not accessible : %s\n", strerror(errno));
    }

    return 0;
}
