#include <stdio.h>
#include <unistd.h>
#include "receptor.h"

int main(int argc, char *argv[])
{
	ReceptorSystemStartup();
	sleep(60);
	ReceptorSystemShotdown();
	return 0;
}