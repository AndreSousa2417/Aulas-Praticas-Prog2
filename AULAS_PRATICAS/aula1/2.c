#include <stdio.h>
#include <string.h>


int main()
{
  int n,byte[1],numero[1];
  char tagR[3], tag[3]="TAG", titulo[30],artista[30],album[30],ano[4],comentario[30];


  FILE* f;

  f = fopen("musica.mp3", "rb");

  fseek(f,-128,SEEK_END);
  fread(tagR,sizeof(char),3,f);
  printf("%s\n",tagR);
  /*if(strcmp(tagR, tag)!=0)
  {
    printf("O ficheiro não apresenta qualquer informaçao sobre a musica.\n");
    return 0;
  }*/
  fseek(f,3,SEEK_CUR);
  fread(titulo,sizeof(char),30,f);
  fseek(f,30,SEEK_CUR);
  fread(artista,sizeof(char),30,f);
  fseek(f,30,SEEK_CUR);
  fread(album,sizeof(char),30,f);
  fseek(f,30,SEEK_CUR);
  fread(ano,sizeof(char),4,f);
  fseek(f,4,SEEK_CUR);
  fread(byte,sizeof(int),1,f);
  fseek(f,1,SEEK_CUR);
  if(byte[0]==1)
  {
    fread(comentario,sizeof(char),30,f);
    fseek(f,30,SEEK_CUR);
  }
  else
  {
    fread(comentario,sizeof(char),28,f);
    fseek(f,28,SEEK_CUR);
  }
  fread(numero,sizeof(int),1,f);

  fclose(f);

  printf("titulo: %s\nartista: %s\nalbum: %s\nano: %s\nnumero: %d\n",titulo,artista,album,ano,numero[0]);


}
