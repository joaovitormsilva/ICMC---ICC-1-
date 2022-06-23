#include <stdio.h>

/*
Questão 2 da prova de ICC
Aluno: João Vitor Martins da Silva
nUSP: 13696641
*/
typedef struct{
    int x;
    int y;
}coordenadas;
coordenadas p1,p2;

int main(){
    scanf("%d %d",&p1.x,&p1.y);

    scanf("%d %d",&p2.x,&p2.y);
    int a = (p2.y - p1.y)/(p2.x-p1.x);
    int b = p2.y - a * p2.x;
    printf("y=%dx + %d\n",a,b);
    return 0;
}