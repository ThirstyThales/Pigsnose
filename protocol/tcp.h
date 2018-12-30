#ifndef TCP_H_H_
#define TCP_H_H_
#ifndef byte_type
    #define byte_type
    typedef unsigned char byte;
    typedef unsigned short word;
    typedef unsigned int dword;
#endif

struct protocol_tcp
{
    word srcport;
    word dstport;
    dword seq;
    dword ack;
    byte hl4r;//header length and 4 reserve bit
    byte flags;
    word win;
    word sum;
    word urp;
};
#define tcp_header_size(tcp) ((tcp->hl4r&0xf0)*4)

#endif
