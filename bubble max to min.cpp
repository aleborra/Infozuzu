#include<stdio.h>
#define MAX_VET 100


void scambia_int(int *ptra,int *ptrb) 
{
	
	int dep;
	dep=*ptra;
	*ptra=*ptrb;
	*ptrb=dep;
}


void carica_vet(int *vet, int *n)
{
	int i;
	
	for(i=0;i<*n;i++) {
		printf("Inserisci un numero:\n");
		scanf("%d",&vet[i]);
	}	
}

void stampa_vet(int *vet,int *n)
{
	int i;
	
	for(i=0;i<*n;i++) {
		
		printf("\n%d",vet[i]);
	}
}

void bubble_sort (int *vet,int *n) {
	
	int i,j,scambio;
	i=(*n-1);
	scambio=1;
	
	while(scambio==1&&i>0)        //va anche solo scambio
	{
		scambio=0;
		for(j=0;j<i;j++) 
		{
			if(vet[j]<vet[j+1])
			{
			 	scambia_int(&vet[j],&vet[j+1]);
				scambio=1;	
			}
		}
		i--;
	}
}
	
	int main () {
		int vet[MAX_VET],n;
		printf("Inserire dimensione vettore:\n");
		scanf("%d",&n);
		
		carica_vet(vet,&n);
		bubble_sort(vet,&n);
		stampa_vet(vet,&n);
	}

