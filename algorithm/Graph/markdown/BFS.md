# 그래프 탐색

그래프 탐색은 크게 두가지 방법이 있다. 

![Introduction of DFS, BFS.gif](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/image/Introduction%20of%20DFS,%20BFS.gif?raw=true)



## BFS (Breadth-First Search, 너비우선탐색)

**개요**

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/image/BFS_intro.png?raw=true" alt="Introduction of DFS, BFS.gif" style="zoom:67%;" />

한 시작 정점을 정해서 인접한 정점부터 모두 탐색하는 방식이다.



**설계 모델**

- 정의
  - Discover: 정점을 처음 방문한다.
  - Explore: 간선을 처음 이용한다.



- 정점의 구분
  - White: discover되지 않은 상태 즉, 처음에 모든 정점은 white 상태이다.

  - <span style="color:gray">Gray</span>: discover는 되었지만 정점에 대해서 탐색이 끝나지 않은 상태

    = Gray 정점의 인접 정점들 중 최소 한개는 white 정점인 상태

  - <span style="color:Black">Black</span>: discover되고 해당 정점에 대해 모든 탐색이 끝난 상태

    = Black 정점의 인접 정점들은 모두 Gray 혹은 Black 상태일 것이다.



- 정점의 색깔과 BFS의 동작 과정을 상응시키면 아래와 같다.

  1. white인 정점 하나를 선택해 <span style="color:gray">Gray</span>로 색칠한다.

  2. 그 정점의 모든 white neighbor를 discover한다.

  3. 모든 인접 정점이 discover되면 선택한 <span style="color:gray">Gray</span>를 <span style="color:Black">Black</span>으로 색칠한다.

     cf> 인접 정점에 대한 정보는 adjacency list(인접 리스트)에서 얻을 수 있다.



**의사 코드**

```c++
BFS(G, s) // s: source vertex

	// 시작하는 정점을 제외한 모든 정점에 대해서
	// 각각의 모든 정점에 대해서 거리를 무한대로 두고 parent 정점을 비워둔다.
	for each vertex u : V-{s} {		
		d[u] = INF;
		p[u] = NULL;			//p[u]: u의 parent 정점
	}

	// init, 시작하는 정점을 선택했으므로 GRAY로 칠해주고,
	// 자기자신 까지의 거리는 0
	// 부모 정점은 없다.
	color[s] = GRAY;
	d[s] = 0;
	p[s] = NULL;
	queue Q; // BFS의 queue는 생성하고 비워둔다.

	// 시작 정점 s를 큐에 넣고 인접정점들을 탐색한다.
	ENQUEUE(Q, s)
        
    // 큐가 빌 때 까지 반복
    while (!Q.empty()) {
        
        // 큐에 있던 정점을 pop해온 것이 u라고 하자 (첫 번째 반복에는 시작정점 s가 되겠지?)
        // 첫 번째 반복은 u가 s라고 생각하고 흐름을 따라가보자.
        u = Q.pop();
        
        // 정점 u의 모든 인접정점에 대해서 반복한다.
        for each v : Adj[u] {     
            // 만약 인접정점 v가 WHITE이면 
            // GRAY로 칠하고
            // d[u]에서의 거리보다 1이 클 것이며
            // v의 부모는 u가 될 것이다.
            // 그리고 인접정점 v를 큐에 넣어준다.
            if (color[v] == WHITE) {
                color[v] = GRAY;
                d[v] = d[u] + 1;
                p[v] = u;
                ENQUEUE(Q, v);
            }
        }
        // u의 모든 인접정점에 대한 탐색이 끝나면 u를 BLACK으로 칠한다.
        color[u] = BLACK;
    }
```



**동작 과정**

![BFS.gif](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/image/BFS.gif?raw=true)



**시간복잡도**

- 모든 정점을 큐에 한번씩 넣어야 한다. (WHITE -> GRAY): O(V)
- 모든 정점을 큐에서 한번씩 빼야 한다. (GRAY -> BLACK): O(V)
- 모든 정점의 인접리스트를 한번식 스캔해야 한다. : O(E)

  => 시간복잡도: O (V+E)



**C++ 코드 (흐름을 따라가며 코드를 작성해보세요, 외우기 힘들다면 의사코드를 보면서 코드를 작성해 보세요.)**

```c++
// 위에서는 정점의 색깔로 표시했지만 컴퓨터는 그럴 수 없기에 bool visit[] 배열을 사용한다.
// visit[x] = false 이면 WHITE, true이면 GRAY or BLACK 이다.
// 아래는 인접 리스트 일 때의 구현입니다. 인접 행렬 일 때의 구현도 작성해보세요!

#include <queue>
#include <vector>

using namespcae std;

bool visit[100];
vector <int> adj_list[100];
int d[100], p[100];

void bfs (int start) { 
    // init
    queue <int> bfs_queue; 
    bfs_queue.push(start); 
    visit[start] = true; 
    d[start] = 0;		// 최단거리 찾을 때
    p[start] = -1;		// 최단거리 경로 구성 할 때
    
    while(!q.empty()){ 
        int u = q.front(); 
        q.pop(); 
        
        // printf("%d ", u);    // 방문 순서를 출력해준다.
        for(int i = 0; i < adj_list[u].size(); i++) {
            int v = adj_list[u][i]; 
            if(!visit[v]) { 
                bfs_queue.push(v); 
                visit[v] = true;
                d[v] = d[u] + 1;
                p[v] = u
            } 
        } 
    } 
}
```







## DFS (Depth-First Search)

**개요**

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/image/DFS_intro.png?raw=true" alt="Introduction of DFS, BFS.gif" style="zoom:67%;" />

**설계 모델**

BFS와 같이 색깔로 정점의 상태를 구별해 보자.

- White: discover되지 않은 상태 즉, 처음에 모든 정점은 white 상태이다.

- <span style="color:gray">Gray</span>: discover는 되었지만 정점에 대해서 탐색이 끝나지 않은 상태

  = <span style="color:gray">Gray</span> 정점의 인접 정점들 중 최소 한개는 white 정점인 상태

- <span style="color:Black">Black</span>: discover되고 해당 정점에 대해 모든 탐색이 끝난 상태

  = <span style="color:Black">Black</span> 정점의 인접 정점들은 모두 <span style="color:gray">Gray</span> 혹은 <span style="color:Black">Black</span> 상태일 것이다.



DFS에서 Gray 정점은 약간 BFS와 다른데, 각 Gray 정점에서 2개의 타임스탬프를 가진다.

- d[v]: 정점 v의 discovery time

- f[v]: 정점 v의 finish time (방문할 수 있는 모든 정점을 방문한 상태, 추후에 무슨 의미인지 알게 됨)

  *Principle*

  1. <img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/image/principle1.png?raw=true" alt="principle1" style="zoom:50%;" />: discover time이 항상 finish time보다 작은 것은 자명하다.
  2. <img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/image/principle2.png?raw=true" alt="principle2" style="zoom:50%;" />: 한 정점에 대해서 왔다갔다 두번하므로 finish time의 최댓값은 2|V|

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/image/d[v], f[v].png?raw=true" alt="principle1"/>





**의사 코드**

```c++
DFS (V, E)
  // 모든 정점을 WHITE로 초기화
  for each u : V
    color[u] = WHITE;

	// 시작시간을 0으로 초기화
	int time = 0;

	// 모든 정점에 대해서 DFS 탐색
	for each u : V {
    if (color[u] == WHITE)
      DFS-VISIT(u);
  }
```



```c++
DFS-VISIT(u)
  
  // 선택된 u 정점을 GRAY로 색칠하고
  // 방문했으니 시간을 1 올려주고 d[u]를 설정한다.
  color[u] = GRAY;
	time++;
	d[u] = time;
	
	// u의 모든 인접정점에 대해서 DFS 탐색을 시작한다.
	// recursive 형태이기 때문에 계속 스택이 쌓이면서 깊게 들어가게 된다.
	for each v : Adj[u] {
    if (color[v] == WHITE)
      DFS-VISIT(v);
  }

	// 정점 u의 모든 인접정접에 대해서 DFS 탐색을 마치면 정점 u를 BLACK으로 칠해준다.
  // 다시 정점 u로 돌아왔으므로 시간을 1 올려주고 f[u]를 설정한다.
	color[u] = BLACK;
	time++;
	f[u] = time;
```



**동작 과정 (각 프레임마다 3초씩 걸리니 머릿속으로 다음 그림을 예상해 보세요!)**

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/image/DFS.gif?raw=true" alt="principle1" style="zoom:150%;" />



**시간복잡도**

- DFS(G)에서 모든 정점을 WHITE로 초기화 하는 비용: O(V)

```c++
DFS (G)
 for each vertex u = V[G]
   color[u] = WHITE;

...
...
...
```



- DFS(G)에서 모든 정점에 대해 DFS-VISIT를 탐색하는 비용: O(V)

```c++
 for each vertex u = V[G]
   if (color[u] = WHITE)
     DFS-VISIT(u);
```



- DFS-VISIT에서 정점 u의 모든 인접정점 v = Adj[u]에 대해 DFS-VISIT 탐색하는 비용: O(E)

```c++
DFS-VISIT
  for each v = Adj[u]
    if (color[v] = WHITE)
      DFS-VISIT(v);
```

=> 총 시간복잡도: O(V+E)





**C++ 코드 (흐름을 따라가며 코드를 작성해보세요, 외우기 힘들다면 의사코드를 보면서 코드를 작성해 보세요.)**

1. recursive 구현 

```c++
// 위에서는 정점의 색깔로 표시했지만 컴퓨터는 그럴 수 없기에 bool visit[] 배열을 사용한다.
// visit[x] = false 이면 WHITE, true이면 GRAY or BLACK 이다.
// 아래는 인접 리스트 일 때의 구현입니다. 인접 행렬 일 때의 구현도 작성해보세요!

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

bool visit[100];
vector <int> adj_list[100];

int d[100], f[100];
int E, V;
int t = 0;


void DFS_ALL() {
    for (int i = 1; i < V; u++) {
        if (visit[i] == false)
            DFS(i);
    }
}

void DFS(int start) {
    // printf("%d ", start);
    visit[start] = true;
    t++;
    d[start] = t;
    // printf("d[%d] = %d\n", start, d[start]);
    
    for (int i = 0; i < adj_list[start].size(); i++) {
        int v = adj_list[start][i];
        if (visit[v] == false) {
            DFS(v);
        }
    }
    
    t++;
    f[start] = t;
    // printf("f[%d] = %d\n", start, f[start]);
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
    	
    // sort ascending order
    for (int i = 0; i < V; i++) 
        sort(adj_list[i].begin(), adj_list[i].end());

    // src = 0, run DFS
    DFS(0);
    return 0;
}
```



2. stack 구현

```c++
void dfs_stack(int start) {
    stack <int> s;
    s.push(start);

	while (!s.empty()) {
        int v = s.top();
        s.pop();
        
        if (!visit[v]) {
            printf("%d ", v);
            visit[v] = true;
        }
        
        for (int i = adj_list[v].size() - 1; i >= 0; i--) {
            int w = adj_list[v][i];
            if (!visit[w]) {
                s.push(w);
            }
        }
    }
}
```





**심화과정**

- Edge의 종류

  - Tree Edge
  - Back Edge
  - Forward Edge
  - Cross Edge

  

- DFS와 BFS의 차이

|      | Implement            |      |
| ---- | -------------------- | ---- |
| BFS  | Queue                |      |
| DFS  | Stack (or Recursive) |      |



- DFS Advanced

1. Topological Sort
2. {[}] problem
3. Finding [Strongly] Connected Component
4. Critical Path Analysis
5. Biconnected Component (Articulation point) Problem
