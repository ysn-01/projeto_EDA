/*********************************************************************
 * @file   soma.c
 * @brief
 *
 * @author Yuri Nascimento
 * @email  a27957@alunos.ipca.pt
 * @date   May 2024
 *********************************************************************/
#include "header.h"

#pragma region SOMA MAXIMA

#pragma region AtualizarResultado

 /**
  * Função para atualizar um resultado com base em uma nova soma e caminho.
  *
  * Esta função atualiza um resultado com base em uma nova soma e caminho encontrados durante
  * a análise de um grafo. Se a soma atual for maior que a soma armazenada no resultado, a soma
  * e o caminho no resultado são atualizados com os valores fornecidos.
  *
  * @param res O apontador para o resultado a ser atualizado.
  * @param somaAtual A soma atual a ser comparada com a soma armazenada no resultado.
  * @param caminhoAtual O apontador para o vértice representando o caminho atual a ser armazenado no resultado.
  * @return Retorna 0 se a atualização for bem-sucedida, caso contrário, retorna -1.
  */
int AtualizarResultado(Resultado* res, int somaAtual, Vertice* caminhoAtual) {
	if (res == NULL) return -1;
	if (somaAtual > res->soma) { // Comparar a soma atual com a soma armazenada no resultado
		res->soma = somaAtual; // Atualizar a soma no resultado
		res->caminho = caminhoAtual; // Atualizar o caminho no resultado
	}
	return 0;
}

#pragma endregion

#pragma region BuscarCaminhoMaximo

/**
 * Função para buscar o caminho máximo em um grafo a partir de um vértice dado.
 *
 * Esta função realiza uma busca em profundidade a partir de um vértice em um grafo, buscando
 * encontrar o caminho máximo (com a maior soma de valores dos vértices) possível. Ela marca os
 * vértices visitados durante a busca, atualiza o resultado com o caminho máximo encontrado e
 * continua a busca pelos vértices adjacentes não visitados. Após a conclusão da busca em profundidade
 * a partir de um vértice, ele é desmarcado como visitado para permitir outras buscas.
 *
 * @param v O vértice inicial da busca.
 * @param somaAtual A soma acumulada dos valores dos vértices ao longo do caminho atual.
 * @param res O apontador para o resultado onde o caminho máximo será armazenado.
 * @return Retorna 0 após concluir a busca em profundidade a partir do vértice dado.
 *         Retorna -1 se o vértice dado for nulo.
 */
int BuscarCaminhoMaximo(Vertice* v, int somaAtual, Resultado* res) {
	if (v == NULL) {
		return -1;
	}
	// Marcar o vértice como visitado
	v->visitado = true;
	somaAtual += v->valor;
	// Atualizar o resultado se a soma atual for maior
	AtualizarResultado(res, somaAtual, v);
	// Recorrer os vértices adjacentes
	Adjacente* adj = v->proxAdjacente;
	while (adj != NULL) {
		Vertice* verticeAdjacente = OndeEstaVerticeGrafo(res->grafo, adj->id);
		if (verticeAdjacente != NULL && !verticeAdjacente->visitado) {
			BuscarCaminhoMaximo(verticeAdjacente, somaAtual, res); // Continuar a busca em profundidade
		}
		adj = adj->proximo;
	}
	// Desmarcar o vértice como visitado para permitir outras buscas
	v->visitado = false;
	return 0;
}

#pragma endregion

#pragma region CaminhoSomaMaxima

/**
 * Função para encontrar o caminho com a soma máxima de valores em um grafo.
 *
 * Esta função percorre todos os vértices de um grafo, realizando uma busca em profundidade a partir de cada vértice
 * para encontrar o caminho com a soma máxima de valores. Ela utiliza a função BuscarCaminhoMaximo para buscar o caminho
 * máximo a partir de cada vértice e atualiza o resultado com o caminho máximo encontrado.
 *
 * @param g O apontador para o grafo onde o caminho com a soma máxima será procurado.
 * @return Retorna um apontador para o resultado contendo o caminho com a soma máxima de valores.
 *         Retorna NULL se não for possível alocar memória para o resultado.
 */
Resultado* CaminhoSomaMaxima(Grafo* g) {
	Resultado* res = (Resultado*)malloc(sizeof(Resultado));
	if (res == NULL) {
		return NULL;
	}
	res->soma = 0;
	res->caminho = NULL;
	res->grafo = g;
	Vertice* v = g->inicioGrafo; // Iniciar a busca a partir do primeiro vértice do grafo
	while (v != NULL) {
		BuscarCaminhoMaximo(v, 0, res); // Buscar o caminho máximo a partir do vértice atual
		v = v->proxVertice; // Avançar para o próximo vértice
	}
	return res;
}

#pragma endregion

#pragma region MostrarSomaMaxima

/**
 * Função para mostrar o caminho com a soma máxima de valores em um grafo.
 *
 * Esta função imprime na saída padrão a soma máxima de valores encontrada no grafo e o caminho associado a essa soma máxima.
 * Ela utiliza a função CaminhoSomaMaxima para encontrar o resultado contendo o caminho com a soma máxima e imprime
 * os detalhes desse caminho na saída padrão.
 *
 * @param grafo O apontador para o grafo onde o caminho com a soma máxima será procurado e exibido.
 */
void MostrarSomaMaxima(Grafo* grafo) {
	Resultado* res = CaminhoSomaMaxima(grafo); // Encontrar o caminho com a soma máxima
	if (res == NULL) return NULL;
	Vertice* caminho = res->caminho;
	printf("Soma Maxima: %d\n", res->soma);
	printf("Caminho: ");
	while (caminho != NULL) {
		printf("%d(%d)\t", caminho->id, caminho->valor);
		caminho = caminho->proxVertice;
	}
	printf("\n");
	free(res);
}

#pragma endregion

#pragma endregion