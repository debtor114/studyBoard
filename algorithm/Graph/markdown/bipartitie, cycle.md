## 싸이클 찾기 

사이클은 첫 번째 정점과 마지막 정점이 동일한 경로입니다.

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210727143331460.png?raw=true" alt="image-20210727143331460" style="zoom:50%;" /> 





#### 설계

DFS 탐색을 그래프에서 수행하면 탐색을 실행하는 동안 사용한 간선들이 트리를 이루게 됩니다. 

이 트리를 DFS 스패닝 트리라고 합니다. 

DFS 스패닝 트리를 구성한 이후 그래프에 존재하는 모든 간선을 4가지 종류로 나눌 수 있습니다.



##### 간선의 종류 

복습

DFS에서 정점의 상태는 3가지이다. 1. 흰색 (방문x) 2. 회색(방문o) 3.검정(탐색완료) 



- 트리 간선 (Tree Edge)

  - DFS 스패닝 트리에 포함된 간선
  - 흰색 정점을 새로 만날 때 생성되는 간선

  

- 순방향 간선 (Forward Edge)

  - 선조(ancestor)에서 자손(descendant)으로 가는 간선이면서, 트리에 포함되지 않은 간선
  - 회색 정점에서 검정색 정점을 탐색하려고 할 때

  

- 역방향 간선 (Back Edge)

  - 자손에서 선조로 가는 간선이면서, 트리에 포함되지 않은 간선
  - 회색정점에서 회색정점으로 탐색하려고 할 때

  

- 교차 간선(Cross Edge)
  - 위의 세 분류에 포함되지 않은 간선. 즉, 트리의 선조와 자손의 관계가 아니면서 트리에 포함되지 않은 간선
  - 회색 정점에서 검정색 정점을 탐색하려 할 때

 

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210727143917563.png?raw=true" alt="image-20210727143917563" style="zoom:50%;" />



이 중 back edge는 항상 사이클을 만듭니다. 따라서 그래프에서 사이클을 찾으려면 back edge의 존재를 따져보면 됩니다. 





**cf> 무방향그래프이면 tree edge와 back edge만 존재한다.**

Proof by contradiction

- forward edge가 존재한다고 가정
- cross edge가 존재한다고 가정



#### 코드

```c++
// back edge찾아서 사이클 찾기

pStack cycle (graph g) {
  g->cycle = NULL;
  if (hasSelfLoop(g) || (hasParallelEdges(g))) return g->cycle;
  
  for (int i = 0; i < V(g); i++) {
    g->marked[i] = false;
    g->parent[i] = -1;
  }
  
  for (int v = 0; v < V(g); v++) {
    if (!g->marked[v]) cycleDFS(g, -1, v);
  }
}

Key pop(pStack s) {
  pNode t = s->top;
  if (t == NULL) return NULL;
  
  Key key = t->key;
  s->top = t->next;
  free(t);
  
  s->size--;
  return key;
}

void testGraph(graph g) {
  pStack s = cycle(g);
  
  if (s) {
    printf("There is a cycle: ");
    while (sizeStack(s)) printf("%d ", pop(s));
    printf("\n");
  }
  
  else printf("This graph is acyclic. \n");
  
  freeGraph(g);
}
```







## 이분그래프 (Bipartite)

인접한 정점끼리 서로 다른 색으로 칠해서 모든 정점을 두 가지 색으로만 칠할 수 있는 그래프.



![image-20210727152121023](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210727152121023.png?raw=true)



#### 설계: Two-colorability

i. BFS, DFS로 탐색하면서 정점을 방문할 때마다 두 가지 색 중 하나를 칠한다.

ii. 다음 정점을 방문하면서 자신과 인접한 정점은 자신과 다른 색으로 칠한다.

iii. 탐색을 진행할 때 자신과 인접한 정점의 색이 자신과 동일하면 이분 그래프가 아니다.

iv .BFS의 경우 정점을 방문하다가 만약 같은 레벨에서 정점을 다른 색으로 칠해야 한다면 무조건 이분 그래프가 아니다.

모든 정점을 다 방문했는데 위와 같은 경우가 없다면 이분 그래프이다.




#### 시간복잡도: $ O(V + E) $



#### 코드

```c++
bool bipartitleVerify(graph g) {
  
  for (int v = 0; v < V(g); v++) {
    
    
    
    
    
  }
  
  return true;
}
```









## P-NP problem

- Graph coloring  - no one knows

- Euler tour - typical

- Hamiliton cycle - intractable, classic NP-complete problem

- Graph isomorphism - no one knows

- lay out a graph in the plane without crossing edges - hire an expert, 

  linear time ifs-based planarity alogrithm discovered by Tarjan in 1970s (too complicated for most practitioners)



how difficult?

- any programmer could do it
- typical diligent alogrithms student could do it
- hire an expert
- intractable.
- no one knows.
- Impossible