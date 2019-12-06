#include<stdio.h>
#include<string.h>
#define MAX_VET 100
#define MAX_STR 100

void caricamento(char nome[MAX_VET][MAX_STR],char nation[MAX_VET][MAX_STR],int n,int tempo[MAX_VET],int numero[MAX_VET])
{
	int i;
    
	for(i=0;i<n;i++)
	{
		getchar();
		printf("Inserire il nome del concorrente:\n");
		gets(nome[i]);
		printf("Inserire la nazionalita' del concorrente:\n");
		gets(nation[i]);
		printf("Inserire il tempo di gara del concorrente:\n");
		scanf("%d",&tempo[i]);
		numero[i]=i+1;
	}
}

void scambia_int(int *ptra,int *ptrb) 
{
	int dep;
	
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

void stampa(char nome[MAX_VET][MAX_STR],char nation[MAX_VET][MAX_STR],int n,int tempo[MAX_VET],int numero[MAX_VET])
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("\n%s %s numero: %d tempo: %d\n",nome[i],nation[i],numero[i],tempo[i]);
	}
}

void ordinamento_tempo(char nome[MAX_VET][MAX_STR],char nation[MAX_VET][MAX_STR],int n,int tempo[MAX_VET],int numero[MAX_VET])
{
	int i,j,scambio;
	
	i=(n-1);
	scambio=1;
	
	while(scambio&&i>0)        
	{
		scambio=0;
		for(j=0;j<i;j++) 
		{
			if(tempo[j]>tempo[j+1])
			{
				scambia_str(nome[j],nome[j+1]);
				scambia_str(nation[j],nation[j+1]);
				scambia_int(&tempo[j],&tempo[j+1]);
				scambia_int(&numero[j],&numero[j+1]);
				scambio=1;	
			}
		}
		i--;
	}
}

int cerca(char nome[MAX_VET][MAX_STR],int n,char cc[MAX_STR])   
{
	int i,trovato;
	     
	trovato=0;
	
	for(i=0;i<n&&!trovato;i++)
	{
		if(strcmp(nome[i],cc)==0)
		trovato=1;
	}
	
	if(trovato)
		return i-1;
	else
		return -1;
}

void cancella_str(char nome[MAX_VET][MAX_STR],char nation[MAX_VET][MAX_STR],int ris,int *n,int tempo[MAX_VET],int numero[MAX_VET])
{
	int i;
	
	for(i=ris;i<*n-1;i++)
	{
		strcpy(nome[i],nome[i+1]);
		strcpy(nation[i],nation[i+1]);
		tempo[i]=tempo[i+1];
		numero[i]=numero[i+1];
	}
	(*n)--;
}

int main () {
	
	freopen("4G Vettori paralleli e algoritmi B-Ott-2019 inputB.txt","r",stdin);
	
	int n,numero[MAX_VET],tempo[MAX_VET],ris;
	char nome[MAX_VET][MAX_STR],nation[MAX_VET][MAX_STR],cc[MAX_STR];
	
	printf("Inserire numero dei concorrenti:\n");
	scanf("%d",&n);
	
	caricamento(nome,nation,n,tempo,numero);
	
	ordinamento_tempo(nome,nation,n,tempo,numero);
	printf("\nI concorenti ordinati in ordine di tempo sono:\n");
	stampa(nome,nation,n,tempo,numero);
	
	getchar();
	printf("\nQuale concorrente vuoi squalificare?\n");
	gets(cc);
	
	ris=cerca(nome,n,cc);
		
	if(ris!=-1)
	{
		printf("\nConcorrenti dopo l'eliminazione:\n");
		cancella_str(nome,nation,ris,&n,tempo,numero);
		stampa(nome,nation,n,tempo,numero);
	}
	else
		printf("Concorrente non trovato\n");
}
