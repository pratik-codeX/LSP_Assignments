#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd = 0;
    char FileName[50] = {'\n'};
    
    printf("Enter File Name: \n");

    scanf("%s",FileName);

    fd = open(FileName,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file \n");
    }
    else
    {
        printf("The fd is %d\n",fd);
    }
    
    if(errno == 0)
    {
        printf("The File is %sfully Opened",strerror(errno));
    }

    if(errno != 0)
    {
        switch(errno)
        {
            case ENOENT :
                printf("There is no such file , create the file and open\n");
                break;
            
            case EACCES :
                printf("Unable to access as there is no permission\n");
                break;

            default:
                printf("%s",strerror(errno));
        }
    }

    return 0;
}