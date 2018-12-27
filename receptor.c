#include <stdlib.h>
#include <string.h>
#include "receptor.h"
#include "receptor_data.h"
int g_receptors_num;
SReceptor* g_receptors;
#include <pcap.h>
#include "receptor_pcap.h"
const int Max_Receptor=64;
typedef int (*FunVisitReceptor)(SReceptor* rec);
int visitReceptor(FunVisitReceptor f)
{
    for(int i=0;i<g_receptors_num;i++)
    {
        if(f(&g_receptors[i])<0)
            return -1;
    }
    return 0;
}

void ReceptorSystemStartup()
{
    g_receptors_num=0;
    g_receptors=(SReceptor*)malloc(sizeof(SReceptor)*Max_Receptor);
    PcapStartup();
}
void ReceptorSystemShotdown()
{
    PcapShotdown();
}

int createReceptor(const char* name)
{
    if(g_receptors_num+1>Max_Receptor)
        return -1;
    SReceptor *rec=&g_receptors[g_receptors_num];
    g_receptors_num++;
    int namelen=strlen(name);
    if(namelen>60)
        return -1;
    memcpy(rec->name,name,namelen);
    rec->sizeData=0;
    rec->isRunning=0;
    rec->firstData = rec->lastData = NULL;
    return 0;
}
SReceptor* getReceptor(const char *rName)
{
    return NULL;
}

