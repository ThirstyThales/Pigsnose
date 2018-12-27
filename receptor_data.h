#ifdef RECEPTOR_DATA_H_H_
    #error "receptor_data.h can't be included twice."
#endif

#define RECEPTOR_DATA_H_H_

typedef struct Struct_SData
{
    struct Struct_SData* next;
    unsigned int len;
    unsigned char packet;
}SData;
SData* buildData(int len,const unsigned char *p)
{
    SData *d;
    d=(SData*)malloc(sizeof(SData)+len-1);
    if(d==NULL)return NULL;
    d->next=NULL;
    d->len=len;
    memcpy(&(d->packet),p,len);
    return d;
}
int appendList(SReceptor* r,SData* p)
{
    if(r->lastData==NULL)
    {
        r->lastData=p;
        r->firstData=p;
    }
    else
    {
        r->lastData->next=p;
        r->lastData=p;
    }
    r->sizeData++;
    return 0;
}