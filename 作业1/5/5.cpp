#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    int a[10][10];
    int log[10];
    int count;

    Graph() {
        memset(a, 0, sizeof(a));
        memset(log, 0, sizeof(log));
        count = 0;
    }

    void addEdge(int u, int v);
    void bfs(int start) ;
};

void Graph::addEdge(int u, int v) {
    if (u >= 0 && u < 10 && v >= 0 && v < 10) {
        a[u][v] = 1;
        a[v][u] = 1;
        if (u + 1 > count) count = u + 1;
        if (v + 1 > count) count = v + 1;
    }
}
void Graph::bfs(int start) {
    memset(log, 0, sizeof(log));

    queue<int> q;
    q.push(start);
    log[start] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < count; i++) {
            if (a[node][i] == 1 && !log[i]) {
                log[i] = 1;
                q.push(i);
            }
        }
    }
    cout << endl;
}




int main() {
    Graph g;
    int u, v;
    while (true) {
        cin >> u >> v;
        if (u == 0 && v == 0) break; 
        g.addEdge(u, v);
    }
    g.bfs(0);
    return 0;
}