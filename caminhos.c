/*********************************************************************
 * @file   caminhos.c
 * @brief
 *
 * @author Yuri Nascimento
 * @email  a27957@alunos.ipca.pt
 * @date   May 2024
 *********************************************************************/
#include "header.h"

#pragma region CAMINHOS

#pragma region BuscarProfundidade

 /**
  * Função para realizar uma busca em profundidade num grafo a partir de um vértice dado.
  *
  * Esta função implementa uma busca em profundidade num grafo, começando a partir de um vértice inicial
  * e procurando por um vértice de destino. Ela marca os vértices visitados, acumula a soma dos valores
  * dos vértices visitados e verifica se o vértice de destino é alcançável a partir do vértice inicial.
  *
  * @param v O vértice inicial da busca.
  * @param idDestino O identificador do vértice de destino a ser encontrado.
  * @param visitado Um array de booleanos indicando se cada vértice foi visitado ou não.
  * @param soma Um apontador para a soma acumulada dos valores dos vértices visitados.
  * @param g O apontador para o grafo onde a busca será realizada.
  * @return Retorna verdadeiro se o vértice de destino for encontrado a partir do vértice inicial, caso contrário, retorna falso.
  */
bool BuscarProfundidade(Vertice* v, int idDestino, bool* visitado, int* soma, Grafo* g) {
	// Marcar o vértice atual como visitado
	visitado[v->id] = true;
	// Adicionar o valor do vértice atual à soma
	*soma += v->valor;
	// Se o vértice atual for o destino, retornar true
	if (v->id == idDestino) {
		return true;
	}
	// Percorrer os vértices adjacentes
	Adjacente* adjacente = v->proxAdjacente;
	while (adjacente != NULL) {
		// Obter o vértice adjacente
		Vertice* verticeAdjacente = OndeEstaVerticeGrafo(g, adjacente->id);

		// Se o vértice adjacente não foi visitado, realizar uma busca em profundidade a partir dele
		if (!visitado[adjacente->id] && BuscarProfundidade(verticeAdjacente, idDestino, visitado, soma, g)) {
			return true;
		}

		// Avançar para o próximo vértice adjacente
		adjacente = adjacente->proximo;
	}
	// Se nenhum caminho para o destino foi encontrado a partir deste vértice, retornar false
	return false;
}

#pragma endregion

#pragma region CalcularSomaCaminho

/**
 * Função para calcular a soma dos valores ao longo do caminho entre dois vértices num grafo.
 *
 * Esta função calcula a soma dos valores dos vértices ao longo do caminho entre dois vértices
 * num grafo utilizando uma busca em profundidade. Ela verifica se os vértices de origem e destino
 * existem no grafo, marca os vértices visitados durante a busca, realiza a busca em profundidade
 * para encontrar o caminho entre os vértices de origem e destino e retorna a soma dos valores dos
 * vértices no caminho encontrado.
 *
 * @param g O apontador para o grafo onde a busca será realizada.
 * @param idOrigem O identificador do vértice de origem.
 * @param idDestino O identificador do vértice de destino.
 * @return Retorna a soma dos valores dos vértices no caminho entre os vértices de origem e destino.
 *         Retorna -1 se um ou ambos os vértices não existirem no grafo ou se não houver caminho entre eles.
 */
int CalcularSomaCaminho(Grafo* g, int idOrigem, int idDestino) {
	// Verificar se os vértices de origem e destino existem no grafo
	Vertice* verticeOrigem = OndeEstaVerticeGrafo(g, idOrigem);
	Vertice* verticeDestino = OndeEstaVerticeGrafo(g, idDestino);
	if (verticeOrigem == NULL || verticeDestino == NULL) {
		printf("Um ou ambos os vértices não existem no grafo.\n");
		return -1;
	}
	// Inicializar um array para marcar os vértices visitados durante a busca em profundidade
	int numVertices = g->totVertices;
	bool* visitado = (bool*)malloc(numVertices * sizeof(bool));
	for (int i = 0; i < numVertices; ++i) {
		visitado[i] = false;
	}
	// Inicializar a soma como zero
	int soma = 0;
	// Realizar a busca em profundidade para encontrar o caminho entre os vértices de origem e destino
	if (!BuscarProfundidade(verticeOrigem, idDestino, visitado, &soma, g)) {
		printf("Não há caminho entre os vértices %d e %d.\n", idOrigem, idDestino);
		free(visitado);
		return -1;
	}
	// Libertar a memória alocada para o array de visitados
	free(visitado);
	// Retornar a soma dos vértices no caminho
	return soma;
}

#pragma endregion

#pragma endregion