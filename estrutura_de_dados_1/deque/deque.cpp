
#include <iostream>
#include <cstdlib> 
using namespace std;

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    
} REGISTRO;

typedef struct no {
    REGISTRO reg;
    struct no *prox;
} NO;

typedef struct {
    NO *inicio, *fim;
} DEQUE;

bool encontrarMax(DEQUE *d, int *max) {
    if (!d->inicio) return false; 

    NO *atual = d->inicio;
    *max = atual->reg.chave;

    while (atual != NULL) {
        if (atual->reg.chave > *max) {
            *max = atual->reg.chave;
        }
        atual = atual->prox;
    }

    return true;
}
