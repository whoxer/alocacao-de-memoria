# Alocação de memória
Alocando memória em C por meio da biblioteca <stdlib.h> e checando a média de números com vetores.
- Introdução aos conceitos
- Boas práticas
- Desenvolvimento
- Compilação e depuração
- Conclusão
## Introdução aos conceitos

Dentro da biblioteca <stdlib.h> existe uma função extremamente importante para a alocação de memória chamada malloc(), de Memory Allocation, é uma função da biblioteca stdlib.h que recebe como argumento números inteiros positivos (size_t), que irão representar o número de bytes que iremos alocar.
Essa função retorna um ponteiro contendo o endereço do bloco alocado.
Sua sintaxe é:

```c
  void *malloc(size_t numero_de_bytes); 
  ```
Olhando para a sintaxe da função malloc() notamos uma peculiaridade dela e da linguagem C. A função retorna um ponteiro.
Ponteiros são muito úteis e especiais pois precisam saber para que tipo de variável vão apontar, pois (dentre outras coisas mais), podemos fazer operações matemática com ponteiros.
Por exemplo: 
```c
   ptr++;
```
Se esse ponteiro apontar para um caractere, ao incrementarmos, ele pulará uma posição de endereço de memória.
Já se apontar para um inteiro, ele pulará **sizeof(int)** posições de endereço, para apontar para o próximo inteiro de um vetor, por exemplo.
Por isso que para o funcionamento eficiente e hábil de um vetor é importante e essencial, que o ponteiro saiba pra que tipo de dado ele aponta.

Como a função **malloc()** serve para declarar qualquer tipo de dado, seja int, float, double ou uma struct criada por você, sua sintaxe foi mostrada como void.
Ela retorna o endereço do bloco de memória que foi alocado. Ao passo que fazemos essa alocação, devemos fazer um cast, ou seja, fazer com que um ponteiro (de algum tipo já definido) receba essa endereço.
Se quisermos alocar um bloco de endereços para inteiros, ao invés do void* colocamos:
```c
(int *) malloc(size_t bytes);
```
Lembrando que a função retorna um endereço de memória.
Logo, alguém (ponteiro) deve receber esse retorno.
Por exemplo, se quiséssemos alocar 20 caracteres para conter uma string, devemos fazer:
```c
#include <stdio.h>
#include <stdlib.h>
int main(void){
    char *nome;
    nome = (char *) malloc(21);
 
    printf("Digite seu nome: ");
    gets(nome);
 
    printf("%sn", nome);
 
    return 0;
}
```
(Por que e para quê alocarmos 21 caracteres, se queremos usar apenas 20?)
Poderíamos criar o ponteiro e logo na declaração fazer ele receber o endereço de um bloco alocado de memória:
```C
char *nome = (char *) malloc(21);
```
## Boas práticas
Uma boa e ótima prática é evitar o uso de números para escolher o número de bytes alocados.
Isso se deve ao fato de diferentes variáveis terem diferentes valores, dependendo da arquitetura.
Existem computadores que um inteiro ocupa 2 bytes, e que outros porém ocupam 4 bytes.

Sim, é um processo trabalhoso, chato e enfadonho. E isso não é o pior(é sério).
Não devemos fugir do uso dinâmico de memória, pois essa é uma das técnicas mais úteis para se otimizar programas, deixá-los mais rápidos e fazer menos uso de memória.

Ao invés de alocar daquela forma, use a alocação da forma correta e para isso use a função **sizeof()** com a sintaxe desta forma:

```c
char *nome = (char *) malloc(21*sizeof(char));
```
Denovo, é um processo trabalhoso, chato e enfadonho. E isso realmente não é o pior (kkkkrying).

## Desenvolvimento

Na função **main()**, o programa inicia um looping **do while**, que só para checar se o usuário irá digitar 0. Se sim, então o programa fecha.
Dentro deste looping é pedido um número inteiro, que será o tanto de números que o usuário vai digitar.
```c
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
```
Após ele fornecer essa informação, passamos ela para a função aloca() que vai alocar dinamicamente um *vetor de inteiros*, com o número de elementos exato que o usuário digitou, e assim retornará o endereço desse espaço alocado.

Esse endereço é armazenado no ponteiro * numeros dentro da da main().

Em seguida, mandamos esse vetor e o número de elementos para a função media(), que irá calcular a média de todos os elementos deste vetor e retornar esse float (a média de inteiros pode ser um número decimal).
```c
  float media(int *numeros, int num){
    float media = 0.0;
    int count;

    for (count = 0; count < num; count++){
        media += numeros[count];
    }
    return media / num;
}
```
Também mandamos os mesmos argumentos para a função exibe(), que irá mostrar os números digitados.
```c
  void exibe(int *numeros, int num){
    int count;

    for (count = 0; count < num; count++){
        printf("%.3d", numeros[count]);
    }
}
```
Após cada iteração do laço while, devemos liberar a memória que está apontado pelo ponteiro * numeros, senão fizermos isso a função aloca() vai alocar um espaço diferente de memória a cada iteração, consumindo a memória aos poucos. E isso não é algo que queremos.

## Compilando e debugando (pelo terminal Windows e Linux)
![image](https://user-images.githubusercontent.com/90641576/151465076-da6de657-ff28-4561-9d52-4bff9c249af2.png)

Esse programa calcula a média de 1, 2, 10, mil ou 1 milhão de números.

![image](https://user-images.githubusercontent.com/90641576/151465337-796d8077-5160-4e5f-ae1b-0ff0075cd641.png)

E o melhor, só aloca 1, 2, 10, mil ou exatos 1 milhão de bytes, nem um a mais. Extremamente econômico e não deixa seu computador 'lerdo' por consumir memória demais, o que é um grande problema ocasionado por péssimos e irresponsáveis programadores.

## Conclusão

Vimos aqui o uso da função **malloc()** e a sua importância. Aprendemos também que com grandes poderes, vêm grandes responsabilidades e por isso precisamos estar atentos ao uso demasiado e muitas das vezes desnecessário de memória nos nossos programas. Desde já eu agradeço a todos, todas e todes que leram até aqui, muito obrigado :D.
