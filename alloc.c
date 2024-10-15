#include <stdio.h>
#include <stdlib.h>
int *aloca(int num){
    int count,*numeros;
    numeros = (int*)malloc(num*sizeof(int));

    for (count = 0; count < num; count++){
       printf("Numero[%d]:", count+1);
       scanf("%d", &numeros[count]);
    }
    return numeros;
}
float media(int *numeros, int num){
    float media = 0.0;
    int count;

    for (count = 0; count < num; count++){
        media += numeros[count];
    }
    return media / num;
}
void exibe(int *numeros, int num){
    int count;

    for (count = 0; count < num; count++){
        printf("%.3d", numeros[count]);
    }
}
int main(){
    int num = 1, *numeros;
    do{
        if (num > 0){
        printf("\nMedia de quantos numeros [0 para sair]:");
        scanf("%d", &num);
        numeros = aloca(num);
        exibe(numeros, num);
        printf("\n\tA media destes numeros eh: %.2f", media(numeros, num));
        free(numeros);
    }
    } while (num);
}