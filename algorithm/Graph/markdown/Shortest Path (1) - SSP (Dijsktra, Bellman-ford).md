# Shortest Path

#### 최단거리 문제

입력으로 그래프의 정보(간선과 정점의 갯수)와 각 간선의 가중치가 주어질 때, 출발점에서 도착점까지의 가는데 드는 최소비용을 구하는 문제



##### 최단경로의 특성

i. **Optimal Substructure**를 가지고 있다. (Dynamic Programming)

![intro.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/intro.png?raw=true)

`distance(n, m)`: n에서 m까지의 최단거리이라고 정의한다면

`distance(1, 4) = distance(1, 2) + distance(2, 3) + distance(3, 4) `로 정의할 수 있다.



**증명** 

만약 각 구간 중 하나라도 구해진 최단경로보다 더 짧은 경로가 존재한다고 가정하자.

그러면 전체 최단경로는 더 짧아질 것이고, 기존에 구했던 최단경로는 더이상 최단경로가 아니게 된다.

이에 모순이 발생하므로 모든 구간의 최단경로의 합은 전체의 최단경로가 된다.





**ii. Triangle inequality: `w[u,v] <= w[u,x] + w[x,v]`** 

`w[u,v]`: 경로 u-v의 가중치

ex) 대전에서 서울을 갈때, 같은 속도로 움직인다면, 대전에서 태안을 갔다가 태안에서 서울을 가는 것이 대전에서 서울로 바로가는 것보다 느리다.

 ![intro.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/shortest_path_dp.png?raw=true)



cf> **Negative-weight edge**

경로 가중치가 0보다 작다면?

- Negative-weight cycle: 그 사이클을 무한히 돈다면 w[u, v] = -INF가 되어버리기 때문에 계산이 안된다.
- Negative-weight edge: 사이클이 없는 음수 가중치가 있다면 계산은 가능할 것이다.

따라서 몇몇 알고리즘은 음이 아닌 정수의 가중치에서만 동작한다.



또한 **최단경로에서 cycle은 항상 포함될 수 없다.** 

음이던 양이던 사이클이 존재하면 거리계산이 부정확하고, 가중치가 0인 사이클은 아무 의마가 없기 때문이다.





## 1. Single-Source Path

임의의 정점 하나에서 시작해서 모든 정점까지의 거리를 구하는 문제

**설계모델**

- s: 출발점
- V: 출발점을 포함한 모든 정점
- d[v]: s에서 v 정점까지의 최단거리
- p[v]: v 정점의 parent, v 정점을 오기 전 어느 정점을 거쳐 왔는가를 나타냄



위의 정의를 이용해 최단경로를 구하는 과정을 서술하면 아래와 같다.

 i. 모든 정점 V에 대해서 d[v]를 무한대로 설정한다.

 ii. Relaxation을 거치면서 d[v]를 감소시킨다.



**Relaxation**

들어가기 앞서, Relaxation이란 최단경로 특성의 *optimal structure*을 이용한 것이다.

![intro.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/relaxation.png?raw=true)

`d[v] > d[u] + w(u,v) `인 경우 `d[u] + w(u,v) `값이 더 작다면 값을 `d[v]`값을 낮춰주는 과정이다.



**의사코드**

```c++
INIT-SINGLE-SOURCE(V, s) {
    for each v : V {
        do d[v] = INF;
        p[v] = NIL;
    }
    d[s] = 0;
}

Relaxation(u,v,w) { 
    if (d[v] > d[u] + w) { /* w = w(u,v) */
   		d[v] = d[u] + w;
    	p[v] = u;
    }
}
```





### Bellman-Ford Algorithm

#### **개요**

- 간선 가중치가 음수여도 가능한 단일 출발점 최단경로 알고리즘이다.

- 반환 값으론 bool 값을 반환한다.
  - FALSE: negative-weight cycle

  - TRUE: No negative-weight cycle

    

그래프의 **vertex의 갯수만큼 모든 edge에 대해서 relaxation**을 진행한다.



#### **의사코드**

```c++
BELLMAN-FORD(V, E, w, s) {
  
   // INIT-SINGLE-SOURCE(V, s);
   for each v : V {
      do d[v] = INF;
      p[v] = NIL;
   }
   
  d[s] = 0;
    
    // why 1 to V-1?
    // 마지막 정점은 어차피 이전 정점을 relaxation 하면서 완료되었으니 건너 뛴다.
	for (i = 1; i < V-1; i++) {
 		for each edge (u,v) : E
        Relaxation(u, v, w)
    }
    
    // 왜 한번 더 체크할까?
    // 음의 사이클이 있는지 확인하기 위해서
    // 만약 음가중치 사이클이 있다면 최단경로 w(u, v) < 0 이므로
	for each edge (u,v) : E {
		if (d[v] > d[u] + w(u,v)) return false
    }
	return true;
}
```



#### **동작과정**

Relaxation을 통해 d[v]가 바뀌는 시점만 있습니다. 



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726141314548.png?raw=true" alt="image-20210726141314548" style="zoom:50%;" />

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726141330925.png?raw=true" alt="image-20210726141330925" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726141344283.png?raw=true" alt="image-20210726141344283" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726141358109.png?raw=true" alt="image-20210726141358109" style="zoom:50%;" />

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726141411704.png?raw=true" alt="image-20210726141411704" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726141425783.png?raw=true" alt="image-20210726141425783" style="zoom:50%;" />



#### **시간복잡도**: $ O (V*E) $ 		

why?  |V| - 1만큼 relaxation을 해주기 때문



#### **c++ 코드**

```c++
// 벨만포드 알고리즘은  따로 인접리스트나 인접행렬을 만들어 주지 않아도 된다.
// 왜냐하면 간선의 정보를 저장하기 때문에 그 정보안에 모든 것이 다들어있기 때문이다.
// tuple 자료구조 찾아보기

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
            
            // 출발점의 거리가 무한대일때 탐색하는 것을 피하기 위해서 조건을 하나 더 넣어준다.
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

         if (d[u] != INF && d[v] > d[u] + w) 
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
```





### Single Source in DAG

- DAG이기 때문에 싸이클이 없습니다.
- DAG의 모든 경로는 토폴로지로 정렬된 하위 시퀀스이므로 왼쪽에서 오른쪽으로 각 최단 경로의 정점을 처리한 다음 한 번에 수행됩니다.



#### 의사코드

```pseudocode
DAG-SHORTEST-PATHS(V, E, w, s)
	topologically sort the vertices 
	INIT-SINGLE-SOURCE(V, s)
	for each vertex u, take in topologically sorted order
		do for each vertex v in Adj[u] 
			do RELAX(u, v, w)
```



#### **시간복잡도**: $ \theta (V+E) $ 		







 ### Dijkstra Algorithm

#### **개요**

- 음이 아닌 정수인 가중치 그래프에 대해서만 사용 가능
- BFS와 비슷하다 (가중치 있는 버전의 BFS)
  - 큐에서 꺼내온 정점에서 시작하여 점차적으로 Tree를 확장시키는 느낌
  - FIFO queue 대신 Priority queue를 사용





#### 설계

두 개의 집합을 준비한다.

- S = 최단 경로에 포함된 정점.
- Q = 우선순위 큐 = V – S.



최단 경로로 정점 u(u ∈ V-S)를 반복적으로 선택하고 u를 S에 추가하고 u에 인접한 모든 정점에 대하여 rexalation합니다.





#### 의사 코드

```pseudocode
Dijkstra (G, w, s)

INITIALIZE-SINGLE-SOURCE (G, s)

set S = {};
priority_queue Q;
for (int i = 0; i < V; i++)
	Q.push(V[i]);
	
while (!Q.empty())
	u = EXTRACT-MIN(Q);
	S.insert(u);
	for each vertext v in adj[u]
		Relaxation(u, v, w)
```



#### 동작

s->t로 가는 최단경로 찾기

![image-20210726144051054](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144051054.png?raw=true)





![image-20210726144131857](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144131857.png?raw=true)



![image-20210726144150288](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144150288.png?raw=true)





![image-20210726144209529](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144209529.png?raw=true)



![image-20210726144350424](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144350424.png?raw=true)





![image-20210726144401909](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144401909.png?raw=true)



![image-20210726144420765](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144420765.png?raw=true)

![image-20210726144439133](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144439133.png?raw=true)



![image-20210726144526881](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144526881.png?raw=true)



![image-20210726144544516](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144544516.png?raw=true)



![image-20210726144619949](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144619949.png?raw=true)



![image-20210726144659741](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144659741.png?raw=true)



![image-20210726144725395](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144725395.png?raw=true)



![image-20210726144743500](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144743500.png?raw=true)



![image-20210726144800422](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144800422.png?raw=true)





![image-20210726144819086](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144819086.png?raw=true)





![image-20210726144829493](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144829493.png?raw=true)



![image-20210726144841733](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144841733.png?raw=true)

![image-20210726144912689](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726144912689.png?raw=true)



#### 코드

```c++
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
```





#### 시간복잡도

- 바이너리 힙: $ O (E \log V) $
- 피보나치 힙: $ O (V \log V + E) $



