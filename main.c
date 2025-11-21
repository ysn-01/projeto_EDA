/*********************************************************************
 * @file   main.c
 * @brief
 *
 * @author Yuri Nascimento
 * @email  a27957@alunos.ipca.pt
 * @date   May 2024
 *********************************************************************/
#include "../TP_27957_F2/header.h"

 /**
  * Função principal do programa.
  *
  * Esta função cria um grafo, insere vértices e arestas, busca e mostra o grafo,
  * encontra e mostra o caminho com a soma máxima de valores no grafo.
  *
  * @return Retorna 0 se o programa for executado com sucesso.
  */
int main() {

	//int res;
	//Grafo* g = LerMatrizDeFicheiro("matriz.txt",&res);
	//MostrarGrafo(g->inicioGrafo);

	int res;
	Grafo* g = CriarGrafo(MAX_VERTICES);

#pragma region CRIAÇÃO DE VERTICES

	Vertice* v1 = CriarVertice(1, 7);
	Vertice* v2 = CriarVertice(2, 53);
	Vertice* v3 = CriarVertice(3, 183);
	Vertice* v4 = CriarVertice(4, 439);
	Vertice* v5 = CriarVertice(5, 863);
	Vertice* v6 = CriarVertice(6, 497);
	Vertice* v7 = CriarVertice(7, 383);
	Vertice* v8 = CriarVertice(8, 563);
	Vertice* v9 = CriarVertice(9, 79);
	Vertice* v10 = CriarVertice(10, 973);
	Vertice* v11 = CriarVertice(11, 287);
	Vertice* v12 = CriarVertice(12, 63);
	Vertice* v13 = CriarVertice(13, 343);
	Vertice* v14 = CriarVertice(14, 169);
	Vertice* v15 = CriarVertice(15, 583);
	Vertice* v16 = CriarVertice(16, 627);
	Vertice* v17 = CriarVertice(17, 343);
	Vertice* v18 = CriarVertice(18, 773);
	Vertice* v19 = CriarVertice(19, 959);
	Vertice* v20 = CriarVertice(20, 943);
	Vertice* v21 = CriarVertice(21, 767);
	Vertice* v22 = CriarVertice(22, 473);
	Vertice* v23 = CriarVertice(23, 103);
	Vertice* v24 = CriarVertice(24, 699);
	Vertice* v25 = CriarVertice(25, 303);

#pragma endregion

#pragma region INSERÇÃO DE VERTICES

	InserirVerticeGrafo(g, v1, &res);
	InserirVerticeGrafo(g, v2, &res);
	InserirVerticeGrafo(g, v3, &res);
	InserirVerticeGrafo(g, v4, &res);
	InserirVerticeGrafo(g, v5, &res);
	InserirVerticeGrafo(g, v6, &res);
	InserirVerticeGrafo(g, v7, &res);
	InserirVerticeGrafo(g, v8, &res);
	InserirVerticeGrafo(g, v9, &res);
	InserirVerticeGrafo(g, v10, &res);
	InserirVerticeGrafo(g, v11, &res);
	InserirVerticeGrafo(g, v12, &res);
	InserirVerticeGrafo(g, v13, &res);
	InserirVerticeGrafo(g, v14, &res);
	InserirVerticeGrafo(g, v15, &res);
	InserirVerticeGrafo(g, v16, &res);
	InserirVerticeGrafo(g, v17, &res);
	InserirVerticeGrafo(g, v18, &res);
	InserirVerticeGrafo(g, v19, &res);
	InserirVerticeGrafo(g, v20, &res);
	InserirVerticeGrafo(g, v21, &res);
	InserirVerticeGrafo(g, v22, &res);
	InserirVerticeGrafo(g, v23, &res);
	InserirVerticeGrafo(g, v24, &res);
	InserirVerticeGrafo(g, v25, &res);

#pragma endregion

#pragma region INSERÇÃO DE ADJACENTES

	// Primeira Linha
	InserirAdjGrafo(g, 1, 2, &res);
	InserirAdjGrafo(g, 2, 3, &res);
	InserirAdjGrafo(g, 3, 4, &res);
	InserirAdjGrafo(g, 4, 5, &res);
	// Segunda Linha
	InserirAdjGrafo(g, 6, 7, &res);
	InserirAdjGrafo(g, 7, 8, &res);
	InserirAdjGrafo(g, 8, 9, &res);
	InserirAdjGrafo(g, 9, 10, &res);
	// Terceira Linha
	InserirAdjGrafo(g, 11, 12, &res);
	InserirAdjGrafo(g, 12, 13, &res);
	InserirAdjGrafo(g, 13, 14, &res);
	InserirAdjGrafo(g, 14, 15, &res);
	// Quarta Linha
	InserirAdjGrafo(g, 16, 17, &res);
	InserirAdjGrafo(g, 17, 18, &res);
	InserirAdjGrafo(g, 18, 19, &res);
	InserirAdjGrafo(g, 19, 20, &res);
	// Quinta Linha
	InserirAdjGrafo(g, 21, 22, &res);
	InserirAdjGrafo(g, 22, 23, &res);
	InserirAdjGrafo(g, 23, 24, &res);
	InserirAdjGrafo(g, 24, 25, &res);

	// Primeira Coluna
	InserirAdjGrafo(g, 1, 6, &res);
	InserirAdjGrafo(g, 6, 11, &res);
	InserirAdjGrafo(g, 11, 16, &res);
	InserirAdjGrafo(g, 16, 21, &res);
	// Segunda Coluna
	InserirAdjGrafo(g, 2, 7, &res);
	InserirAdjGrafo(g, 7, 12, &res);
	InserirAdjGrafo(g, 12, 17, &res);
	InserirAdjGrafo(g, 17, 22, &res);
	// Terceira Coluna
	InserirAdjGrafo(g, 3, 8, &res);
	InserirAdjGrafo(g, 8, 13, &res);
	InserirAdjGrafo(g, 13, 18, &res);
	InserirAdjGrafo(g, 18, 23, &res);
	// Quarta Coluna
	InserirAdjGrafo(g, 4, 9, &res);
	InserirAdjGrafo(g, 9, 14, &res);
	InserirAdjGrafo(g, 14, 19, &res);
	InserirAdjGrafo(g, 19, 24, &res);
	// Quinta Coluna
	InserirAdjGrafo(g, 5, 10, &res);
	InserirAdjGrafo(g, 10, 15, &res);
	InserirAdjGrafo(g, 15, 20, &res);
	InserirAdjGrafo(g, 20, 25, &res);

#pragma endregion

	MostrarGrafo(g->inicioGrafo);
	printf("\nSoma do caminho: %d\n", CalcularSomaCaminho(g, 1, 8));
	printf("\n");
	MostrarSomaMaxima(g);
	printf("\n");
}