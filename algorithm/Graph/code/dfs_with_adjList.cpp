#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

bool visited[100];
vector <int> adj_list[100];

int d[100], f[100];
int E, V;
int t = 0;

void DFS(int);
void DFS_VISIT(int);

void DFS(int start) {
    for (int u = 0; u < V; u++) {
        if (visited[u] == false)
            DFS_VISIT(u);
    }
}

void DFS_VISIT(int u) {

    visited[u] = true;
    t++;
    d[u] = t;
    printf("d[%d] = %d\n", u, d[u]);
    
    for (int i = 0; i < adj_list[u].size(); i++) {
        int v = adj_list[u][i];
        if (visited[v] == false) {
            DFS_VISIT(v);
        }
    }
    
    t++;
    f[u] = t;
    printf("f[%d] = %d\n", u, f[u]);
}

int main() {
    scanf("%d %d", &E, &V);
    for (int i = 0; i < E; i++) {
        int src, dst;
        scanf("%d %d", &src, &dst);
        adj_list[src].push_back(dst);
        adj_list[dst].push_back(src);
    }

    // check adj_list
    for (int i = 0; i < V; i++) {
        printf("v[%d]: ", i);
        for (int j = 0; j < adj_list[i].size(); j++) {
           printf("%d ", adj_list[i][j]);
        }
        printf("\n");
    }

    // src = 0, run DFS
    DFS(0);
    return 0;


}