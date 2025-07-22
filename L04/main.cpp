#include "Grafo.h"

int main() {
    cout << "=== QUESTÃO 1: Grafo construído por matriz ===" << endl;
    
    vector<vector<int>> matriz = {
        {0, 5, 0, 8, 0},
        {5, 0, 3, 0, 4},
        {0, 3, 0, 2, 6},
        {8, 0, 2, 0, 7},
        {0, 4, 6, 7, 0}
    };
    
    Grafo g1(matriz);
    
    cout << "Tamanho do grafo: " << g1.tamanhoGrafo() << endl;
    cout << "Cardinalidade de vértices: " << g1.cardinalidadeVertices() << endl;
    cout << "Cardinalidade de arestas: " << g1.cardinalidadeArestas() << endl;
    cout << "Diferença V-A: " << g1.diferencaCardinalidadesVA() << endl;
    cout << "É conexo: " << (g1.ehConexo() ? "Sim" : "Não") << endl;
    cout << "É árvore: " << (g1.ehArvore() ? "Sim" : "Não") << endl;
    cout << "É anel: " << (g1.ehAnel() ? "Sim" : "Não") << endl;
    cout << "É estrela: " << (g1.ehEstrela() ? "Sim" : "Não") << endl;
    cout << "É totalmente conexo: " << (g1.ehTotalmenteConexo() ? "Sim" : "Não") << endl;
    
    cout << "\n--- Problema de origem-destino (A -> D) ---" << endl;
    vector<char> caminho = g1.CaminhoMaisCurto('A', 'D');
    if(!caminho.empty()) {
        cout << "Caminho mais curto de A para D: ";
        for(int i = 0; i < caminho.size(); i++) {
            cout << caminho[i];
            if(i < caminho.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "Não há caminho de A para D" << endl;
    }
    
    cout << "\n--- Algoritmo de Dijkstra (origem A) ---" << endl;
    vector<int> distancias = g1.Dijkstra('A');
    for(int i = 0; i < distancias.size(); i++) {
        char vertice = 'A' + i;
        cout << "Distância de A para " << vertice << ": ";
        if(distancias[i] == numeric_limits<int>::max()) {
            cout << "infinito" << endl;
        } else {
            cout << distancias[i] << endl;
        }
    }
    
    cout << "\n--- Árvore Geradora Mínima (Prim) ---" << endl;
    vector<Aresta> mstPrim = g1.Prim();
    int pesoTotalPrim = 0;
    for(const auto& aresta : mstPrim) {
        cout << aresta.origem << " - " << aresta.destino << " (peso: " << aresta.peso << ")" << endl;
        pesoTotalPrim += aresta.peso;
    }
    cout << "Peso total da MST (Prim): " << pesoTotalPrim << endl;
    
    cout << "\n--- Árvore Geradora Mínima (Kruskal) ---" << endl;
    vector<Aresta> mstKruskal = g1.Kruskal();
    int pesoTotalKruskal = 0;
    for(const auto& aresta : mstKruskal) {
        cout << aresta.origem << " - " << aresta.destino << " (peso: " << aresta.peso << ")" << endl;
        pesoTotalKruskal += aresta.peso;
    }
    cout << "Peso total da MST (Kruskal): " << pesoTotalKruskal << endl;
    
    cout << "\n\n=== EXEMPLO 2: Grafo construído por lista de arestas ===" << endl;
    
    vector<Aresta> arestas = {
        {'X', 'Y', 10},
        {'Y', 'Z', 15},
        {'X', 'Z', 20},
        {'X', 'W', 5},
        {'W', 'Z', 25}
    };
    
    Grafo g2(arestas);
    
    cout << "Tamanho do grafo: " << g2.tamanhoGrafo() << endl;
    cout << "Cardinalidade de vértices: " << g2.cardinalidadeVertices() << endl;
    cout << "Cardinalidade de arestas: " << g2.cardinalidadeArestas() << endl;
    cout << "É conexo: " << (g2.ehConexo() ? "Sim" : "Não") << endl;
    cout << "É árvore: " << (g2.ehArvore() ? "Sim" : "Não") << endl;
    cout << "É anel: " << (g2.ehAnel() ? "Sim" : "Não") << endl;
    
    cout << "\n--- Problema de única origem (X para todos) ---" << endl;
    vector<int> distanciasX = g2.Dijkstra('X');
    vector<char> verticesG2 = {'W', 'X', 'Y', 'Z'};
    for(int i = 0; i < verticesG2.size(); i++) {
        char vertice = verticesG2[i];
        int idx = -1;
        for(int j = 0; j < g2.vertices.size(); j++) {
            if(g2.vertices[j].vertice == vertice) {
                idx = j;
                break;
            }
        }
        if(idx != -1) {
            cout << "Distância de X para " << vertice << ": ";
            if(distanciasX[idx] == numeric_limits<int>::max()) {
                cout << "infinito" << endl;
            } else {
                cout << distanciasX[idx] << endl;
            }
        }
    }
    
    cout << "\n--- Problema de todos os pares (Floyd-Warshall) ---" << endl;
    vector<vector<int>> todasDistancias = g2.BellmanFord('X');
    for(int i = 0; i < g2.vertices.size(); i++) {
        for(int j = 0; j < g2.vertices.size(); j++) {
            cout << "Distância de " << g2.vertices[i].vertice << " para " << g2.vertices[j].vertice << ": ";
            if(todasDistancias[i][j] == numeric_limits<int>::max()) {
                cout << "infinito" << endl;
            } else {
                cout << todasDistancias[i][j] << endl;
            }
        }
    }
    
    cout << "\n--- Árvore Geradora (Problema 5) ---" << endl;
    vector<Aresta> mstG2 = g2.Prim();
    int pesoTotalG2 = 0;
    for(const auto& aresta : mstG2) {
        cout << aresta.origem << " - " << aresta.destino << " (peso: " << aresta.peso << ")" << endl;
        pesoTotalG2 += aresta.peso;
    }
    cout << "Peso total da árvore geradora: " << pesoTotalG2 << endl;
    
    return 0;
}