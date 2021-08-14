// 사이클이 2개이상 있으면 왜 멈출까
// 단방향그래프만 된다.

#include <stack>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int V, E;
int visit[100], p[100];
int isCycle = 0;

stack <int> s;
vector <int> adj_list[100];

bool hasSelfLoop() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj_list[i].size(); j++) {
            if (adj_list[i][j] == i) return true;
        }
    }

    return false;
}


void cycleDFS(int u, int parent) {

    // grey
    visit[u] = 1;

    p[u] = parent;
    for (int i = 0; i < adj_list[u].size(); i++) {
        int v = adj_list[u][i];

        if (!visit[v]) {
            cycleDFS(v, u);
        }
        
        else if (visit[v] == 1) { 
            while (u != v) {
                s.push(u);
                u = p[u];
            }
            s.push(v);

            isCycle = 1;
        }
    }

    // black
    visit[u] = 2;
}



void hasCycle() {

  if (hasSelfLoop()) {
      isCycle = 2;
      return;
  }
  

for (int v = 0; v < V; v++) {
    if (!visit[v]) 
        cycleDFS(v, v);
  }

}



int main() {

    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        //adj_list[v].push_back(u);
    }

    hasCycle();

    if (isCycle == 1) {
        printf("There is a cycle: ");
        while (!s.empty()) {
            printf("%d ", s.top());
            s.pop();
        }
        printf("\n");
    }

    else if (isCycle == 2) printf("It has self-root cycle\n");
    
    else printf("This graph is acyclic. \n");


    
    return 0;
}