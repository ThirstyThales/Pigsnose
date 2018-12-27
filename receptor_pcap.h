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
	printf("Jacked a packet with length of [%d]\n", header->len);
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