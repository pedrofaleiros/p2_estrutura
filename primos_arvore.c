#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
    int valor;
    struct no * esquerda;
    struct no * direita;
}no;

void pre_ordem(no * node);
no * inclui_arvore(no * node, int num);
no * aloca_no();
int calcula_primos(no * node);
int primo(int num);

int main()
{
    srand(time(NULL));

    no * raiz;
    int primos, aux, i, num;

    raiz = NULL;
    num = 10;

    printf("\n incluindo %d numeros aleatorios entre 1 e 100", num);
    for(i = 0; i < num; i++){
        aux = rand()%100 + 1;
        raiz = inclui_arvore(raiz, aux);
    }

    printf("\npre-ordem: ");
    pre_ordem(raiz);

    primos = calcula_primos(raiz);

    printf("\n\n quantidade de números primos: %d", primos);

    printf("\n");
    return 0;
}

int primo(int num)
{
    int flag, i;

    if(num <= 1)
        return 0;

    for(i = 2; i < num; i++){
        if(num % i == 0)
            return 0;    
    }

    return 1;
}

int calcula_primos(no * node)
{
    int primos;

    if(node == NULL)
        return 0;
    else
        return primo(node->valor) + calcula_primos(node->esquerda) + calcula_primos(node->direita);
}

no * aloca_no()
{
    no * novo;
    novo = (no*)calloc(1, sizeof(no));
    return novo;
}

no * inclui_arvore(no * node, int num)
{

    if(node == NULL){
        no * novo;
        novo = aloca_no();
        novo->valor = num;
        node = novo;
        return novo;
    }else{
        if(num > node->valor){
            node->direita = inclui_arvore(node->direita, num);
        }else{
            node->esquerda = inclui_arvore(node->esquerda, num);
        }
    }
    return node;
}

void pre_ordem(no * node)
{
    if(node != NULL){
        printf(" %d", node->valor);
        pre_ordem(node->esquerda);
        pre_ordem(node->direita);
    }
}