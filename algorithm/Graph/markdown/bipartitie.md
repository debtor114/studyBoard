## 이분그래프 (Bipartite)

인접한 정점끼리 서로 다른 색으로 칠해서 모든 정점을 두 가지 색으로만 칠할 수 있는 그래프.



![image-20210727152121023](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210727152121023.png?raw=true)



#### 설계: Two-colorability

i. BFS, DFS로 탐색하면서 정점을 방문할 때마다 두 가지 색 중 하나를 칠한다.

ii. 다음 정점을 방문하면서 자신과 인접한 정점은 자신과 다른 색으로 칠한다.

iii. 탐색을 진행할 때 자신과 인접한 정점의 색이 자신과 동일하면 이분 그래프가 아니다.

모든 정점을 다 방문했는데 위와 같은 경우가 없다면 이분 그래프이다.




#### 시간복잡도: $ O(V + E) $



#### 코드

```c++
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
```

