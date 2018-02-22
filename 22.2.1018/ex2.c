#include <stdio.h>
#include "vetor.h"
#define STRINGS 5

int main()
{
    vetor *n;
    int p, a,b,c,d=STRINGS;
    char string[100];

    n= vetor_novo();
    
  
  for(int i=0;i<d;i++)
  {
      printf("Insira a string nº %d\n",i+1);
      fgets(string,100,stdin);
      p = vetor_insere(n,string,i);
  }

    

    printf("Escreva uma string.\n");
    fgets(string,100,stdin);

    a=vetor_pesquisa(n,string);
    if(a!=-1)
    {
        b=vetor_remove(n,a);
        d-=1;
    } 
    
   


    c=vetor_ordena(n);

 for(int k=0;k<d;k++)
    {
        printf("%s",n->elementos[k].str);
    }
}