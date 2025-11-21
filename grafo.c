/*********************************************************************
 * @file   grafo.c
 * @brief
 *
 * @author Yuri Nascimento
 * @email  a27957@alunos.ipca.pt
 * @date   May 2024
 *********************************************************************/
#include "header.h"

#pragma region GRAFO

#pragma region CriarGrafo

 /**
  * Cria um novo grafo com o número total de vértices especificado.
  *
  * Esta função aloca memória para um novo grafo e inicializa suas variáveis.
  *
  * @param tot Número total de vértices do grafo.
  * @return Retorna um apontador para o novo grafo criado.
  */
Grafo* CriarGrafo(int tot) {
	Grafo* g = (Grafo*)malloc(sizeof(Grafo)); // Aloca memória para criar o grafo
	if (g != NULL) { // Inicializa todas as variáveis do grafo
		g->inicioGrafo = NULL;
		g->numVertices = 0;
		g->totVertices = tot;
	}
	return g;
}

#pragma endregion

#pragma region InserirVerticeGrafo

/**
 * Insere um novo vértice no grafo.
 * Esta função insere um novo vértice no grafo, desde que o vértice seja válido
 * e ainda não exista no grafo.
 *
 * @param g Apontador para o grafo onde o vértice será inserido.
 * @param v Apontador para o vértice a ser inserido.
 * @param res Apontador para um inteiro onde será armazenado o resultado da operação:
 *        - 1: Inserção bem-sucedida.
 *        - 0: Vértice inválido, a inserção não foi realizada.
 *        - -1: O grafo é inválido, a inserção não foi realizada.
 *        - -2: O vértice já existe no grafo, a inserção não foi realizada.
 * @return Retorna um apontador para o grafo atualizado após a inserção do vértice.
 */
Grafo* InserirVerticeGrafo(Grafo* g, Vertice* v, int* res) {
	*res = 1;
	if (v == NULL) { // Vértice inválido
		*res = 0;
		return g;
	}
	if (g == NULL) { // Grafo vazio
		*res = -1;
		return NULL;
	}
	if (ExisteVerticeGrafo(g, v->id)) { // Verifica se o vértice já existe
		*res = -2;
		return g;
	}
	g->inicioGrafo = InserirVertice(g->inicioGrafo, v, res); // Chama a função para inserir o vértice no início do grafo depois de todas as validações
	if (*res == true) {
		g->numVertices++;
	}
	return g;
}

#pragma endregion

#pragma region InserirAdjGrafo

/**
 * Insere uma aresta entre dois vértices no grafo.
 *
 * Esta função insere uma aresta entre os vértices de origem e destino no grafo, se eles existirem.
 *
 * @param g Apontador para o grafo.
 * @param idOrigem Identificador do vértice de origem.
 * @param idDestino Identificador do vértice de destino.
 * @param res Apontador para uma variável booleana que será definida como verdadeira se a operação for bem-sucedida.
 * @return Retorna um apontador para o grafo atualizado ou NULL se o grafo for nulo ou se os vértices não forem encontrados.
 */
Grafo* InserirAdjGrafo(Grafo* g, int idOrigem, int idDestino, bool* res) {
	*res = false;
	if (g == NULL) return NULL;
	Vertice* vertOrigem = OndeEstaVerticeGrafo(g, idOrigem); // Chama a função para procurar o vértice de origem
	if (vertOrigem == NULL) return g;
	Vertice* vertDestino = OndeEstaVerticeGrafo(g, idDestino); // Chama a função para procurar o vértice de destino
	if (!vertDestino) return g;
	int valorAdj = vertDestino->valor; // Adiciona o valor ao adjacente
	int peso = vertOrigem->valor + vertDestino->valor; // Calcula o peso de uma aresta (valor do "vertOrigem" + o valor do "vertDestino")
	vertOrigem->proxAdjacente = InserirAdjacente(vertOrigem->proxAdjacente, idDestino, valorAdj, peso); // Chama a função para adicionar um novo adjacente ao vértice de origem
	*res = true;
	return g;
}

#pragma endregion

#pragma region EliminarAdjGrafo

/**
 * @brief Elimina uma aresta entre dois vértices em um grafo.
 *
 * Esta função elimina a aresta entre o vértice de origem e o vértice de destino no grafo fornecido.
 *
 * @param g O apontador para o grafo.
 * @param idOrigem O identificador do vértice de origem.
 * @param idDestino O identificador do vértice de destino.
 * @param res Um apontador para uma variável booleana que será atualizada para true se a operação for bem-sucedida, false caso contrário.
 * @return O apontador para o grafo após a eliminação da aresta.
 */
Grafo* EliminarAdjGrafo(Grafo* g, int idOrigem, int idDestino, bool* res) {
	*res = false;
	if (g == NULL) return NULL;
	Vertice* vertOrigem = OndeEstaVerticeGrafo(g, idOrigem); // Chama a função para procurar o vértice de origem
	if (vertOrigem == NULL) return g;
	Vertice* vertDestino = OndeEstaVerticeGrafo(g, idDestino); // Chama a função para procurar o vértice de destino
	if (!vertDestino) return g;
	vertOrigem->proxAdjacente = EliminarAdjacente(vertOrigem->proxAdjacente, idDestino, res); // Chama a função para eliminar o adjacente do vértice de origem
	return g;
}

#pragma endregion

#pragma region OndeEstaVerticeGrafo

/**
 * @brief Encontra um vértice em um grafo com base em seu identificador.
 *
 * Esta função procura e retorna um apontador para o vértice com o identificador especificado no grafo fornecido.
 *
 * @param g O apontador para o grafo.
 * @param idVertice O identificador do vértice a ser encontrado.
 * @return Um apontador para o vértice encontrado, ou NULL se o vértice não for encontrado ou se o grafo for nulo.
 */
Vertice* OndeEstaVerticeGrafo(Grafo* g, int idVertice) {
	if (g == NULL) return NULL;
	return(ObterVertice(g->inicioGrafo, idVertice)); // Retorna a função para obter o vértice
}

#pragma endregion

#pragma region ExisteVerticeGrafo

/**
 * @brief Verifica se um vértice existe em um grafo com base em seu identificador.
 *
 * Esta função verifica se um vértice com o identificador especificado existe no grafo fornecido.
 *
 * @param g O apontador para o grafo.
 * @param idVertice O identificador do vértice a ser verificado.
 * @return true se o vértice existir no grafo, false caso contrário ou se o grafo for nulo.
 */
bool ExisteVerticeGrafo(Grafo* g, int idVertice) {
	if (g == NULL) return NULL;
	return(ExisteVertice(g->inicioGrafo, idVertice)); // Retorna a função para verificar se o vértice existe
}

#pragma endregion

#pragma region EliminarVerticeGrafo

/**
 * @brief Elimina um vértice de um grafo com base em seu identificador.
 *
 * Esta função elimina o vértice com o identificador especificado do grafo fornecido.
 *
 * @param g O apontador para o grafo.
 * @param idVertice O identificador do vértice a ser eliminado.
 * @param res Um apontador para uma variável booleana que será atualizada para true se a operação for bem-sucedida, false caso contrário.
 * @return O apontador para o grafo após a eliminação do vértice.
 */
Grafo* EliminarVerticeGrafo(Grafo* g, int idVertice, bool* res) {
	*res = false;
	if (g == NULL) return NULL;
	g->inicioGrafo = EliminarVertice(g->inicioGrafo, idVertice, res); // Chama a função para eliminar o vértice
}

#pragma endregion

#pragma region MostrarGrafoLA

/**
 * @brief Mostra um grafo representado como lista de adjacências.
 *
 * Esta função mostra na saída padrão o grafo fornecido, que está representado como lista de adjacências.
 *
 * @param g O apontador para o grafo a ser mostrado.
 */
void MostrarGrafoLA(Grafo* g) {
	MostrarGrafo(g->inicioGrafo); // Chama a função para mostrar o grafo
}

#pragma endregion

#pragma endregion