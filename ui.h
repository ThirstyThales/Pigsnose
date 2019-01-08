#ifndef UI_H_H_
#define UI_H_H_

void OutputHelpMessage()
{
	printf("Pigsnose [h][s][l][d][p] [device name] [string]\n");
	printf("h: show help menu\ns: show more tcp message\nl: show all devices\nd: set specified device to sniff\np: set searched string\n"); 
}
void OutputPrompt()
{
    printf("command:");
}

#endif