#include <stdio.h>
#include <stdlib.h>
/*
Questão 6 da prova de ICC
Aluno: João Vitor Martins da Silva
nUSP: 13696641
*/
int *ordena(int *vetorA,int *vetorB){
    int *vetorC;
    vetorC=(int *)malloc(2000*sizeof(int));
    int suporte;
    for(int i=0;i<1000;i++)
        vetorC[i]=vetorA[i];
    for(int i=1000;i<2000;i++)
        vetorC[i]=vetorB[i-1000];
    for(int i=0;i<2000;i++){
        for (int j=i;j<2000;j++){
            if(vetorC[j]<vetorC[i]){
                suporte=vetorC[j];
                vetorC[j]=vetorC[i];
                vetorC[i]=suporte;
            }
        }
    }
    return vetorC;
}
int main (){
    int vetorA[1000],vetorB[1000],*vetorC;

    vetorC=(int *)malloc(2000*sizeof(int));
    for(int i=0;i<1000;i++)
        scanf("%d",&vetorA[i]);
    for(int i=0;i<1000;i++)
        scanf("%d",&vetorB[i]);
    vetorC=ordena(vetorA,vetorB);

    for(int i=0;i<2000;i++)
        printf("%d ",vetorC[i]);
    printf("\n");
    free(vetorC);
    return 0;
}