#ifndef UI_H_H_
#define UI_H_H_

void OutputHelpMessage()
{
	printf("Pigsnose [h][s][l][d][p] [device name] [string]\n");
	printf("h: show help menu in detail\ns: show more tcp message\nl: show all devices and descriptions\nd: choose specific device to sniff\np: find the string we wish get\n"); 
}
void OutputPrompt()
{
    printf("command:");
}

#endif