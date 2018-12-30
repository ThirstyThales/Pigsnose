#ifndef ETHERNET_H_H
#define ETHERNET_H_H
#ifndef uchar
    typedef unsigned char uchar;
#endif

struct protocol_ethernet
{
    uchar dst[6];
    uchar src[6];
    uchar type[2];
};
#define ethernet_size (sizeof(struct protocol_ethernet))
#define is_ipv4(eth) (((struct protocol_ethernet*)eth)->type[0]==0x08&&((struct protocol_ethernet*)eth)->type[1]==0x00)
/* 
    以太网协议由6字节目标地址，6字节源地址，2字节类型构成
    类型为0x0800时，代表是Ipv4报文
*/

#endif