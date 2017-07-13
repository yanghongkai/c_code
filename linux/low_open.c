/*************************************************************************
	> File Name: low_open.c
	> Author: 
	> Mail: 
	> Created Time: 2017年06月12日 星期一 15时32分17秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

void error_handling(char* message);

int main(void)
{
    int fd;
    char buf[]="Let's go!\n";

    fd=open("data.txt", O_CREAT|O_WRONLY|O_TRUNC);
    if(fd==-1)
        error_handling("open() error!");
    printf("file descriptor:%d \n", fd);

    if(write(fd, buf, sizeof(buf))==-1)
        error_handling("write() error!");
    close(fd);

    return 0;
}

void error_handling(char* message)
{
    fputs(message,stderr);
    fputc('\n',stderr);
    exit(1);
}







