#include <stdio.h>
#include<string.h>
#define MAX 100

int main () {
	
	char z[MAX];
	char *p;
	
	printf("Inserire una domanda:\n");
	gets(z);
	
	p=strstr(z,"zuzu");
  
  	if(p==NULL)
  		printf("\n\n\n\n\n\nZUZU.EXE HA SMESSO DI FUNZIONARE\n\n\n\n\n\n\n\n\n");
  	else
  		printf("\n\n\n\n\n\nFILE NOT FOUND (404)\n\n\n\n\n\n\n\n\n\n");
}
