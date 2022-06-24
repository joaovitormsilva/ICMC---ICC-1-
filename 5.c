#include <stdio.h>
#include <stdlib.h>
/*
Questão 5 da prova de ICC
Aluno: João Vitor Martins da Silva
nUSP: 13696641
*/
int *escreveVetor(int tamanho){
    int *vetor=(int *)malloc(tamanho * sizeof(int));
    return vetor;
}

int *lerVetor(int *v, int n){
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    return v;
}
void maiorElemento(int *v,int n,int *maior){
    for(int i=0;i<n;i++){
        if(v[i]>*maior){
            *maior=v[i];
        }
    }
}
int main(){
    int tamanho;
    scanf("%d",&tamanho);
    int *vetor;
    vetor=escreveVetor(tamanho);
    vetor=lerVetor(vetor,tamanho);
    int maiorEle=0;
    int *maior=&maiorEle;
    maiorElemento(vetor,tamanho,maior);
    printf("O maior eh: %d\n",maiorEle);
    free(vetor);
    return 0;
}