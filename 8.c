#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Questão 8 da prova de ICC
Aluno: João Vitor Martins da Silva
nUSP: 13696641
*/
int contaDigitos(int numero,int comparador){
    int vezes=0;
    int auxiliar;
    while(numero>0){
        auxiliar=numero%10;
        if(auxiliar == comparador){
            vezes++;
        }
        numero/=10;
    }
    return vezes;
}
int main(){
    int numero1,numero2;
    scanf("%ld %ld",&numero1,&numero2);
    int tamanhoDoNumero=1,tamanho=0,num1=numero1;

    while(tamanhoDoNumero>0){
        tamanhoDoNumero=num1%10;
        if(tamanhoDoNumero<=0){
            break;
        }
        tamanho++;
        num1/=10;
    }
    int vezes=0,i=0,comparador = 1, matrizNum1[tamanho][2], matrizNum2[tamanho][2];
    int num2=numero2;

    while(comparador>0){
        comparador=num2%10;
        if(comparador<=0)
            break;
        vezes=contaDigitos(numero1,comparador);
        matrizNum1[i][0]=comparador;
        matrizNum1[i][1]=vezes;
        i++;
        num2/=10;
    }
    num1=numero1;
    comparador=1;
    i =0;
    while(comparador>0){
        comparador=num1%10;
        if(comparador<=0)
            break;
        vezes=contaDigitos(numero2,comparador);
        matrizNum2[i][0]=comparador;
        matrizNum2[i][1]=vezes;
        i++;
        num1/=10;
    }
    int repeticao=0;
    int valor=0;   
    int permuta=0;   

    while(repeticao<tamanho){
        valor=matrizNum1[repeticao][0];       
        for(int i=0;i<tamanho;i++){       
            if(valor==matrizNum2[i][0]){
                if(matrizNum1[repeticao][1]==matrizNum2[i][1]){                    
                    permuta++;                      
                }
                else{
                    permuta-=1000;
                }
            }
        }
        repeticao++;
        }

    if(permuta >0){
        printf("eh permutacao\n");
    }
    else
        printf("nao eh permutacao\n");
}
