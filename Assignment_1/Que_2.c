#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd = 0;
    char FileName[50] = {'\n'};
    char mode = {'\n'};
    int flags = 0;

    printf("Enter file name: ");
    scanf("%[^'\n']s", FileName);

    printf("Enter mode (R / W / E): ");
    scanf(" %c", &mode);

    //Converting the modes into flags
    switch (mode)
    {
        case 'R':
            flags = O_RDONLY;
            break;

        case 'W':
            flags = O_WRONLY | O_CREAT | O_TRUNC;
            break;

        case 'E':
            flags = O_WRONLY | O_APPEND | O_CREAT;
            break;

        default:
            printf("Invalid mode\n");
            return -1;
    }

    fd = open(FileName, flags, 0777);   

    if (fd == -1)
    {
        printf("Error opening file: %s\n", strerror(errno));
        return -1;
    }

    printf("File opened successfully with fd : %d\n", fd);

    close(fd);
    return 0;
}
