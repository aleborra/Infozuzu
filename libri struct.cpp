#include<stdio.h>
#include<string.h>
#define MAX_VET 100
#define MAX_STR 100

typedef struct
{
	char cod[MAX_STR];
	char tit[MAX_STR];
	char aut[MAX_STR];
	char ca_ed[MAX_STR];
	int p[MAX_VET];
}book;

typedef struct
{
	char au[MAX_STR];
	int nlibri[MAX_VET];
}autore;

void caricamento(book libro[MAX_STR],int n)
{
	int i;
    
    getchar();
	for(i=0;i<n;i++)
	{
		printf("Inserire il codice del libro:\n");
		gets(libro[i].cod);
		printf("Inserire il titolo del libro:\n");
		gets(libro[i].tit);
		printf("Inserire l'autore del libro:\n");
		gets(libro[i].aut);
		printf("Inserire la casa editrice del libro:\n");
		gets(libro[i].ca_ed);
		printf("Inserire prezzo del libro:\n");
		scanf("%d",&libro[i].p);
	}
}

int one_aut(book libro[MAX_STR],char A[MAX_STR],int n)
{
	int i,cont=0;
	
	for(i=0;i<n;i++)
	{
		if(strcmp(libro[i].aut,A)==0)
		{
			cont++;
		}
	}
	
	printf("\nIl numero di libri pubblicati dall'autore %s sono %d\n",A,cont);
	
	return cont;
}

void scambia_str(book *str1,book *str2) 
{
	
	book dep;
	
	dep=*str1;
	*str1=*str2;
	*str2=dep;
}

void ordinamento_libri(book libro[MAX_STR],int n)
{
	int i,j,scambio;
	
	i=(n-1);
	scambio=1;
	
	while(scambio&&i>0)        
	{
		scambio=0;
		for(j=0;j<i;j++) 
		{
			if(libro[j].p<libro[j+1].p)
			{
				scambia_str(&libro[j],&libro[j+1]);
				scambio=1;	
			}
		}
		i--;
	}
}

void stampa(book libro[MAX_STR],int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("\n%s  %s  %s  %s  %d\n",libro[i].cod,libro[i].tit,libro[i].aut,libro[i].ca_ed,libro[i].p);
	}
}

int main () {
	
	int n,pos=0,max=0,posmax=0,i,k=0,j;
	book libro[MAX_STR];
	char A[MAX_STR];
	autore autor[MAX_STR];
	
	printf("Inserire numero di libri:\n");
	scanf("%d",&n);
	
	caricamento(libro,n);
	
	printf("Inserire autore da cercare:\n");
	gets(A);
	
	one_aut(libro,A,n);
	
	ordinamento_libri(libro,n);
	
	for(j=0;j<n;j++)
	{
		strcpy(autor[j].au,libro[j].aut);
	}
	
	for(i=0;i<n;i++)
	{
		pos=one_aut(libro,autor[i].au,k);
		if(pos==-1)
		{
			strcpy(autor[k].au,libro[i].aut);
			autor[k].nlibri=1;
			k++;
		}
		else
			autor[pos].nlibri++;
	}
	max=autor[0].nlibri;
	
	for(i=1;i<k;i++)
	{
		if(autor[i].nlibri>max)
		{
			max=autor[i].nlibri;
			posmax=i;
		}
	}
	printf("\nL'autore che ha scritto piu libri e': %s\n",autor[posmax].au);
}
