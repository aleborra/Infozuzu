#include<stdio.h>
#include<string.h>

#define MAX_VET 100
#define MAX_STR 100

void scambia_float(float *ptra,float *ptrb) 
{
	
	float dep;
	dep=*ptra;
	*ptra=*ptrb;
	*ptrb=dep;
}

void scambia_str(char *str1,char *str2) 
{
	
	char dep[MAX_STR];
	
	strcpy(dep,str1);
	strcpy(str1,str2);
	strcpy(str2,dep);
}


void bubble_sort (char str[MAX_VET][MAX_STR],float prezzi[MAX_VET],int n) {
	
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
				scambia_float(&prezzi[j],&prezzi[j+1]);
				scambio=1;	
			}
		}
		i--;
	}
}


void stampa_str(char str[MAX_VET][MAX_STR],float prezzi[MAX_VET],int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("%s     %.2f euro\n", str[i],prezzi[i]);
	}
	
}


int cerca_str(char str[MAX_VET][MAX_STR], int *n,char togliere[MAX_VET])     //ricerca dicotomica
{
	int i,j,med,trovato;
	
	i=0;
	j=*n-1;     
	trovato=0;
	
	while(!trovato&&i<=j)
	{
		med=(i+j)/2;
		if(strcmp(str[med], togliere)==0)
			trovato=1;
		else
			if(strcmp(str[med], togliere)>0)    //elemento sta a sinistra
				j=med-1;	
			else
				i=med+1;
	}
	if(trovato)
		return med;
	else
		return -1;
}



void compare_str(char str[MAX_VET][MAX_STR], char controllare[MAX_STR],  int n)
{
	int i, cont = 0;
	
	for(i=0;i<n;i++)
	{
		if(strstr(str[i],controllare)!=NULL)
			cont++;
	}
	
	printf("Ci sono %d piatti simili \n", cont);
}



void shift_sx(char str[MAX_VET][MAX_STR], int *n, char togliere[MAX_STR])
{
	int i, tmp; 
	
	tmp=cerca_str(str, n, togliere);
	
	if(tmp==-1)
	{
		printf("\n\nparola non trovata\n\n");
	}
	else
	{	
		for(i=tmp;i<*n;i++)
		{
			strcpy(str[i],str[i+1]);
		}
	}
}


void carica_str(char str[MAX_VET][MAX_STR],float prezzi[MAX_VET],int n)                  //qui è aggiunto il prezzo
{
	int i;
	
	for(i=0;i<n;i++)
	{
		getchar();
		printf("Inserisci il piatto: \n");
		gets(str[i]);
		printf("\n");
		
		printf("Inserisci il prezzo del piatto:\n");
		scanf("%f",&prezzi[i]);
	}	
}


int main (){

	int n, i, cont;
	char str[MAX_VET][MAX_STR], togliere[MAX_STR], controllare[MAX_STR];
	float prezzi[MAX_VET];
	
	printf("Quanti piatti vuoi inserire \n");
	scanf("%d",&n);
	printf("\n");
	
	carica_str(str,prezzi,n);
	stampa_str(str,prezzi,n);
	
	bubble_sort(str,prezzi,n);
	
	stampa_str(str, n);	
	
	printf("\n");
	printf("Quale pietanza vuoi controllare? \n");
	scanf("%s", controllare);
	compare_str(str, controllare, n);
	
	getchar();
	printf("\n");
	printf("Quale piatto vuoi togliere:\n");
	gets(togliere);
	
	shift_sx(str, &n, togliere);
	n=n-1;
	
	printf("\n");
	stampa_str(str, n);
}
