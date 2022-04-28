#include <stdio.h>

int main(){
    int m[4][4]= {{1,1,1,0},{0,1,1,0},{1,0,1,1},{0,0,1,1}}; 
    int k,saiEstrada = 0, entraEstrada=0;

    scanf("%d",&k); 
    for(int i=0;i<4;i++){
        if(k != i){
            if(m[k][i] == 1) 
                saiEstrada++;
            if(m[i][k] == 1) 
                entraEstrada++; 

            if(m[k][i] == m[i][k] && m[k][i] == 1)
               printf("entre a cidade %d e a cidade %d existe mão dupla\n",k,i);
            else{
                printf("entre a cidade %d e a cidade %d existe NAO mão dupla\n",k,i);
            }
        }
    }

    int entraEstradaB0 =0,entraEstradaB1 =0,entraEstradaB2 =0,entraEstradaB3 =0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i !=j){
                switch(i){
                    case 0:
                        if(m[j][i] == 1){
                            entraEstradaB0++;
                        }
                            break;
                    case 1:
                        if(m[j][i] == 1){
                            entraEstradaB1++;
                        }
                            break;
                    case 2:
                        if(m[j][i] == 1){
                            entraEstradaB2++;
                        }
                            break;
                    case 3:
                        if(m[j][i] == 1){
                            entraEstradaB3++;
                }
                            break;
                }
            }
        }
    }
    if(entraEstradaB0 == 3)
       printf("A cidade 0 tem mais entradas\n");
    if(entraEstradaB1 == 3)
       printf("A cidade 1 tem mais entradas\n");
    if(entraEstradaB2 == 3)
       printf("A cidade 2 tem mais entradas\n");
    if(entraEstradaB3 == 3)
       printf("A cidade 3 tem mais entradas\n");
    
    
    if(saiEstrada == 0)
        printf("A cidade %d nao tem saida\n",k);
    if(saiEstrada == 0 && entraEstrada == 0)
         printf("A cidade %d eh uma cidade isolada\n",k);
    if(saiEstrada != 0 && entraEstrada == 0)
         printf("A cidade %d tem saida mas nao tem entradas\n",k);

    printf("A quantidade de estradas que saem eh:%d\n",saiEstrada);
    printf("A quantidade de estradas que entram eh:%d\n",entraEstrada);

    return 0;
}