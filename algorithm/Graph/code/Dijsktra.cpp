#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <stack>

using namespace std;

#define PAIR pair<int, int>

int d[1000], p[1000];

vector <PAIR> adj_list[1000];


void dijsktra(int V, int E, int start) {

    for (int i = 1; i <= V; i++) {
        d[i] = 9999999;
        p[i] = -1;
    }

    d[start] = 0;
    p[start] = 0;

    set <int> S;
    priority_queue <PAIR, vector<PAIR>, greater<PAIR> > Q;

    for (int i = 1; i <= V; i++) {
        Q.push(make_pair(d[i], i)); 
    }

    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        S.insert(u);
    
        for (int i = 0; i < adj_list[u].size(); i++) {
            int v = adj_list[u][i].first;
            int w = adj_list[u][i].second;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
                Q.push(make_pair(d[v], v));
            }
        }
    }
}

int main() {
    int V, E, src, dest;
    cin >> V >> E >> src >> dest;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj_list[u].push_back(make_pair(v, w));
    }

    dijsktra(V, E, src);

    // 각 정점까지의 최단거리
    for (int i = 1; i <= V; i++) {
        cout << "d[" << i << "]: " << d[i] << endl;
    }

    // 최단경로 출력
    stack <int> sp;
    while (1) {
        sp.push(dest);
        dest = p[dest];
        if (dest == 0) break;
    }

    cout << "shortest path: ";
    while (!sp.empty()) {
        cout << sp.top() << " ";
        sp.pop();
    }

    return 0;
  
}