/*********************************************************************
 * @file   adjacentes.c
 * @brief
 *
 * @author Yuri Nascimento
 * @email  a27957@alunos.ipca.pt
 * @date   May 2024
 *********************************************************************/
#include "header.h"

#pragma region ADJACENTES

#pragma region CriarAdjacente

 /**
  * @brief Cria um novo adjacente com um identificador e um peso especificados.
  *
  * Esta função aloca memória para um novo adjacente e inicializa os seus campos com os valores especificados.
  * Se a alocação de memória falhar, a função retorna `NULL`.
  *
  * @param id O identificador do adjacente a ser criado.
  * @param valor O valor da adjacência.
  * @param peso O peso da adjacência.
  * @return Apontador para o novo adjacente criado, ou `NULL` se a alocação de memória falhar.
  */
Adjacente* CriarAdjacente(int id, int valor, int peso) {
	Adjacente* adj = (Adjacente*)malloc(sizeof(Adjacente)); // Aloca memória para criar o adjacente
	if (adj == NULL) return NULL;
	// Inicializa o novo adjacente
	adj->id = id;
	adj->valor = valor;
	adj->peso = peso;
	adj->proximo = NULL;
	return adj;
}

#pragma endregion

#pragma region DestruirAdjacente

/**
 * @brief Liberta a memória associada a um adjacente.
 *
 * Esta função liberta a memória associada a um adjacente, que foi alocada anteriormente
 * utilizando a função `malloc`.
 *
 * @param adj Apontador para o adjacente a ser destruído.
 */
void DestruirAdjacente(Adjacente* adj) {
	free(adj);
}

#pragma endregion

#pragma region EliminarAdjacente

/**
 * @brief Elimina uma adjacência com um determinado identificador da lista de adjacências.
 *
 * Esta função procura e elimina uma adjacência com o identificador especificado da lista de adjacências.
 * Se a eliminação for bem-sucedida, o indicador de sucesso é definido como `true`.
 *
 * @param listaAdj Apontador para o início da lista de adjacências.
 * @param idAdj O identificador da adjacência a ser eliminada.
 * @param res Apontador para uma variável booleana que indica o sucesso da eliminação.
 *            Será definido como `true` se a adjacência for encontrada e eliminada com sucesso, caso contrário `false`.
 * @return Apontador para o início atualizado da lista de adjacências após a eliminação.
 */
Adjacente* EliminarAdjacente(Adjacente* listaAdj, int idAdj, bool* res) {
	if (listaAdj == NULL) return NULL;
	// Procura a adjacência
	Adjacente* aux = listaAdj;
	Adjacente* anterior = NULL;
	while (aux && aux->id != idAdj) {
		anterior = aux; // O adjacente "anterior" passa a apontar para o adjacente que "aux" estava a apontar
		aux = aux->proximo; // O adjacente "aux" passa a apontar para o próximo adjacente
	}
	if (!aux) return listaAdj; // A adjacência não existe
	// Apaga a adjacência no início
	if (anterior == NULL) {
		listaAdj = aux->proximo; // "listaAdj" passa a apontar para o adjacente seguinte de "aux", eliminando assim o primeiro adjacente da lista
	}
	else
	{
		// Apaga o vértice
		anterior->proximo = aux->proximo; // "anterior" passa a apontar para o adjacente seguinte ao qual estava a ser apontado por "aux", eliminando assim o adjacente pretendido
	}
	DestruirAdjacente(aux);
	*res = true;
	return listaAdj;
}

#pragma endregion

#pragma region EliminaTodosAdjacentes

/**
 * @brief Elimina todas as adjacências da lista de adjacências.
 *
 * Esta função percorre a lista de adjacências e elimina todos os seus elementos.
 * Se a eliminação for bem-sucedida, o indicador de sucesso é definido como `true`.
 *
 * @param listaAdj Apontador para o início da lista de adjacências.
 * @param res Apontador para uma variável booleana que indica o sucesso da eliminação.
 *            Será definido como `true` se todas as adjacências forem eliminadas com sucesso, caso contrário `false`.
 * @return Apontador nulo após a eliminação de todas as adjacências.
 */
Adjacente* EliminaTodosAdjacentes(Adjacente* listaAdj, bool* res) {
	*res = false;
	if (listaAdj == NULL) return NULL;
	// Percorre a lista de adjacências
	Adjacente* aux = listaAdj;
	while (aux) {
		if (aux) {
			listaAdj = aux->proximo; // "listaAdj" passa a apontar para adjacente seguinte ao que "aux" estava a apontar, assim eliminando o adjacente apontado por "aux"
		}
		DestruirAdjacente(aux);
		aux = listaAdj;
	}
	listaAdj = NULL;
	*res = true;
	return listaAdj;
}

#pragma endregion

#pragma region InserirAdjacente

/**
 * Insere um novo adjacente à lista de adjacências.
 *
 * Esta função cria e insere um novo nó adjacente à lista de adjacências.
 * Se a lista de adjacências estiver vazia, o novo nó será inserido no início.
 * Caso contrário, será inserido no final da lista.
 *
 * @param listaAdj Apontador para a lista de adjacências.
 * @param idDestino Identificador do nó adjacente.
 * @param valor Valor do nó adjacente.
 * @param peso Peso da aresta para o nó adjacente.
 * @return Retorna um apontador para a lista de adjacências atualizada.
 */
Adjacente* InserirAdjacente(Adjacente* listaAdj, int idDestino, int valor, int peso) {
	Adjacente* novoAdj;
	if ((novoAdj = CriarAdjacente(idDestino, valor, peso)) == NULL) {
		return listaAdj; // Se não conseguiu criar uma nova adjacência
	}
	// Se a lista de adjacências esta vazia
	if (listaAdj == NULL) {
		listaAdj = novoAdj; // Insere uma nova adjacência do inicio
	}
	else {
		// Por opcão, inserir no fim da LA
		Adjacente* aux = listaAdj;
		while (aux->proximo != NULL)
		{
			aux = aux->proximo; // O adjacente "aux" passa a apontar para o próximo adjacente
		}
		aux->proximo = novoAdj; // "aux" fica a apontar para o "novoAdj"(adjacente inserido anteriormente no final da linha)
	}
	return listaAdj;
}

#pragma endregion

#pragma endregion