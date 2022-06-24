#include <stdio.h>
#include<stdlib.h>
/*
Questão 4 da prova de ICC
Aluno: João Vitor Martins da Silva
nUSP: 13696641
*/
int **escreverMatriz(int linhas,int colunas){
    int **Matriz=(int **)malloc(linhas*sizeof(int *));
    for(int i=0;i<linhas;i++)
        Matriz[i]=(int *)malloc(colunas*sizeof(int));
    return Matriz;
}
int **lerMatriz(int **Matriz,int linhas,int colunas){
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            Matriz[i][j]=-1;
        }
    }
    colunas-=2;
    linhas-=2;
    for(int i=1;i<=linhas;i++){
        for(int j=1;j<=colunas;j++){
            scanf("%d",&Matriz[i][j]);
        }
    }

    return Matriz;
}
int **marcarCaminho(int **Matriz,int x,int y, int k,int linhas,int colunas){
    if ((Matriz[x][y]== -1 ||Matriz[x][y]<k) && Matriz[x][y]!=0)
        return Matriz;

    Matriz[x][y]=k;
    marcarCaminho(Matriz,x+1,y,k+1,linhas,colunas);
    marcarCaminho(Matriz,x-1,y,k+1,linhas,colunas);
    marcarCaminho(Matriz,x,y+1,k+1,linhas,colunas);
    marcarCaminho(Matriz,x,y-1,k+1,linhas,colunas);
    return Matriz;
}
void imprimirCaminho(int **matriz,int linhas,int colunas,int x,int y,int k){
    if ((matriz[x][y]== -1 ||matriz[x][y]>k) && matriz[x][y]!=0)
        return;

    printf("%d ",matriz[x][y]);
    imprimirCaminho(matriz,linhas,colunas,x+1,y,k-1);
    imprimirCaminho(matriz,linhas,colunas,x-1,y,k-1);
    imprimirCaminho(matriz,linhas,colunas,x,y+1,k-1);
    imprimirCaminho(matriz,linhas,colunas,x,y-1,k-1);
}

int **passaMatriz(int **Matriz,int **MatrizReal,int linhas,int colunas){
    linhas-=2;
    colunas-=2;
    for(int i=1;i<=linhas;i++){
        for(int j=1;j<=colunas;j++){
        MatrizReal[i-1][j-1]=Matriz[i][j];
        }
    }
    return MatrizReal;
}
void liberarMatriz(int **Matriz,int linhas){
    for(int i=0;i<linhas;i++)
        free(Matriz[i]);
    free(Matriz);
}
int main (){
    int linhas,colunas;
    scanf("%d %d",&linhas,&colunas);
    //int **MatrizReal=escreverMatriz(linhas,colunas);
    linhas+=2;
    colunas+=2;
    int **Matriz=escreverMatriz(linhas,colunas);

    Matriz=lerMatriz(Matriz,linhas,colunas);
    int xb,yb,xa,ya;
    scanf("%d %d",&xa,&ya);
    scanf("%d %d",&xb,&yb);
    xa++;
    ya++;
    xb++;
    yb++;
    int k=1;
    Matriz=marcarCaminho(Matriz,xb,yb,k,linhas,colunas);
    int valor=Matriz[xa][ya];
    imprimirCaminho(Matriz,(linhas),(colunas),xa,ya,valor);
    printf("\n");
    liberarMatriz(Matriz,linhas);
    
    return 0;
}