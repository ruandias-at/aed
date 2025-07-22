#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <set>

using namespace std;

struct Vertice {
    char vertice;
    int visitado = 0;
    int flags = 0;
};

struct Aresta {
    char origem;
    char destino;
    int peso;
    bool operator<(const Aresta &a) const { return peso < a.peso; }
};

class Grafo {
public:
    bool direcionado = false;
    bool conexo = false;
    
    vector<Vertice> vertices;
    vector<Aresta> arestas;
    vector<vector<int>> matriz;

    Grafo(const vector<vector<int>>& mat);
    Grafo(const vector<Aresta>& novasArestas);
    
    void TransformaMatrizEmLista();
    void TransformaListaEmMatriz();
    
    int tamanhoGrafo();
    int cardinalidadeVertices();
    int cardinalidadeArestas();
    int grauVertice(char v);
    int diferencaCardinalidadesVA();
    
    vector<char> CaminhoMaisCurto(char origem, char destino);
    bool ehConexo();
    bool ehArvore();
    bool ehAnel();
    bool ehEstrela();
    bool ehTotalmenteConexo();
    
    void dfs(char inicio);
    void bfs(char inicio);
    
    vector<int> Dijkstra(char origem);
    vector<Aresta> Prim();
    vector<Aresta> Kruskal();
    vector<vector<int>> BellmanFord(char origem);
    
private:
    int getIndiceVertice(char v);
    void resetVisitados();
    void dfsUtil(char v);
    bool temCiclo();
    vector<char> getVerticesAdjacentes(char v);
    int find(vector<int>& parent, int i);
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y);
};

#endif