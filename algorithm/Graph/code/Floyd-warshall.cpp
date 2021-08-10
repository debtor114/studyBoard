#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
 
#define INF 9238749845722243
 
using namespace std;

long long d[101][101];
int V, E;
 

void floyd() {    
    // k = 중간정점
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                //if (i == k || j == k) continue;
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}

 
int main() {

    //init 

    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            d[i][j] = INF;
        }
    }
 
    for (int i = 1; i <= V; i++) 
        d[i][i] = 0;


    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (d[u][v] > w) d[u][v] = w;
    }


    floyd();

    // print distance
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (d[i][j] == INF) printf("0 ");
            else printf("%lld ", d[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}

