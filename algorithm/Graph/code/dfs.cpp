#include <cstdio>
#include <vector>

using namespace std;

vector <int> adj_list[100];
vector <int> traversal_order;
int visit[1000], d[1000], f[1000];
int t = 0;

void dfs (int);
void dfs_all(int);

void dfs_all(int V) {
    for (int i = 0; i < V; i++) {
        if (visit[i] == 0) dfs(i);
    }
}

void dfs(int start) {
    t++;
    d[start] = t;
    visit[start] = 1;

    traversal_order.push_back(start);
    for (int i = 0; i < adj_list[start].size(); i++) {
        int v = adj_list[start][i];
        if (visit[v] == 0) {
            dfs(v);
        }
    }

    t++;
    f[start] = t;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj_list[u].push_back(v);
    }

    dfs_all(V);

    for (int i = 0; i < traversal_order.size(); i++) {
        printf("%d ", traversal_order[i]);
    }

    return 0;

}
