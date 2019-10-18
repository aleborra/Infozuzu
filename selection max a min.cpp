//selection sort dal max al min

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

void selection_sort(int *vet,int *n)       // sp dal maggioore al minore
{
	int i,j,posmax;
	
	for(i=0;i<(*n-1);i++) {
		posmax=i;
		for(j=(i+1);j<*n;j++) {
			if(vet[j]>vet[posmax])
				posmax=j;
		}
		scambia_int(&vet[i],&vet[posmax]);
	}
		
}

int main () {
	
	int len,numeri[MAX_VET];
	
	printf("Quanti numeri vuoi inserire?\n");
	scanf("%d",&len);
	
	carica_vet(numeri,&len);
	selection_sort(numeri,&len);
	stampa_vet(numeri,&len);
}
