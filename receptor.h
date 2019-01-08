#ifndef RECEPTOR_H_H_
#define RECEPTOR_H_H_
struct Struct_SData;
typedef struct
{
    char name[64];
    int isRunning;
    int sizeData;
    struct Struct_SData *firstData;
    struct Struct_SData *lastData;
}SReceptor;

int createReceptor(const char* name);
SReceptor* getReceptor(const char *name);

void ReceptorSystemStartup();
void ReceptorSystemShotdown();

int showTCPIP;
int showDev;
char* setDevName;
char* setSerachString;
#endif