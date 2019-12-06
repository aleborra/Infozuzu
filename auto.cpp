#include<stdio.h>
#include<string.h>
#define MAX_VET 100
#define MAX_STR 100

void scambia_str(char *str1,char *str2) 
{
	char dep[MAX_STR];
	
	strcpy(dep,str1);
	strcpy(str1,str2);
	strcpy(str2,dep);
}

void stampa(char marca[MAX_VET][MAX_STR],char modello[MAX_VET][MAX_STR],char tipo[MAX_VET][MAX_STR],int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("%s  %s  %s\n",marca[i],modello[i],tipo[i]);
	}
}

void caricamento(char modello[MAX_VET][MAX_STR],char marca[MAX_VET][MAX_STR],char tipo[MAX_VET][MAX_STR],int n)
{
    int i;
    
    getchar();
	for(i=0;i<n;i++)
	{
		printf("Inserire la marca:\n");
		gets(marca[i]);
		printf("Inserire il modello:\n");
		gets(modello[i]);
		printf("Inserire il tipo:\n");
		gets(tipo[i]);
	}
}

void elenco(char modello[MAX_VET][MAX_STR],char marca[MAX_VET][MAX_STR],char tipo[MAX_VET][MAX_STR],int n,char cerca[MAX_STR])
{
	int i,trovato=0,j=0;
	
	printf("\nDi questa marca, %s, ci sono:\n",cerca);
	for(i=0;i<n;i++)
	{
		if(strcmp(marca[i],cerca)==0)
		{
			printf("\n%s %s\n",modello[i],tipo[i]);	
			trovato=1;
			j++;
		}
	}
	
	if(trovato)
		printf("\nCi sono %d %s\n",j,cerca);
	else
		printf("\n\nNessuna vettura della marca %s trovata\n",cerca);
}
		
void ordinamento(char modello[MAX_VET][MAX_STR],char marca[MAX_VET][MAX_STR],char tipo[MAX_VET][MAX_STR],int n) 
{	
	int i,j,scambio;
	
	i=(n-1);
	scambio=1;
	
	while(scambio&&i>0)        
	{
		scambio=0;
		for(j=0;j<i;j++) 
		{
			if(strcmp(modello[j],modello[j+1])>0)
			{
				scambia_str(modello[j],modello[j+1]);
				scambia_str(marca[j],marca[j+1]);
				scambia_str(tipo[j],tipo[j+1]);
				scambio=1;	
			}
		}
		i--;
	}
}
		 
void ordinamento_tipo(char ctipo[MAX_VET][MAX_STR],char cmodello[MAX_VET][MAX_STR],char cmarca[MAX_VET][MAX_STR],int n)
{
    int i,j,t;
	i=(n-1);
	t=1;
	
	while(t&&i>=0)
	{
		t=0;
		for(j=0;j<i;j++)
		{
			if(strcmp(ctipo[j],ctipo[j+1])>0)
			{
				scambia_str(ctipo[j],ctipo[j+1]);
				scambia_str(cmarca[j],cmarca[j+1]);
				scambia_str(cmodello[j],cmodello[j+1]);
				t=1;
			}
		}
		i--;
		
		if(t==0)
		 break;
	}
}
			
void ricerca(char modello[MAX_VET][MAX_STR],char marca[MAX_VET][MAX_STR],char tipo[MAX_VET][MAX_STR],int n,char cerca2[MAX_STR])
{
	int i,trovato,j;
	
	char ctipo[MAX_VET][MAX_STR],cmodello[MAX_VET][MAX_STR],cmarca[MAX_VET][MAX_STR];
	
	trovato=0; j=0;
	
	for(i=0;i<n;i++)
	{
		if(strcmp(modello[i],cerca2)==0)
		{
			strcpy(cmodello[j],modello[i]);
			strcpy(ctipo[j],tipo[i]);
			strcpy(cmarca[j],marca[i]);
			j++;
			trovato=1;
		}
	}
	
	if(trovato==0)
	{
		printf("\nNessuna vettura della modello %s trovata\n",cerca2);
	}
	if(trovato==1)
	{
		ordinamento_tipo(ctipo,cmodello,cmarca,n);
		
		printf("\nDel modello %s sono:\n",cerca2);
		stampa(cmarca,cmodello,ctipo,n);
	}
}

int main()
{
	freopen("4G Vettori paralleli e algoritmi A-Ott-2019 inputA.txt","r",stdin);
	
	int n;
	char modello[MAX_VET][MAX_STR],marca[MAX_VET][MAX_STR],tipo[MAX_VET][MAX_STR];
	char cerca[MAX_STR],cerca2[MAX_STR];
	
	printf("Inserire numero di auto:\n");
	scanf("%d",&n);
	
	caricamento(modello,marca,tipo,n);
	
	printf("\n\nInserire marca da ricercare:\n");
	gets(cerca);
	elenco(modello,marca,tipo,n,cerca);
	
	printf("\nVetture ordinate secondo il modello:\n");
	ordinamento(modello,marca,tipo,n);
	stampa(modello,marca,tipo,n);
	
	printf("\n\nInserire modello da ricercare:\n");
	gets(cerca2);
	
	ricerca(modello,marca,tipo,n,cerca2);
}
