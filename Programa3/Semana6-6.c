#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int mapa[10][10];
    int QuantidadePico=0,QuantidadeAgua=0;
    //lendo a quantidade de pico e de agua que tem
    scanf("%d %d",&QuantidadePico,&QuantidadeAgua);
    
    int XPico[QuantidadePico],YPico[QuantidadePico],AlturaPico[QuantidadePico];
    int XAgua[QuantidadeAgua],YAgua[QuantidadeAgua],AlturaAgua[QuantidadeAgua];
    //coordenadas e alturas do pico e da agua
    for(int i=0;i<QuantidadePico;i++){
        scanf("%d %d %d",&XPico[i],&YPico[i],&AlturaPico[i]);
    }
    for(int i=0;i<QuantidadeAgua;i++){
        scanf("%d %d %d",&XAgua[i],&YAgua[i],&AlturaAgua[i]);
    }
   //zerando o mapa
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            mapa[i][j]=0;
        }
    }

    


    //Printando o mapa 
    printf("  | ");
    for(int i=0;i<10;i++){
        printf("%d ",i);
    }
      printf("\n--+--------------------\n");
    for(int i=0;i<10;i++){
        printf("%d | ",i);
        for(int j=0;j<10;j++){
            printf("%d ",mapa[i][j]);
        }
        printf("\n");
    }
    return 0;
}