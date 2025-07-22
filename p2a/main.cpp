#include "Grafo.h"

int main() {
    cout << "=== QUESTAO A: ===" << endl;
    
    vector<vector<int>> matriz = {
        //A  B  C  D  E  F
        { 0, 1, 5, 0, 0, 10},  // A
        { 1, 0, 6, 13, 0, 0},   // B
        { 5, 6, 0, 15, 7, 0},  // C  
        { 0, 13, 15, 0, 3, 0}, // D
        { 0, 0, 7, 3, 0, 9},   // E
        {10, 0, 0, 0, 9, 0}   // F
    };
    
    Grafo g1(matriz);
    
    cout << "Tamanho do grafo: " << g1.tamanhoGrafo() << endl;
    cout << "Cardinalidade de vertices: " << g1.cardinalidadeVertices() << endl;
    cout << "Cardinalidade de arestas: " << g1.cardinalidadeArestas() << endl;
    cout << "Grau do vertice 'C': " << g1.grauVertice('C') << endl;
    cout << "Diferenca V-A: " << g1.diferencaCardinalidadesVA() << endl;
    cout << "Eh conexo: " << (g1.ehConexo() ? "Sim" : "Nao") << endl;
    cout << "Eh arvore: " << (g1.ehArvore() ? "Sim" : "Nao") << endl;
    cout << "Eh anel: " << (g1.ehAnel() ? "Sim" : "Nao") << endl;
    cout << "Eh estrela: " << (g1.ehEstrela() ? "Sim" : "Nao") << endl;
    cout << "Eh totalmente conexo: " << (g1.ehTotalmenteConexo() ? "Sim" : "Nao") << endl;
    
    
    cout << "--- Algoritmo de Dijkstra (origem A) ---" << endl;
    vector<int> distancias = g1.Dijkstra('A');
    for(int i = 0; i < distancias.size(); i++) {
        char vertice = 'A' + i;
        cout << "Distancia de A para " << vertice << ": ";
        if(distancias[i] == numeric_limits<int>::max()) {
            cout << "infinito" << endl;
        } else {
            cout << distancias[i] << endl;
        }
    }
    
    cout << "--- Arvore Geradora Minima (Prim) ---" << endl;
    vector<Aresta> mstPrim = g1.Prim();
    int pesoTotalPrim = 0;
    for(const auto& aresta : mstPrim) {
        cout << aresta.origem << " - " << aresta.destino << " (peso: " << aresta.peso << ")" << endl;
        pesoTotalPrim += aresta.peso;
    }
    cout << "Peso total da MST (Prim): " << pesoTotalPrim << endl;
    
    cout << "--- Arvore Geradora Minima (Kruskal) ---" << endl;
    vector<Aresta> mstKruskal = g1.Kruskal();
    int pesoTotalKruskal = 0;
    for(const auto& aresta : mstKruskal) {
        cout << aresta.origem << " - " << aresta.destino << " (peso: " << aresta.peso << ")" << endl;
        pesoTotalKruskal += aresta.peso;
    }
    cout << "Peso total da MST (Kruskal): " << pesoTotalKruskal << endl;
    


    cout << "\n=== QUESTAO B: ===" << endl;
    
    vector<Aresta> arestas = {
        {'A', 'B', 10},
        {'B', 'C', 15},
        {'B', 'E', 20},
        {'B', 'F', 5},
        {'C', 'D', 25},
        {'C', 'G', 13},
        {'D', 'H', 22},
        {'E', 'F', 7},
        {'F', 'G', 9},
        {'G', 'H', 18}
    };
    
    Grafo g2(arestas); 
    
    cout << "Tamanho do grafo: " << g2.tamanhoGrafo() << endl;
    cout << "Cardinalidade de vertices: " << g2.cardinalidadeVertices() << endl;
    cout << "Cardinalidade de arestas: " << g2.cardinalidadeArestas() << endl;
    cout << "Grau do vertice 'C': " << g2.grauVertice('C') << endl;
    cout << "Diferenca V-A: " << g2.diferencaCardinalidadesVA() << endl;
    cout << "Eh conexo: " << (g2.ehConexo() ? "Sim" : "Nao") << endl;
    cout << "Eh arvore: " << (g2.ehArvore() ? "Sim" : "Nao") << endl;
    cout << "Eh anel: " << (g2.ehAnel() ? "Sim" : "Nao") << endl;
    cout << "Eh estrela: " << (g2.ehEstrela() ? "Sim" : "Nao") << endl;
    cout << "Eh totalmente conexo: " << (g2.ehTotalmenteConexo() ? "Sim" : "Nao") << endl;
    
    
    cout << "--- Algoritmo de Dijkstra (origem A) ---" << endl;
    vector<int> distancias2 = g2.Dijkstra('A');
    for(int i = 0; i < distancias2.size(); i++) {
        char vertice = 'A' + i;
        cout << "Distancia de A para " << vertice << ": ";
        if(distancias2[i] == numeric_limits<int>::max()) {
            cout << "infinito" << endl;
        } else {
            cout << distancias2[i] << endl;
        }
    }
    
    cout << "--- Arvore Geradora Minima (Prim) ---" << endl;
    vector<Aresta> mstPrim2 = g2.Prim();
    int pesoTotalPrim2 = 0;
    for(const auto& aresta : mstPrim2) {
        cout << aresta.origem << " - " << aresta.destino << " (peso: " << aresta.peso << ")" << endl;
        pesoTotalPrim2 += aresta.peso;
    }
    cout << "Peso total da MST (Prim): " << pesoTotalPrim2 << endl;
    
    cout << "--- Arvore Geradora Minima (Kruskal) ---" << endl;
    vector<Aresta> mstKruskal2 = g2.Kruskal();
    int pesoTotalKruskal2 = 0;
    for(const auto& aresta : mstKruskal2) {
        cout << aresta.origem << " - " << aresta.destino << " (peso: " << aresta.peso << ")" << endl;
        pesoTotalKruskal2 += aresta.peso;
    }
    cout << "Peso total da MST (Kruskal): " << pesoTotalKruskal2 << endl;
    
    return 0;
}