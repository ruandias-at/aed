#include "Grafo.h"

Grafo::Grafo(const vector<vector<int>>& mat) {
    int n = mat.size();
    vertices.resize(n);
    for(int i = 0; i < n; i++) {
        vertices[i].vertice = 'A' + i;
        vertices[i].visitado = 0;
        vertices[i].flags = 0;
    }
    
    matriz = mat;
    TransformaMatrizEmLista();
}

Grafo::Grafo(const vector<Aresta>& novasArestas) {
    arestas = novasArestas;
    
    set<char> verticesUnicos;
    for(const auto& aresta : arestas) {
        verticesUnicos.insert(aresta.origem);
        verticesUnicos.insert(aresta.destino);
    }
    
    vertices.clear();
    for(char v : verticesUnicos) {
        Vertice novo;
        novo.vertice = v;
        novo.visitado = 0;
        novo.flags = 0;
        vertices.push_back(novo);
    }
    
    sort(vertices.begin(), vertices.end(), [](const Vertice& a, const Vertice& b) {
        return a.vertice < b.vertice;
    });
    
    TransformaListaEmMatriz();
}

void Grafo::TransformaMatrizEmLista() {
    arestas.clear();
    int n = matriz.size();
    
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(matriz[i][j] != 0) {
                Aresta nova;
                nova.origem = 'A' + i;
                nova.destino = 'A' + j;
                nova.peso = matriz[i][j];
                arestas.push_back(nova);
            }
        }
    }
}

void Grafo::TransformaListaEmMatriz() {
    int n = vertices.size();
    matriz.assign(n, vector<int>(n, 0));
    
    for(const auto& aresta : arestas) {
        int i = getIndiceVertice(aresta.origem);
        int j = getIndiceVertice(aresta.destino);
        if(i != -1 && j != -1) {
            matriz[i][j] = aresta.peso;
            matriz[j][i] = aresta.peso;
        }
    }
}

int Grafo::tamanhoGrafo() {
    return vertices.size();
}

int Grafo::cardinalidadeVertices() {
    return vertices.size();
}

int Grafo::cardinalidadeArestas() {
    return arestas.size();
}

int Grafo::grauVertice(char v) {
    int grau = 0;
    for(const auto& aresta : arestas) {
        if(aresta.origem == v || aresta.destino == v) {
            grau++;
        }
    }
    return grau;
}

int Grafo::diferencaCardinalidadesVA() {
    return cardinalidadeVertices() - cardinalidadeArestas();
}

vector<char> Grafo::CaminhoMaisCurto(char origem, char destino) {
    vector<int> dist = Dijkstra(origem);
    vector<char> caminho;
    
    int indiceDestino = getIndiceVertice(destino);
    if(indiceDestino == -1 || dist[indiceDestino] == numeric_limits<int>::max()) {
        return caminho;
    }
    
    vector<char> parent(vertices.size(), '\0');
    queue<char> q;
    resetVisitados();
    
    q.push(origem);
    vertices[getIndiceVertice(origem)].visitado = 1;
    
    while(!q.empty()) {
        char atual = q.front();
        q.pop();
        
        if(atual == destino) break;
        
        vector<char> adjacentes = getVerticesAdjacentes(atual);
        for(char adj : adjacentes) {
            int indiceAdj = getIndiceVertice(adj);
            if(vertices[indiceAdj].visitado == 0) {
                vertices[indiceAdj].visitado = 1;
                parent[indiceAdj] = atual;
                q.push(adj);
            }
        }
    }
    
    if(parent[getIndiceVertice(destino)] != '\0' || origem == destino) {
        char atual = destino;
        while(atual != '\0') {
            caminho.push_back(atual);
            atual = parent[getIndiceVertice(atual)];
        }
        reverse(caminho.begin(), caminho.end());
    }
    
    return caminho;
}

bool Grafo::ehConexo() {
    if(vertices.empty()) return true;
    
    resetVisitados();
    dfsUtil(vertices[0].vertice);
    
    for(const auto& v : vertices) {
        if(v.visitado == 0) return false;
    }
    return true;
}

bool Grafo::ehArvore() {
    return ehConexo() && cardinalidadeArestas() == cardinalidadeVertices() - 1;
}

bool Grafo::ehAnel() {
    return ehConexo() && cardinalidadeArestas() == cardinalidadeVertices();
}

bool Grafo::ehEstrela() {
    if(cardinalidadeVertices() < 3) return false;
    
    int verticesCentrales = 0;
    for(const auto& v : vertices) {
        int grau = grauVertice(v.vertice);
        if(grau == cardinalidadeVertices() - 1) {
            verticesCentrales++;
        } else if(grau != 1) {
            return false;
        }
    }
    return verticesCentrales == 1;
}

bool Grafo::ehTotalmenteConexo() {
    int n = cardinalidadeVertices();
    return cardinalidadeArestas() == (n * (n - 1)) / 2;
}

void Grafo::dfs(char inicio) {
    resetVisitados();
    dfsUtil(inicio);
}

void Grafo::bfs(char inicio) {
    resetVisitados();
    queue<char> q;
    
    int indiceInicio = getIndiceVertice(inicio);
    if(indiceInicio == -1) return;
    
    vertices[indiceInicio].visitado = 1;
    q.push(inicio);
    
    while(!q.empty()) {
        char atual = q.front();
        q.pop();
        
        vector<char> adjacentes = getVerticesAdjacentes(atual);
        for(char adj : adjacentes) {
            int indiceAdj = getIndiceVertice(adj);
            if(vertices[indiceAdj].visitado == 0) {
                vertices[indiceAdj].visitado = 1;
                q.push(adj);
            }
        }
    }
}

vector<int> Grafo::Dijkstra(char origem) {
    int n = vertices.size();
    vector<int> dist(n, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    int indiceOrigem = getIndiceVertice(origem);
    if(indiceOrigem == -1) return dist;
    
    dist[indiceOrigem] = 0;
    pq.push({0, indiceOrigem});
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for(int v = 0; v < n; v++) {
            if(matriz[u][v] != 0) {
                int peso = matriz[u][v];
                if(dist[u] + peso < dist[v]) {
                    dist[v] = dist[u] + peso;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    
    return dist;
}

vector<Aresta> Grafo::Prim() {
    vector<Aresta> mst;
    if(vertices.empty()) return mst;
    
    int n = vertices.size();
    vector<bool> inMST(n, false);
    vector<int> key(n, numeric_limits<int>::max());
    vector<int> parent(n, -1);
    
    key[0] = 0;
    
    for(int count = 0; count < n - 1; count++) {
        int u = -1;
        for(int v = 0; v < n; v++) {
            if(!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }
        
        inMST[u] = true;
        
        if(parent[u] != -1) {
            Aresta aresta;
            aresta.origem = vertices[parent[u]].vertice;
            aresta.destino = vertices[u].vertice;
            aresta.peso = matriz[parent[u]][u];
            mst.push_back(aresta);
        }
        
        for(int v = 0; v < n; v++) {
            if(matriz[u][v] != 0 && !inMST[v] && matriz[u][v] < key[v]) {
                parent[v] = u;
                key[v] = matriz[u][v];
            }
        }
    }
    
    return mst;
}

vector<Aresta> Grafo::Kruskal() {
    vector<Aresta> mst;
    vector<Aresta> arestasSorted = arestas;
    sort(arestasSorted.begin(), arestasSorted.end());
    
    int n = vertices.size();
    vector<int> parent(n);
    vector<int> rank(n, 0);
    
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    for(const auto& aresta : arestasSorted) {
        int u = getIndiceVertice(aresta.origem);
        int v = getIndiceVertice(aresta.destino);
        
        if(find(parent, u) != find(parent, v)) {
            mst.push_back(aresta);
            unionSets(parent, rank, u, v);
            if(mst.size() == n - 1) break;
        }
    }
    
    return mst;
}

vector<vector<int>> Grafo::BellmanFord(char origem) {
    int n = vertices.size();
    vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) dist[i][j] = 0;
            else if(matriz[i][j] != 0) dist[i][j] = matriz[i][j];
        }
    }
    
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] != numeric_limits<int>::max() && 
                   dist[k][j] != numeric_limits<int>::max() &&
                   dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    return dist;
}

int Grafo::getIndiceVertice(char v) {
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i].vertice == v) return i;
    }
    return -1;
}

void Grafo::resetVisitados() {
    for(auto& v : vertices) {
        v.visitado = 0;
    }
}

void Grafo::dfsUtil(char v) {
    int indice = getIndiceVertice(v);
    if(indice == -1) return;
    
    vertices[indice].visitado = 1;
    
    vector<char> adjacentes = getVerticesAdjacentes(v);
    for(char adj : adjacentes) {
        int indiceAdj = getIndiceVertice(adj);
        if(vertices[indiceAdj].visitado == 0) {
            dfsUtil(adj);
        }
    }
}

vector<char> Grafo::getVerticesAdjacentes(char v) {
    vector<char> adjacentes;
    for(const auto& aresta : arestas) {
        if(aresta.origem == v) {
            adjacentes.push_back(aresta.destino);
        } else if(aresta.destino == v) {
            adjacentes.push_back(aresta.origem);
        }
    }
    return adjacentes;
}

int Grafo::find(vector<int>& parent, int i) {
    if(parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void Grafo::unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    
    if(rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if(rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}