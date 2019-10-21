#include <stdio.h>
#include<string.h>
#define MAX_VET 100
#define MAX_STR 100

char frase[MAX_VET][MAX_STR];

void separare_str(char frase,char *spa,int conta)
{
	int i,sp,j;
	
	i=0;
	
	while(i<conta)
	{
		sp=strstr(frase[i],*spa);
		j=sp;
		strcpy(frase[j],frase[j++]);
		i++;
	}
}

int main () { 
     
  int i,conta;

  printf("Inserisci una frase: \n");      
  gets(frase); 
  
  i=0;
  conta=0;     
      
  while(frase[i]!='\0')      
  {
     if(strcmp(frase[i],';')==0&&strcmp(frase[i-1],';')!=0) 
        conta++;        
     i++;      
  }   
   
  if (strcmp(frase[i-1],';')!=0)
      conta++; 

  printf("Nella frase ci sono %d parole",conta);
  
  const char *spa = " ";
  separare_str(frase,&spa,conta);
  printf("\n%s\n",frase);
}
