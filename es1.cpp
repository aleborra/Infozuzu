#include<stdio.h>
#include<string.h>
#define MAX_VET 100
#define MAX_STR 100

char str[MAX_VET][MAX_STR];
char str2[MAX_VET][MAX_STR];
char *q;

void carica_str(char str[MAX_VET][MAX_STR],int n)
{
	int i;
	
	for(i=0;i<n;i++) {
		printf("Inserisci una lettera:\n");
		scanf("%s", str[i]);
	}
}

int cerca_e_sos(char str[MAX_VET][MAX_STR],int n,char str2[MAX_VET][MAX_STR],char *q)   
{
	int i,j;
	j=0;
	*q='*';
	
	for(i=0;i<n;i++)
        {
		for(j=0;j<n;j++)
		{	
			if(strcmp(str[j],str2[i])==0)
			{
				strcpy(str[j],q);
				printf("%s",str[j]);
				j++;
			}
			else
			{
				printf("%s",str[j]);
			}
                 }
	}
}

int main () {
	
	int n;
	
	printf("Inserire dimensioni stringa:\n");
	scanf("%d",&n);
	
	printf("PRIMA STRINGA\n");
	carica_str(str,n);
	
	printf("SECONDA STRINGA\n");
	carica_str(str2,n);
	
	cerca_e_sos(str,n,str2,q);
}
