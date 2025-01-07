#include <iostream>
#include <cstdlib> 
#define MAX 100
using namespace std;
typedef int TIPOCHAVE;

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
