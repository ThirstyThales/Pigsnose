#ifndef IPV4_H_H_
#define IPV4_H_H_
#ifndef byte_type
    #define byte_type
    typedef unsigned char byte;
    typedef unsigned short word;
#endif

struct protocol_ipv4
{
    byte vhl;  //vesrion和header length
    byte tos;
    word len;
    word id;
    word flagoffset;
    byte ttl;
    byte protocol;
    word sum;
    byte src[4];
    byte dst[4];  
};
#define ipv4_header_size(ip) ((ip->vhl&0x0f)*4)
/*
    IPv4 通常大小都是20字节 由header length * 4 获得
    有可能有选项字段在这20字节后
*/
#endif