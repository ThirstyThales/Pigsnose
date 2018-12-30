#ifndef ETHERNET_H_H_
#define ETHERNET_H_H_
#ifndef byte_type
    #define byte_type
    typedef unsigned char byte;
    typedef unsigned short word;
#endif

struct protocol_ethernet
{
    byte dst[6];
    byte src[6];
    byte type[2];
};
#define ethernet_size (sizeof(struct protocol_ethernet))
#define is_ipv4(eth) (((struct protocol_ethernet*)eth)->type[0]==0x08&&((struct protocol_ethernet*)eth)->type[1]==0x00)
/* 
    以太网协议由6字节目标地址，6字节源地址，2字节类型构成
    类型为0x0800时，代表是Ipv4报文
*/

#endif