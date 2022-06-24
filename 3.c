#include <stdio.h>

/*
Questão 3 da prova de ICC
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
    if(p2.x-p1.x == 0){
       int a = (p2.y - p1.y);
       printf("x=%d\n",a);
       return 0;
    }
    else if(p2.y-p1.y == 0){
        int a = (p2.y - p1.y)/(p2.x-p1.x);
        int b = p2.y - a * p2.x;
        printf("y=0x + %d\n",b);
        return 0;
    }
    int a = (p2.y - p1.y)/(p2.x-p1.x);
    int b = p2.y - a * p2.x;
    printf("y=%dx + %d\n",a,b);
    return 0;
}