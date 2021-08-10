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




