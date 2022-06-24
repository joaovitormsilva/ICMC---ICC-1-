#include <stdio.h>
#include<stdlib.h>
/*
Questão 7 da prova de ICC
Aluno: João Vitor Martins da Silva
nUSP: 13696641
*/

int **ler_matriz(int linhas, int colunas);
int **subtrai_matrizes(int **mat1, int **mat2,int **mat3, int linhas, int colunas);
void imprimir_matriz(int **mat, int linhas, int colunas);
void liberar_matriz(int **mat, int linhas);

int main(void)
{
	int **matriz1,**matriz2;
	int linhas,colunas;

    scanf("%d %d",&linhas,&colunas);
    matriz1=ler_matriz(linhas,colunas);
    matriz2=ler_matriz(linhas,colunas);

    int **matriz3=(int **)malloc(linhas*sizeof(int*));
	for(int i=0;i<linhas;i++)
		matriz3[i]=(int *)malloc(colunas*sizeof(int));
        
    matriz3=subtrai_matrizes(matriz1,matriz2,matriz3,linhas,colunas);
    imprimir_matriz(matriz3,linhas,colunas);
    liberar_matriz(matriz3,linhas);
    liberar_matriz(matriz2,linhas);
    liberar_matriz(matriz1,linhas);
}


int **ler_matriz(int linhas, int colunas){
	int **matriz=(int **)malloc(linhas*sizeof(int*));

	for(int i=0;i<linhas;i++){
		matriz[i]=(int *)malloc(colunas*sizeof(int));
	}
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            scanf("%d",&matriz[i][j]);
        }
    }
	return matriz;
}

int **subtrai_matrizes(int **mat1, int **mat2,int **mat3, int linhas, int colunas){
 for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            mat3[i][j]=mat1[i][j] - mat2[i][j];
        }
    }
    return mat3;
}

void imprimir_matriz(int **mat, int linhas, int colunas){
  for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void liberar_matriz(int **mat, int linhas){
    for(int i=0;i<linhas;i++)
        free(mat[i]);
    free(mat);
}