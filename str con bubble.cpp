#include<stdio.h>
#include<string.h>
#define MAX_VET 100
#define MAX_STR 100

char str[MAX_VET][MAX_STR];

void carica_str(char str[MAX_VET][MAX_STR],int s)
{
	int i;
	
	for(i=0;i<s;i++) {
		printf("Inserisci una parola:\n");
		scanf("%s", str[i]);
	}	
}

void stampa_str(char str[MAX_VET][MAX_STR],int s)
{
	int i;
	
	for(i=0;i<s;i++) {
		
		printf("\n%s",str[i]);
	}
}

void scambia_str(char *str1,char *str2) 
{
	
	char dep[MAX_STR];
	
	strcpy(dep,str1);
	strcpy(str1,str2);
	strcpy(str2,dep);
}

void bubble_sort (char str[MAX_VET][MAX_STR],int s) {
	
	int i,j,scambio;
	
	i=s-1;
	scambio=1;
	
	while(scambio==1&&i>0)        //va anche solo (scambio&&i>0)
	{
		scambio=0;
		for(j=0;j<i;j++) 
		{
			if(strcmp(str[j],str[j+1])>0)
			{
				scambia_str(str[j],str[j+1]);
				scambio=1;	
			}
		}
		i--;
	}
}

	
int main () {
	int s;
	
	printf("Quante parole vuoi inserire?\n");
	scanf("%d",&s);
	
	carica_str(str,s);
	bubble_sort(str,s);
	stampa_str(str,s);
}

