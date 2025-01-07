#include <iostream>
#include <cstdlib> 
using namespace std;

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux *ant, *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct {
    PONT inicio;
} LISTA;

bool inserirElemListaOrd(LISTA *l, REGISTRO reg) {
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    if (!novo) return false;
    novo->reg = reg;
    novo->prox = NULL;
    novo->ant = NULL;

    PONT atual = l->inicio;
    PONT anterior = NULL;

    while (atual != NULL && atual->reg.chave < reg.chave) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->reg.chave == reg.chave) {
        free(novo);
        return false;
    }

    novo->prox = atual;
    if (atual != NULL) {
        atual->ant = novo; 
    }

    if (anterior == NULL) {
        l->inicio = novo; 
    } else {
        anterior->prox = novo; 
        novo->ant = anterior; 
    }

    return true;
}