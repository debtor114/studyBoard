#include <cstdio>
#include <tuple>
#include <vector>

using namespace std;

#define MAX 99999999

vector < tuple <int, int, int> > Edge; // 0: src  1: dst  2: weight

int V, E, start;
int d[501]; // distance
int p[501]; // parents node


bool BellmanFord() {
    // init
    for (int v = 1; v <= V; v++) {
        d[v] = MAX;
    } 
    
    // relaxation
    d[start] = 0;
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = get<0>(Edge[j]);
            int v = get<1>(Edge[j]);
            int w = get<2>(Edge[j]);
            
            if (d[u] != MAX && d[v] > d[u] + w) {
                d[v] = d[u] + w;
             	p[v] = u;   
            }    
        }
    }

    // check negative weighted cycle
    for (int i = 0; i < E; i++) {
         int u = get<0>(Edge[i]);
         int v = get<1>(Edge[i]);
         int w = get<2>(Edge[i]);

         if (d[v] > d[u] + w) 
            return false;
    }
    
    return true;
         
}

int main() {
    scanf("%d %d %d", &V, &E, &start);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        Edge.push_back(make_tuple(u, v, w));
    }

    if (BellmanFord()) {
        for (int i = 1; i <= V; i++) {
            if (d[i] == MAX) printf("d[%d]: INF\n", i);
            else printf("d[%d]: %d\n", i, d[i]);
        }
    }

    else printf("It contains negative weighted cycle\n");
    return 0;
}