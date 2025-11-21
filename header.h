/*********************************************************************
 * @file   header.h
 * @brief
 *
 * @author Yuri Nascimento
 * @email  a27957@alunos.ipca.pt
 * @date   May 2024
 *********************************************************************/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "assert.h"
#define MAX_VERTICES 25
#pragma warning(disable:4996)

 // Estrutura de dados para representar uma aresta adjacente a um vértice
typedef struct Adjacente {
	int id; // Identificador do vértice adjacente
	int valor; // Valor associado à adjacência
	int peso; // Peso associado à adjacência
	struct Adjacente* proximo; // Apontador para o próximo vértice adjacente
} Adjacente;

// Estrutura de dados para representar um vértice em um grafo
typedef struct Vertice {
	int id; // Identificador único do vértice
	int valor; // Valor associado ao vértice
	bool visitado; // Flag para marcar se o vértice foi visitado durante a busca
	Adjacente* proxAdjacente; // Apontador para a lista de vértices adjacentes
	struct Vertice* proxVertice; // Apontador para o próximo vértice no grafo
} Vertice;

// Estrutura de dados para representar um grafo
typedef struct Grafo {
	Vertice* inicioGrafo; // Apontador para o início do grafo
	int numVertices; // Número atual de vértices no grafo
	int totVertices; // Número total de vértices permitidos no grafo
} Grafo;

// Estrutura de dados para representar o resultado de uma operação no grafo
typedef struct Resultado {
	int soma; // Soma dos valores do caminho ou resultado da operação
	Vertice* caminho; // Apontador para o vértice que representa o caminho ou o resultado
	Grafo* grafo; // Apontador para o grafo associado ao resultado
} Resultado;

// Vertices
Vertice* CriarVertice(int id, int valor);
bool ExisteVertice(Vertice* inicio, int idVertice);
Vertice* InserirVertice(Vertice* vertices, Vertice* novoVertice, bool* res);
Vertice* EliminarVertice(Vertice* vertices, int idVertice, bool* res);
Vertice* ObterVertice(Vertice* inicio, int idVertice);
void DestruirVertice(Vertice* v);
void MostrarGrafo(Vertice* grafo);

// Adjacencias
Adjacente* CriarAdjacente(int id, int valor, int peso);
Adjacente* EliminarAdjacente(Adjacente* listaAdj, int idAdj, bool* res);
Adjacente* EliminaTodosAdjacentes(Adjacente* listaAdj, bool* res);
Vertice* EliminarAdjTodosVertices(Vertice* vertices, int idVertice, bool* res);
Adjacente* InserirAdjacente(Adjacente* listaAdj, int idDestino, int valor, int peso);
void DestruirAdjacente(Adjacente* adj);

// Grafo
void MostrarGrafoLA(Grafo* g);
Grafo* InserirVerticeGrafo(Grafo* g, Vertice* v, int* res);
Grafo* EliminarVerticeGrafo(Grafo* g, int idVertice, bool* res);
Grafo* EliminarAdjGrafo(Grafo* g, int idOrigem, int idDestino, bool* res);
Vertice* OndeEstaVerticeGrafo(Grafo* g, int idVertice);
Grafo* InserirAdjGrafo(Grafo* g, int idOrigem, int idDestino, bool* res);
Grafo* CriarGrafo(int tot);
bool ExisteVerticeGrafo(Grafo* g, int idVertice);


// Caminhos
bool BuscarProfundidade(Vertice* v, int idDestino, bool* visitado, int* soma, Grafo* g);
int CalcularSomaCaminho(Grafo* g, int idOrigem, int idDestino);

// Soma
int AtualizarResultado(Resultado* res, int somaAtual, Vertice* caminhoAtual);
int BuscarCaminhoMaximo(Vertice* v, int somaAtual, Resultado* res);
Resultado* CaminhoSomaMaxima(Grafo* g);
void MostrarSomaMaxima(Grafo* grafo);

// Ficheiros
//Grafo* LerMatrizDeFicheiro(const char* filename, int* res);