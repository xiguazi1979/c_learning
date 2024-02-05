#include <arpa/inet.h>
#include "stdio.h"
#include "string.h"
typedef unsigned char  		U8;
typedef unsigned short 		U16;
typedef unsigned int  		U32;
typedef union Ipv6AddrT
{
    U8  Addr8[16];
    U16 Addr16[8];
    U32 Addr32[4];
} Ipv6AddrT;

unsigned char v6addr1[16] = {65,0,1,32,17,0,3,0,0,0,0,0,203,0,0,0};
unsigned char v6addr2[16] = {65,0,1,32,17,0,3,0,0,0,0,0,34,0,16,0};
int main(void)
{
    unsigned int o;
    Ipv6AddrT *addr1, *addr2;
    addr1 = (Ipv6AddrT *)v6addr1;
    addr2 = (Ipv6AddrT *)v6addr2;
    printf("dump ip1\n");
    for(int i = 0; i < 16; i++) {
        printf("%d ", v6addr1[i]);
    }
    printf("\n");
    printf("dump ip2\n");
    for(int i = 0; i < 16; i++) {
        printf("%d ", v6addr2[i]);
    }
    printf("\n");
    printf("no convert:\n");
    for(o = 0; o < 4; o++)
    {
        printf("%d: %X - %X\n",\
            o, addr1->Addr32[o], addr2->Addr32[o]);
    }
    printf("\n");
    printf("convert htonl:\n");
    for(o = 0; o < 4; o++)
    {
        printf("%d: %X - %X\n",\
            o, htonl(addr1->Addr32[o]), htonl(addr2->Addr32[o]));
    }
    return 0;
}
