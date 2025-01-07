
#include <iostream>
#include <cstdlib> 
using namespace std;

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    
} REGISTRO;

typedef struct elemento_fila {
    REGISTRO reg;
    struct elemento_fila *prox;
} ELEMENTO_FILA;

typedef ELEMENTO_FILA *PONT_FILA;

typedef struct {
    PONT_FILA inicio, fim;
} FILA;

bool inserirNaFila(FILA *f, REGISTRO reg) {
    PONT_FILA novo = (PONT_FILA)malloc(sizeof(ELEMENTO_FILA));
    if (!novo) return false;
    novo->reg = reg;
    novo->prox = NULL;

    if (!f->inicio) {
        f->inicio = novo; 
    } else {
        f->fim->prox = novo; 
    }

    f->fim = novo; 
    return true;
}

bool excluirDaFila(FILA *f, REGISTRO *reg) {
    if (!f->inicio) return false; 

    PONT_FILA apagar = f->inicio; 
    *reg = apagar->reg; 

    f->inicio = f->inicio->prox; 

    if (!f->inicio) {
        f->fim = NULL; 
    }

    free(apagar); 
    return true;
}
