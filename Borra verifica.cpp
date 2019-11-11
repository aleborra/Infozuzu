/*
maim e caricamento 18
conta 0
ordina 20
elimina non c'è
Totale 38
*/

#include<stdio.h>
#include<string.h>
#define MAX_VET 100
#define MAX_STR 100

  //char *el;			// no, dichiarato così non è un vettore

void carica_str(char piatto[MAX_VET][MAX_STR],int n)
{
	int i;
	
	getchar();
	
	for(i=0;i<n;i++) {
		printf("Inserisci una piatto:\n");
		//scanf("%s", str[i]);	
		gets(piatto[i]);		// gets
	}	
}

void scambia_str(char *str1,char *str2) 
{
	
	char dep[MAX_STR];
	
	strcpy(dep,str1);
	strcpy(str1,str2);
	strcpy(str2,dep);
}

void bubble_sort (char str[MAX_VET][MAX_STR],int n) {
	
	int i,j,scambio;
	
	i=n-1;
	scambio=1;
	
	while(scambio==1&&i>0)        
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

void stampa_str(char str[MAX_VET][MAX_STR],int n)
{
	int i;
	
	for(i=0;i<n;i++) {
		
		printf("\n%s",str[i]);
	}
}

void conta(char piatto[MAX_VET][MAX_STR],/*char *el,*/char el[MAX_STR], int n)
{
	int j,conta;
	
	conta=0;				// conta non inizializzato
	
	for(j=0;j<n;j++)
	{
		if(strstr(piatto[j],el)!=NULL)				// non è una strcmp la funzione da usare
			conta++;
	}
	printf("%s compare %d volte",el,conta);
}

void elimina(char piatto[MAX_VET][MAX_STR],char sost[MAX_STR])
{
	int i;
	
	for(i=pos;i<*n-1;i++)
	{
		strcpy(str[i],str[i+1]);
	}
	*n-1;
}

int main () {
 
  char piatto[MAX_VET][MAX_STR];	// corretto 
  char el[MAX_STR];                 //corretto
  char sost[MAX_STR];
     
  int j,n;
  
  printf("Quanti piatti vuoi inserire?\n");
  scanf("%d",&n);
  
  //carica_str(piatto,n);
  carica_str(piatto,n);		// se è globale non serve passarla come parametro
  
  printf("\nQuale parolola vuoi cercare:\n");
  scanf("%s",el);
  conta(piatto,el,n);				// manca richiamo a conta
  
  bubble_sort(piatto,n);
  stampa_str(piatto,n);
  
  getchar();
  printf("Inserire piatto da eliminare dal menù");
  gets(sost);
  elimina(piatto,n,sost);
}
