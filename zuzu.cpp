#include <stdio.h>
#include<string.h>
#include<unistd.h>
#define MAX 100

int main () {
	
	char z[MAX];
	char *p;
	int x,i;
	
	printf("\nInserire una domanda:\n");
	gets(z);
	
	p=strstr(z,"zuzu");
	
	printf("\nOgni quanto riprovare la ricerca?\n");
	scanf("%d",&x);
	
	for(i=0;i<1000;i++)
	{
		sleep(x);
		if(p==NULL)
  			printf("\n\n\n\n\n\nZUZU.EXE HA SMESSO DI FUNZIONARE\n\n\n\n\n\n\n");
  		else
  			printf("\n\n\n\nFILE NOT FOUND (404)\n\n\n\n\n\n\n\n");
	}
}
