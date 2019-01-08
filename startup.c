#include <stdio.h>
#include <string.h>
#include "receptor.h"
#include "ui.h"
int main(int argc, char *argv[])
{
	showTCPIP=0;
	showDev=0;
	setDevName=NULL;
	setSerachString="password";
	int arg=2;
	if(argc>=2)
	{
		if(strstr(argv[1],"h")!=NULL)
		{
			OutputHelpMessage();
			return 0;
		}
		if(strstr(argv[1],"s")!=NULL)
			showTCPIP=1;
		if(strstr(argv[1],"l")!=NULL)
			showDev=1;
		if(strstr(argv[1],"d")!=NULL)
		{
			if(argc<arg+1)
			{
				printf("error arg.\n");
				return -1;
			}
			setDevName=argv[arg];
			arg++;
		}
		if(strstr(argv[1],"p")!=NULL)
		{
			if(argc<arg+1)
			{
				printf("error arg.\n");
				return -1;
			}
			setSerachString=argv[arg];
			arg++;		
		}
	}
	ReceptorSystemStartup();
	//ReceptorSystemShotdown();
	return 0;
}