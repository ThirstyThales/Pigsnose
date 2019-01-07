#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "receptor.h"

int main(int argc, char *argv[])
{
	showTCPIP=0;
	if(argc==2)
	{
		if(strstr(argv[1],"s")!=NULL)
			showTCPIP=1;
	}
	ReceptorSystemStartup();
	//sleep(60);
	//ReceptorSystemShotdown();
	return 0;
}