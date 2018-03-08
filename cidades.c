/*****************************************************************/
/*         Trabalho pratico 1 | PROG2 | MIEEC | 2017/18          */
/*****************************************************************/
/*                    FUNCOES A IMPLEMENTAR                      */
/*****************************************************************/

#include "cidades.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vetor.h"

/**
 ordena o vetor de cidades por ordem crescente segundo a sua área:
 *parametro: vec apontador para o vetor de cidades
 *parametro: left posiçao inicial do vetor
 *parametro: right posiçao final do vetor 
 **/

void QuickSort_A(vetor *vec, int left, int right);

/**
 ordena o vetor de cidades por ordem crescente segundo o seu país:
 *parametro: vec apontador para o vetor de cidades
 *parametro: left posiçao inicial do vetor
 *parametro: right posiçao final do vetor 
 **/

void QuickSort_P(vetor *vec, int left, int right);



vetor* cidades_load(const char *nomef)
{
  //ficheiro.......................................

  FILE *f;
  cidade aux;
  f=fopen(nomef,"rb");
  int i=0;
  //.....................................................


  //vetor...................................................
  vetor* v=vetor_novo();



  while(fread(&aux.nome,sizeof(char)*MAXSTR,1,f)==1){
    i++;
    fread(&aux.pais,sizeof(char)*MAXSTR,1,f);
    fread(&aux.populacao,sizeof(int),1,f);
    fread(&aux.area,sizeof(int),1,f);


  int a=vetor_insere(v, aux, -1);
  if(a==-1){
    printf("Erro!");
    return NULL;
    break;
   
  }
    
  }            
  fclose(f);
  return v;
}

int cidades_save(const vetor *vec, const char *nomef)
{
   FILE *ff;
    ff=fopen(nomef,"wb");
    int i=vetor_tamanho(vec);
    cidade *a;
    if(i==0) {
      return -1;
    }
    int n=0;
    for(n=0; n<i;n++){
      
      a=vetor_elemento(vec,n);
      fwrite(a,sizeof(cidade),1,ff);
    }

  fclose(ff);

  return n;
}

int cidades_peek(const char *nomef, const char *nomecidade, cidade *resultado)
{
	FILE *f;
    f=fopen(nomef,"rb");
    cidade aux;
    fread(&aux,sizeof(cidade),1,f);
    int i=0;
    while(strcmp(aux.nome,nomecidade)!=0){
       i++;
      fread(&aux,sizeof(cidade),1,f);
     
    }
    *resultado=aux;
    fclose(f);
    if(strcmp(aux.nome,nomecidade)==0)
    return i;
    else return -1;
}

int cidades_poke(const char *nomef, const char *nomecidade, cidade nova)
{
  FILE *f;
  f=fopen(nomef,"rb+");
  cidade inutil;
  int i;
  i=cidades_peek(nomef,nomecidade,&inutil);
  fseek(f,i*sizeof(cidade),SEEK_SET);
  if(fwrite(&nova,sizeof(cidade),1,f)==1){
      fclose(f);
      return i;}
  else{
  return -1;
  fclose(f);}
}

int cidades_resort(vetor *vec, char criterio)
{
  int left= 0, right= (vec->tamanho)-1;

 if(criterio == 'p') 
 {
   QuickSort_P(vec , left, right);
   return 0;
 }
 
 if(criterio == 'a')
 {
   QuickSort_A(vec, left, right);
   return 0;
 }

  return -1;

}
  
  
  
  

char** cidades_similar (vetor *vec, const char *nomecidade, int deltapop, int *nsimilares)
{
  return NULL;
}


void QuickSort_A(vetor *vec, int left, int right)
{
   int i, j, tamanho = right-left+1;
  cidade aux;

  {
    if(tamanho < 2) return;

    else 
    {
      int pos = rand()%tamanho+left;
      aux = vec->elementos[pos];
      vec->elementos[pos] = vec->elementos[right];
      vec->elementos[right] = 
      aux;

      i = left; 
      j = right-1;

      while(1)
      {
        while (vec->elementos[i].area  <= vec->elementos[right].area && i<right)i++;
        while (vec->elementos[right].area <= vec->elementos[j].area && j >= 0) j--;

        if()
        if( i < j )
        {
          aux = vec->elementos[i]; 
          vec->elementos[i] = vec->elementos[j];
          vec->elementos[j] = aux;
        }

        else break;
      }

        aux = vec->elementos[i];
        vec->elementos[i] = vec->elementos[right];
        vec->elementos[right] = aux;

        QuickSort_A(vec, left, i-1);
        QuickSort_A(vec, i+1, right);
 
    }
  }
}

void QuickSort_P(vetor *vec, int left, int right)
{
   int i, j, tamanho = right-left+1;
  cidade aux;

  {
    if(tamanho < 2) return;

    else 
    {
      int pos = rand()%tamanho+left;
      aux = vec->elementos[pos];
      vec->elementos[pos] = vec->elementos[right];
      vec->elementos[right] = aux;

      i = left; 
      j = right-1;

      while(1)
      {
        while (strcmp(vec->elementos[i].pais,vec->elementos[right].pais)<=0 && i<right) i++;
        while (strcmp(vec->elementos[right].pais,vec->elementos[j].pais)<=0 && j >= 0) j--;

        if( i < j )
        {
          aux = vec->elementos[i]; 
          vec->elementos[i] = vec->elementos[j];
          vec->elementos[j] = aux;
        }

        else break;
      }

        aux = vec->elementos[i];
        vec->elementos[i] = vec->elementos[right];
        vec->elementos[right] = aux;

        QuickSort_P(vec, left, i-1);
        QuickSort_P(vec, i+1, right);
 
    }
  }
}