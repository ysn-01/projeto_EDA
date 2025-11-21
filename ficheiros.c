/*********************************************************************
 * @file   ficheiros.c
 * @brief
 *
 * @author Yuri Nascimento
 * @email  a27957@alunos.ipca.pt
 * @date   May 2024
 *********************************************************************/
#include "header.h"

#pragma region FICHEIROS

#pragma region LerMatrizDeFicheiro

 //Grafo* LerMatrizDeFicheiro(char* nomeFicheiro, int* res) {
 //	*res = 1;
 //	FILE* fp = fopen(nomeFicheiro, "r");
 //	if (fp == NULL) return NULL;
 //	int linhas = 0;
 //	int colunas = 0;
 //	char buffer[1024];
 //	while (fgets(buffer, sizeof(buffer), fp)) {
 //		if (linhas = 0) {
 //			char* aux = strdup(buffer);
 //			char* token = strtok(aux, ";");
 //			while (aux != NULL) {
 //				colunas++;
 //				token = strtok(NULL, ";");
 //			}
 //			free(aux);
 //		}
 //		linhas++;
 //	}
 //	rewind(fp);
 //	Grafo* g = CriarGrafo(linhas);
 //	int idVertice = 0;
 //	while (fgets(buffer, sizeof(buffer), fp)) {
 //		Vertice* v = CriarVertice(idVertice++);
 //		int idAdj = 0;
 //		char* token = strtok(buffer, ";");
 //		while (token != NULL) {
 //			int valor = atoi(token);
 //			v->proxAdjacente = InserirAdjGrafo(v->proxAdjacente, idAdj++, valor, res);
 //		}
 //		g = InserirVerticeGrafo(g, v, res);
 //	}
 //	fclose(fp);
 //	return g;
 //}

#pragma endregion

#pragma endregion