#include <vector>
#include <iostream>
#include <cstdbool>

using namespace std;

int V, E;
vector <int> adj_list[100];
int colored[1000], visit[1000];
bool flag = true;

void dfs(int u, int color) {

    visit[u] = 1;
    colored[u] = color;

    for (int i = 0; i < adj_list[u].size(); i++) {
        int v = adj_list[u][i];
      
      	// 방문 안한 경우 방문해서 색깔 칠해주기
        if (visit[v] == 0) {
            dfs(v, !color);
        }

      	// 방문 했는데 인접한 정점인데 색깔이 같으면 false
        else {
            if (color == colored[v])  {
                flag = false;
                return;
            }
        }
    }
}

void bipartitleVerify() {
  for (int i = 0; i < V; i++) {
      if (!visit[i]) dfs(i, 0);
  }
}

int main() {
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    bipartitleVerify();

    if (flag) cout << "2-colorbility" << endl;
    else cout << "Not bipartite" << endl;

    return 0;
}