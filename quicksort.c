#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;
}lista;

lista * aloca_lista();
elemento * aloca_elemento();
void inclui_lista(lista * l, int num);
int * funcao(lista * l);
void mostra_vetor(int * vet, int tamanho);
void quick_sort(int * vet, int inicio, int final);

int main()
{
    int N, i, num, * vet;
    lista * l;

    l = aloca_lista();

    printf("\n N: ");
    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d", &num);
        inclui_lista(l, num);
    }

    vet = funcao(l);

    mostra_vetor(vet, N);

    printf("\n");
    return 0;
}

void quick_sort(int * vet, int inicio, int final)
{
    int i, pivo, aux;

    if(inicio >= final)
        return;

    pivo = inicio;
    i = final;

    while(i != pivo){

        if(pivo > i){
            if(vet[pivo] < vet[i]){
                aux = vet[i];
                vet[i] = vet[pivo];
                vet[pivo] = aux;

                aux = i;
                i = pivo;
                pivo = aux;
            }
        }else{
            if(vet[pivo] > vet[i]){
                aux = vet[i];
                vet[i] = vet[pivo];
                vet[pivo] = aux;

                aux = i;
                i = pivo;
                pivo = aux;
            }
        }

        if(i < pivo)
            i++;
        else
            i--;
    }

    quick_sort(vet, inicio, pivo);
    quick_sort(vet, pivo+1, final);
}

void mostra_vetor(int * vet, int tamanho)
{
    int i = 0;
    printf("\n Valores: ");
    for(; i < tamanho; i++)
        printf(" %d", vet[i]);
}

int * funcao(lista * l)
{
    int * vet, i;

    vet = calloc(l->qtd, sizeof(int));

    elemento * aux;

    aux = l->inicio;

    i = 0;
    while(aux){
        vet[i] = aux->valor;
        aux = aux->prox;
        i++;
    }

    quick_sort(vet, 0, l->qtd - 1);

    return vet;
}

void inclui_lista(lista * l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        elemento * aux;

        aux = l->inicio;    

        while(aux->prox)
            aux = aux->prox;

        aux->prox = novo;
    }
    l->qtd++;
}

lista * aloca_lista()
{
    lista * nova;
    nova = (lista*)calloc(1, sizeof(lista));
    return nova;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = (elemento*)calloc(1, sizeof(elemento));
    return novo;
}