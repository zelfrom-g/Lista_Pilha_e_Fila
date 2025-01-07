# Atividade de Estrutura de Dados I

Este projeto foi desenvolvido como parte da disciplina de Estruturas de Dados I, com o objetivo de implementar e manipular diferentes estruturas de dados, como listas, pilhas, deques e filas.

## 1. Lista Duplamente Ligada
- Atualização da função de inserção `inserirElemListaOrd`:
  - Configura os ponteiros `ant` e `prox` corretamente.
  - Impede a inserção de elementos duplicados.

## 2. Pilha Estática
- Implementação da função `exibirPilhaInvertida`:
  - Exibe os elementos da pilha do **mais antigo (base)** até o **mais recente (topo)**.

## 3. Deque
- Implementação da função `encontrarMax`:
  - Encontra a maior chave no deque.
  - Retorna `false` caso o deque esteja vazio.

## 4. Fila com Nó-Cabeça
- Adaptação das funções:
  - `inserirNaFila`: Insere novos elementos considerando o nó-cabeça.
  - `excluirDaFila`: Exclui elementos considerando o nó-cabeça, que nunca é removido.

## Observações
- O código está organizado para facilitar testes adicionais.
- Adicione os casos de teste no `main()` para validar cada funcionalidade implementada.
