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

void merge(int *vet1,int *vet2,int *n)
{
	int i,j,k,C[2*MAX_VET];
	
	for(i=0,j=0,k=0;i<*n&&j<*n;i++,j++,k++)
		{
			if(vet1[i]!=vet2[j])
			{
				if(vet1[i]<vet2[j])
				{
					C[k]=vet1[i];
					j--;
				}
				else
				{
					C[k]=vet2[j];
					i--;
				}
				printf("Valore nuovo vettore: %d,\n",C[k]);	
			}
			else
			{
				C[k]=vet1[i];
				printf("Valore nuovo vettore: %d,\n",C[k]);
			}
		}
}

int main () {
	
	int A[MAX_VET],B[MAX_VET],n;
	
	printf("Inserire dimensione dei vettori principali:\n");
	scanf("%d",&n);
	
	carica_vet(A,B,n);
	bubble_sort(A,&n);
	bubble_sort(B,&n);
	merge(A,B,&n);
}
