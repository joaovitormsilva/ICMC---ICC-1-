#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Questão 2 da prova de ICC
Aluno: João Vitor Martins da Silva
nUSP: 13696641
*/
int **criarMatriz(int linhas,int colunas){
    int **Matriz=(int **) malloc(linhas*sizeof(int *));
    for(int i=0;i<linhas;i++)
        Matriz[i]=(int *) malloc(colunas * sizeof(int));
    return Matriz;
}

int **preencheMatriz(int **matriz, int linhas,int colunas){
    srand(time(NULL));
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            matriz[i][j]=rand () % 1000;
        }
    }
    return matriz;
}

void limparMatriz(int **Matriz,int linhas){
    for(int i=0;i<linhas;i++)
        free(Matriz[i]);
    free(Matriz);
}

int main(){
    int n1,n2;
    scanf("%d %d", &n1, &n2);
    int **Matriz=criarMatriz(n1,n2);
    Matriz=preencheMatriz(Matriz,n1,n2);

    int menor=1000,maior=0,xmenor,ymenor;
    int xmaior,ymaior;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(Matriz[i][j]<menor){
                menor=Matriz[i][j];
                xmenor=i;
                ymenor=j;
            }
            if(Matriz[i][j]>maior){
                maior=Matriz[i][j];
                xmaior=i;
                ymaior=j;
            }
        }
    }
    printf("Menor eh: %d, seu X eh: %d, seu Y eh: %d\n",menor,xmenor,ymenor);
    printf("Maior eh: %d, seu X eh: %d, seu Y eh: %d\n",maior,xmaior,ymaior);

    limparMatriz(Matriz,n1);
    return 0;
}