# Projeto de Estruturas de Dados Avançadas (EDA – C)

## Autor
- **Nome:** Yuri Nascimento
- **Número:** 27957
- **Curso:** Engenharia de Sistemas Informáticos

---

Projeto em C desenvolvido no âmbito da unidade curricular **Estruturas de Dados Avançadas**.

O projeto aplica estruturas de dados dinâmicas, armazenamento em ficheiros e algoritmos de procura para resolver problemas de otimização sobre matrizes de inteiros.

## Fase 1 – Listas ligadas

Implementação de uma solução para calcular a **soma máxima possível** dos inteiros de uma matriz, garantindo que:
- não são escolhidos dois inteiros na **mesma linha**;
- não são escolhidos dois inteiros na **mesma coluna**.

Principais pontos:
- representação da matriz com **estruturas de dados dinâmicas** (listas ligadas);
- carregamento da matriz a partir de um **ficheiro de texto** (valores separados por `;`);
- operações de:
  
  - alteração de valores;
  - inserção de linhas/colunas;
  - remoção de linhas/colunas;
  - listagem tabular da matriz na consola;
    
- cálculo da soma máxima sob as restrições de linha/coluna.

---

## Fase 2 – Grafos

Modelação do problema com **grafos dirigidos**:

- cada elemento da matriz é representado por um **vértice**;
- as **arestas** representam a possibilidade de somar dois elementos adjacentes, segundo regras de conexão configuráveis (ex.: mesma linha/coluna, sem diagonais);
- carregamento da matriz para a estrutura de grafo a partir de ficheiro de texto;
- implementação de algoritmos de **procura em profundidade (DFS)** e/ou **procura em largura (BFS)** para:
  
  - gerar caminhos válidos;
  - calcular a soma dos valores ao longo de um caminho;
    
- determinação do(s) caminho(s) com **soma máxima**, apresentando:
  
  - o valor máximo encontrado;
  - o caminho (ou caminhos) correspondente(s).

---
