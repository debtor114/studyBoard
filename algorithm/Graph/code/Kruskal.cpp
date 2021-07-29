#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple> 		// c++ 17 

using namespace std;

int parent[1000];
vector < tuple <int, int, int> > Edge;

int V, E;

int getRoot(int x) {  
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void unionSet(int a, int b) { 
    int x = getRoot(a);
    int y = getRoot(b);

    if(x < y) parent[y] = x;
    else parent[x] = y;
}

bool find(int a, int b) { 
    int x = getRoot(a);
    int y = getRoot(b);
    if(x == y) return true;
    else return false;
}

int main() {	
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        Edge.push_back(make_tuple(w, u, v));
    }

	sort(Edge.begin(), Edge.end());


    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int cost = 0;
    for (int i = 0; i < Edge.size(); i++) {
        int u, v , w;
        u = get<1>(Edge[i]);
        v = get<2>(Edge[i]);
        w = get<0>(Edge[i]);
        if (!find(u, v)) {
            unionSet(u, v);
            cost += w;
        }
    }

    cout << cost << endl;
    
    return 0;
}