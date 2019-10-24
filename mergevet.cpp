#include <stdio.h>
#define MAX_VET 100

void carica_vet(int A[],int B[],int n)
{
	int i,j;
	
	for(i=0;i<n;i++){
		printf("Inserire valore primo vettore:\n");
		scanf("%d",&A[i]);
	}
	
	for(j=0;j<n;j++)
	{
		printf("Inserire valore secondo vettore:\n");
		scanf("%d",&B[j]);	
	}
}

void stampa_vet(int *vet,int *n)
{
	int i;
	
	for(i=0;i<*n;i++) 
	{
		printf("%d, ",vet[i]);
	}
}

void scambia_int(int *ptra,int *ptrb) 
{
	
	int dep;
	dep=*ptra;
	*ptra=*ptrb;
	*ptrb=dep;
}

void bubble_sort (int *vet,int *n)
 {
	int i,j,scambio;
	
	i=(*n-1);
	scambio=1;
	
	while(scambio==1&&i>0)        //va anche solo scambio&&i>0
	{
		scambio=0;
		for(j=0;j<i;j++) 
		{
			if(vet[j]>vet[j+1])
			{
			 	scambia_int(&vet[j],&vet[j+1]);
				scambio=1;	
			}
		}
		i--;
	}
}

int main () {
	
	int A[MAX_VET],B[MAX_VET],C[2*MAX_VET],i,j,k,n,m;
	
	printf("Inserire dimensione dei vettori principali:\n");
	scanf("%d",&n);
	
	carica_vet(A,B,n);
	bubble_sort(A,&n);
	bubble_sort(B,&n);
	
	i=0;
	j=0;
	k=0;
	
	while(i<n||j<n)
	{
		if(A[i]<B[j])
		{
			C[k]=A[i];
			i++;
		}
		else
		{
			C[k]=B[j];
			j++;
		}
		printf("Valore nuovo vettore: %d,\n",C[k]);
		k++;
	}
}

