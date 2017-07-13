/*************************************************************************
	> File Name: endian_conv.c
	> Author: 
	> Mail: 
	> Created Time: 2017年06月13日 星期二 10时06分32秒
 ************************************************************************/

#include<stdio.h>
#include<arpa/inet.h>

int main(int argc, char *argv[])
{
    unsigned short host_port=0x1234;
    unsigned short net_port;
    unsigned long host_addr=0x12345678;
    unsigned long net_addr;

    net_port=htons(host_port);
    net_addr=htonl(host_addr);
    printf("Host ordered port: %#x \n",host_port);
    printf("Network ordered port: %#x \n",net_port);
    printf("Host ordered address: %#lx \n",host_addr);
    printf("Network ordered address: %#lx \n",net_addr);
    return 0;
}









