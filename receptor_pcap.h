#ifdef RECEPTOR_PCAP_H_H_
    #error "receptor_pcap.h can't be included twice."
#endif

#define RECEPTOR_PCAP_H_H_

typedef struct
{
    pcap_t *handle;	
    char *dev;
    bpf_u_int32 net;
    bpf_u_int32 mask;
}SPcapConfig;

void PacketRec(u_char *args, const struct pcap_pkthdr *header,const u_char *packet)
{
    struct protocol_ethernet* p_eth
        =(struct protocol_ethernet*)packet;
    struct protocol_ipv4* p_ipv4
        =(struct protocol_ipv4*)(packet+ethernet_size);
    //struct protocol_tcp 
	printf("[%05d] %d.%d.%d.%d -> %d.%d.%d.%d \n", header->len,
            p_ipv4->src[0],p_ipv4->src[1],p_ipv4->src[2],p_ipv4->src[3],
            p_ipv4->dst[0],p_ipv4->dst[1],p_ipv4->dst[2],p_ipv4->dst[3]);
    printf("       ");
    for(int i=0;i<20;i++)
    {
        printf("%02x ",*((byte*)p_ipv4+i));
    }
    printf("\n");
    for(int i=0;i<g_receptors_num;i++)
    if(g_receptors[i].isRunning)
    {
        appendList(&g_receptors[i],buildData(header->len,packet));
    }  
}
int openPcap(SPcapConfig *pcap)
{
    char errbuf[PCAP_ERRBUF_SIZE];
	pcap->dev = pcap_lookupdev(errbuf);//尝试打开默认网络设备
	if(pcap->dev == NULL)
    {
		fprintf(stderr, "Device Error: %s\n", errbuf);
		return -1;
	}
	if(pcap_lookupnet(pcap->dev, &(pcap->net), &(pcap->mask), errbuf) == -1)//获得设备的ip和掩码
    {
		fprintf(stderr, "%s can't get ip and mask: %s\n", pcap->dev, errbuf);
		pcap->net=0;
		pcap->mask=0;
	}

	pcap->handle = pcap_open_live(pcap->dev, BUFSIZ, 1, 1000, errbuf);
	if (pcap->handle == NULL) {
		fprintf(stderr, "%s handle Error: %s\n", pcap->dev, errbuf);
		return -1;
	}

	if(pcap_loop(pcap->handle,-1,PacketRec,NULL)!=0)
    {
        fprintf(stderr, "Enter loop failed.\n");
        return -1;
    }
	
	return 0;
}
int closePcap(SPcapConfig *pcap)
{
    pcap_close(pcap->handle);
    return 0;
}

SPcapConfig defualtPcap;
void PcapStartup()
{
    openPcap(&defualtPcap);
}
void PcapShotdown()
{
    closePcap(&defualtPcap);
}