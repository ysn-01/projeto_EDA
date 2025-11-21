/*********************************************************************
 * @file   vertices.c
 * @brief
 *
 * @author Yuri Nascimento
 * @email  a27957@alunos.ipca.pt
 * @date   May 2024
 *********************************************************************/
#include "header.h"

#pragma region VERTICES

#pragma region DestruirVertice

 /**
  * @brief Destrói um vértice, libertando a memória associada ao mesmo.
  *
  * Esta função recebe um apontador para um vértice e liberta a memória
  * associada ao mesmo utilizando a função `free`.
  *
  * @param v Apontador para o vértice a ser destruído.
  */
void DestruirVertice(Vertice* v) {
	free(v);
}

#pragma endregion

#pragma region CriarVertice

/**
 * @brief Cria um novo vértice com um identificador especificado.
 *
 * Esta função aloca memória para um novo vértice e inicializa seus campos.
 * Se a alocação de memória falhar, a função retorna `NULL`.
 *
 * @param id O identificador do vértice a ser criado.
 * @param valor O valor do vértice a ser criado.
 * @return Apontador para o novo vértice criado, ou `NULL` se a alocação de memória falhar.
 */
Vertice* CriarVertice(int id, int valor) {
	Vertice* v = (Vertice*)malloc(sizeof(Vertice)); // Aloca memória para criar o vértice
	if (v == NULL) return NULL;
	// Inicializa o novo vértice
	v->id = id;
	v->valor = valor;
	v->visitado = false;
	v->proxAdjacente = NULL;
	v->proxVertice = NULL;
	return v;
}

#pragma endregion

#pragma region InserirVertice

/**
 * @brief Insere um novo vértice na lista de vértices do grafo.
 *
 * Esta função insere um novo vértice na lista de vértices do grafo,
 * mantendo a ordem crescente dos identificadores dos vértices. Se a lista
 * estiver vazia, o novo vértice é inserido como o primeiro vértice. A função
 * também atualiza um indicador de sucesso.
 *
 * @param vertices Apontador para o início da lista de vértices.
 * @param novoVertice Apontador para o novo vértice a ser inserido.
 * @param res Apontador para uma variável booleana que indica o sucesso da inserção.
 *            Será definido como `true` se a inserção for bem-sucedida, caso contrário `false`.
 * @return Apontador para o início atualizada da lista de vértices.
 */
Vertice* InserirVertice(Vertice* vertices, Vertice* novoVertice, bool* res) {
	*res = false;
	// Insere um novo vértice no grafo vazio
	if (vertices == NULL) {
		*res = 1;
		vertices = novoVertice;
		return vertices;
	}
	// Verifica se o vértice já existe na lista de vértices
	if (ExisteVertice(vertices, novoVertice->id)) {
		return vertices;
	}
	else
	{
		// Procura onde inserir o vértice
		Vertice* anterior = NULL;
		Vertice* aux = vertices;
		while (aux != NULL && aux->id < novoVertice->id) {
			anterior = aux; // O vértice "anterior" passa a apontar para o vértice que "aux" estava a apontar
			aux = aux->proxVertice; // O vértice "aux" passa a apontar para o próximo vértice
		}
		*res = true;
		if (anterior == NULL) {
			novoVertice->proxVertice = vertices; // "novoVertice" e inserido no início da lista e aponta para o vértice inicial(vértices)
			vertices = novoVertice; // "vertices" passa para o início da lista e aponta para "novoVertice"(vértice que foi inserido anteriormente)
		}
		else {
			novoVertice->proxVertice = aux; // "novoVertice" e inserido antes do vértice que estava a ser apontado por "aux"(ultimo vértice da lista)
			anterior->proxVertice = novoVertice; // O vértice anterior fica a apontar para "novoVertice"(vértice que foi inserido anteriormente)
		}
	}
	return vertices;
}

#pragma endregion

#pragma region ExisteVertice

/**
 * @brief Verifica se um vértice com um determinado identificador existe na lista de vértices.
 *
 * Esta função percorre a lista de vértices a partir do vértice inicial e verifica
 * se existe um vértice com o identificador especificado.
 *
 * @param inicio Apontador para o vértice inicial da lista.
 * @param idVertice O identificador do vértice a ser procurado.
 * @return `true` se o vértice com o identificador especificado existir na lista, caso contrário `false`.
 */
bool ExisteVertice(Vertice* inicio, int idVertice) {
	if (inicio == NULL) return false;
	Vertice* aux = inicio; // "aux" fica a apontar para o vértice inicial
	while (aux) {
		if (aux->id == idVertice) return true; // Retorna "true" se o id do vértice para o qual "aux" esta a apontar for igual ao vértice pretendido
		aux = aux->proxVertice; // "aux" passa a apontar para o próximo vértice
	}
	return false;
}

#pragma endregion

#pragma region ObterVertice

/**
 * @brief Obtém um vértice com um determinado identificador na lista de vértices.
 *
 * Esta função percorre a lista de vértices a partir do vértice inicial e retorna
 * um apontador para o vértice que possui o identificador especificado.
 *
 * @param inicio Apontador para o vértice inicial da lista.
 * @param idVertice O identificador do vértice a ser procurado.
 * @return Apontador para o vértice com o identificador especificado, ou `NULL` se não for encontrado.
 */
Vertice* ObterVertice(Vertice* inicio, int idVertice) {
	if (inicio == NULL) return NULL;
	Vertice* aux = inicio;
	while (aux) {
		if (aux->id == idVertice) return aux; // Retorna "aux" se o id do vértice para o qual "aux" esta a apontar for igual ao vértice pretendido
		aux = aux->proxVertice; // "aux" passa a apontar para o próximo vértice
	}
	return aux; // Retorna o vértice para o qual "aux" esta a apontar
}

#pragma endregion

#pragma region EliminarVertice

/**
 * @brief Elimina um vértice com um determinado identificador da lista de vértices do grafo.
 *
 * Esta função procura um vértice com o identificador especificado na lista de vértices do grafo
 * e o elimina, mantendo a integridade da estrutura do grafo. Se o vértice for encontrado e eliminado
 * com sucesso, o indicador de sucesso é atualizado para `true`.
 *
 * @param vertices Apontador para a cabeça da lista de vértices do grafo.
 * @param idVertice O identificador do vértice a ser eliminado.
 * @param res Apontador para uma variável booleana que indica o sucesso da eliminação.
 *            Será definido como `true` se a eliminação for bem-sucedida, caso contrário `false`.
 * @return Apontador para a cabeça atualizada da lista de vértices do grafo.
 */
Vertice* EliminarVertice(Vertice* vertices, int idVertice, bool* res) {
	if (vertices == NULL) return NULL;
	// Procurar vertice
	Vertice* aux = vertices;
	Vertice* anterior = NULL;
	while (aux->id != idVertice) {
		anterior = aux; // O vértice "anterior" passa a apontar para o vértice que "aux" estava a apontar
		aux = aux->proxVertice;	// O vértice "aux" passa a apontar para o próximo vértice
	}
	if (!aux) return vertices; // Significa que o vértice não existe
	// Apaga o vértice no início
	if (anterior == NULL) {
		// Apaga todas as adjacências do vértice a eliminar
		aux->proxAdjacente = EliminaTodosAdjacentes(aux->proxAdjacente, res); // Chama a função para eliminar todas as adjacências do vértice para o qual "aux" estava a apontar
		if (*res == false) return vertices;
		vertices = aux->proxVertice; // "vertices" passa a apontar para o vértice seguinte do que foi eliminado
	}
	else {
		anterior->proxVertice = aux->proxVertice; // "anterior" passa a apontar para o vértice seguinte ao qual estava a ser apontado por "aux", eliminando assim o vértice pretendido
	}
	DestruirVertice(aux);
	*res = true;
	return vertices;
}

#pragma endregion

#pragma region EliminarAdjTodosVertices

/**
 * @brief Elimina todas as adjacências de um vértice com um determinado identificador em todos os vértices do grafo.
 *
 * Esta função percorre todos os vértices do grafo e elimina a adjacência com um vértice específico,
 * identificado pelo identificador `idVertice`. Se a eliminação for bem-sucedida em todos os vértices, o indicador
 * de sucesso é definido como `true`.
 *
 * @param vertices Apontador para a cabeça da lista de vértices.
 * @param idVertice O identificador do vértice cujas adjacências devem ser eliminadas.
 * @param res Apontador para uma variável booleana que indica o sucesso da eliminação das adjacências.
 *            Será definido como `true` se todas as adjacências forem eliminadas com sucesso, caso contrário `false`.
 * @return Apontador para a cabeça atualizada da lista de vértices após a eliminação das adjacências.
 */
Vertice* EliminarAdjTodosVertices(Vertice* vertices, int idVertice, bool* res) {
	*res = false;
	if (vertices == NULL) return NULL;
	Vertice* aux = vertices;
	while (aux) {
		aux->proxAdjacente = EliminarAdjacente(aux->proxAdjacente, idVertice, res); // Chama a função para eliminar a adjacência do vértice para o qual "aux" estava a apontar
		aux = aux->proxVertice; // O vértice "aux" passa a apontar para o próximo vértice
	}
	*res = true;
	return vertices;
}

#pragma endregion

#pragma region MostrarGrafo

/**
 * @brief Mostra os vértices e suas adjacências no grafo.
 *
 * Esta função percorre a lista de vértices do grafo e imprime cada vértice com os seus adjacentes,
 * juntamente com os pesos das adjacências. Os vértices são mostrados na ordem em que aparecem na lista.
 *
 * @param grafo Apontador para o vértice inicial da lista de vértices do grafo.
 */
void MostrarGrafo(Vertice* grafo) {
	Vertice* atual = grafo;
	printf("-----------------------------------------------------------------------");
	while (atual != NULL) {
		printf("\nVertice %d: %d\t", atual->id, atual->valor);
		printf("\n\n\tAdjacentes:\t");
		Adjacente* adjAtual = atual->proxAdjacente;
		while (adjAtual != NULL) {
			printf("Vertice %d:\t%d\t", adjAtual->id, adjAtual->valor);
			printf("(Soma:%d)\n\t\t\t", adjAtual->peso);
			adjAtual = adjAtual->proximo; // Passa para o próximo adjacente
		}
		printf("\n");
		atual = atual->proxVertice; // Passa o próximo vértice
		printf("-----------------------------------------------------------------------");
		printf("\n");
	}

}

#pragma endregion

#pragma endregion