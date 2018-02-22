#include <stdio.h>
#include <stdlib.h>

void lerValores(int *v,unsigned int n);
int* criarMemoria(unsigned int n);
void imprimirValores(int *v, unsigned int n);
int* Impar(int *v, unsigned int n,unsigned int *ni);
int* Par(int *v, unsigned int n, unsigned int *np);

int main()
{
    int *v,*vp,*vi;
    unsigned int n,np,ni;

    printf("Numero de elementos?\n");
    scanf("%d",&n);
    v = criarMemoria(n);
    lerValores(v,n);
    printf("Vetor Original: [");
    imprimirValores(v,n);
    printf(" ]\n");


    vp = Par(v,n, &np);
    vi = Impar(v,n, &ni);
    printf("Impar: [");
    imprimirValores(vi,ni);
    printf(" ]\n");
    printf("Par: [");
    imprimirValores(vp,np);
    printf(" ]\n");
    

  

}


void lerValores(int *v, unsigned int n)
{
    for(int k=0;k<n;k++)
    {
        printf("Insira o %dº Numero.\n",k+1);
        scanf("%d", &v[k]);
    }
}

int* criarMemoria(unsigned int n)
{
     int *v;

    v = (int*)malloc(sizeof(int)*n);

    return v;
}

void imprimirValores(int *v, unsigned int n)
{

    for(int k=0;k<n;k++)
    {
        printf(" %d",v[k]);
    }
  
}

int* Impar(int *v, unsigned int n, unsigned int *ni)
{
   unsigned int i=0;
   int *vi,j=0,k=0;
   
    for(k=0;k<n;k++)
    {
        if(v[k]%2 !=0)
        {
            i++;
        }
    
    }
    k=0;
    vi = (int*)(malloc(sizeof(int)*i));
   
   for(k=0;k<n;k++)
    {
        if(v[k]%2 !=0)
        {
          vi[j]=v[k];
          j++;   
        }
    
    }

    *ni = i;
    return vi;
}

int* Par(int *v, unsigned int n, unsigned int *np)
{
   unsigned int p=0;
   int *vp,j=0,k=0;
   
    for(k=0;k<n;k++)
    {
        if(v[k]%2 == 0)
        {
            p++;   
        }
    
    }
    
    vp = (int*)(malloc(sizeof(int)*p));
    k=0;
    for(k=0;k<n;k++)
    {
        if(v[k]%2 ==0)
        {
            vp[j]=v[k];
            j++;
        }
    
    }
    *np = p;
    return vp;
}