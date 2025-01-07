

#include <iostream>
#include <cstdlib> 
using namespace std;

// ================= LISTA DUPLAMENTE LIGADA ===================
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

// ==================== PILHA ESTÁTICA =========================
#define MAX 100

typedef struct {
    TIPOCHAVE chave;
} REG_PILHA;

typedef struct {
    REG_PILHA A[MAX];
    int topo;
} PILHA;

void exibirPilhaInvertida(PILHA *p) {
    printf("Pilha (da base para o topo): \" ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->A[i].chave);
    }
    printf("\"\n");
}

// ======================= DEQUE ==============================
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

// ================= FILA COM NÓ-CABEÇA =======================
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

int main() {
    
    return 0;
}