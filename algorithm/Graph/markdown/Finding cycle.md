## 싸이클 찾기 

### 무향 vs 유향 그래프





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









### [1] 그래프 조건, 트리 조건

사이클에 대해 이야기하기 전에 2가지 사실을 짚고 넘어갑니다.

#### 1. 정점 n개, 간선 n-1개인 그래프는 트리이다.

그렇지 않습니다. 하지만 역인 트리이면 정점 n개 간선 n-1개를 갖는다는 맞습니다.

#### 2. 정점 n개, 간선 n개인 그래프는 정확히 한개의 사이클을 갖는다.

맞습니다. 간선의 개수가 정점의 개수와 같다면 하나의 사이클이 존재하게 됩니다.

그렇다면 사이클을 어떻게 찾을 수 있을까요?

### [2] 사이클을 찾기 위해 필요한 2가지

#### 1. DFS로 그래프를 탐색하고나서 탐색 경로를 살펴보면 트리가 된다.

![img](https://images.velog.io/images/since-1994/post/70f3ec7e-80c9-400b-a07f-970438f17ec5/IMG_0125.jpg)<주어진 그래프>![img](https://images.velog.io/images/since-1994/post/8cf7452d-d393-4476-9187-1f09283949c6/IMG_0128.jpg)

<DFS 경로를 표시한 그래프>

주어진 그래프를 딱보면 사이클이 있는 그래프네요. 이 그래프를 정점 1을 루트로 DFS 탐색을 하고 탐색한 경로를 빨간색으로 표시한것이 아래 이미지입니다. 빨간색 이미지를 보면 어떻나요? 트리를 이루고 있죠? 트리의 정의는 무엇인가요? 임의의 두 노드를 잇는 경로는 유일해야하죠. DFS는 어떤가요? 같은 노드를 여러번 방문하나요? 그렇지 않죠 그래서 DFS경로를 표시하면 위와 같이 트리가 됩니다.

#### 2. 트리는 어디서부터 왔는지를 이용하면 visited배열 없이 DFS 탐색이 가능하다.

DFS 탐색시에 많은 분들이 visited 배열을 이용해서 방문한 노드를 확인하는데 사용하실거라 생각합니다. 그런데 트리에서는 visited 배열 없이도 DFS탐색을 할 수 있습니다. 현재 탐색 중인 노드의 부모를 표시하면 가능합니다. 다음 방문할 노드가 현재 노드의 부모라면 다시 방문하지 않는것이죠.

코드로는 아래와 같이 직전 노드가 어디인지만 표시해주면 됩니다.

```java
dfs(int now, int from){
  for(int next : list[now]){
    //다음에 방문할 노드가 현재 노드의 부모라면 방문하지 않는다.
    if(next == from){
      continue;
    }
    dfs(next, now);
  }
}

// dfs를 시작할때는 자기 자신을 부모로 해줘도 됩니다.
dfs(1,1);
```

![img](https://media.vlpt.us/images/since-1994/post/9645b77b-ac24-4e26-b270-356cf8381f21/IMG_0127.jpg)

위 그래프에서 빨간색은 실제 탐색 경로를 나타내면 파란색은 탐색을 시도했으나 부모와 같아서 방문하지 않은 것을 의미합니다.

### [3] 사이클 찾기

그럼 이제 우리는 사이클을 찾는데 필요한 두가지 조건을 모두 알았습니다. 이제 사이클을 찾고 사이클에 존재하는 정점을 모두 출력해보도록 하겠습니다.

먼저 조건은 정점 n개, 간선 n개를 갖는 그래프입니다. 우리가 위에서 배운대로 무조건 한개의 사이클을 갖습니다. 우리는 이 그래프를 DFS탐색을 할 겁니다. 탐색을 하기 위해 우리는 visited배열과 노드의 부모 노드 표시 두가지를 사용할 겁니다. 탐색 경로로 우리는 트리를 얻게 될 겁니다.

이제 사이클을 찾기 위해 한가지 트릭을 더합니다. 우리는 그래프를 찾기 위해 n-1개의 간선을 탐색했을 것이고 남은 1개의 간선이 바로 사이클을 찾는 키가 됩니다. 부모 노드와 다음 노드를 이용해 표시했음에도 visited한 정점을 발견한다면 바로 정점에 의해 사이클이 형성된 것이란걸 알 수 있습니다.

![img](https://images.velog.io/images/since-1994/post/8cf7452d-d393-4476-9187-1f09283949c6/IMG_0128.jpg)이 상황에선 1번 정점과 6번 정점을 잇는 간선이 사이클을 형성한 원인이 되겠죠. 이 간선만 없다면 트리였으니까요. 우리가 이런 정점을 찾았을 때 이 간선을 잇는 두 정점을 표시해두면 이제 우리는 사이클의 끝과 끝을 찾은 겁니다.

끝과 끝을 찾았지만 갈길이 멀군요.. 사이클에 포함된 정점들은 어떻게 찾을 까요? 바로 아래와 같이 찾을 수 있습니다. 방문할 때마다 이 정점이 어디서부터 온지를 저장해놓으면 돼요.

![img](https://images.velog.io/images/since-1994/post/c73d0a05-8c8b-49ef-a1be-3a00e6ee0fb4/IMG_0129.jpg)

6은 5에서 왔고 5는 2에서 왔고 2는 1에서 왔고 1은 사이클의 끝과 끝이니까 더 확인할 정점은 없다. 따라서 `1, 2, 5, 6이 사이클을 이루는 정점이다` 라는 결론을 얻을 수 있습니다.

### [4] 관련 문제

[서울 지하철 2호선](https://www.acmicpc.net/problem/16947) 이라는 문제 입니다. 위에 적힌 설명과 BFS에 대한 지식이 있다면 충분히 해결가능하니 꼭 풀어보시기 바랍니다. 사실 이 포스트를 적게 된 원인이 된 문제입니다. 여러번 풀어보았는데 풀때마다 새로운 실수를 해서 반나절씩 시간을 잡아먹더라구요.. 뭔가 희한한 문제입니다. 차근히 풀어보시면 쉽게 푸실거라 생각합니다. 이걸 풀고나면 지하철 탈 때 재밌습니다. ㅋㅋㅋ







#### **무방향 그래프에서 사이클 찾기**

 dfs를 수행하면서, 방문한 정점을 기록합니다. 방문한 정점을 또 방문하면 사이클이 존재합니다.











## 유니온 파인드로 사이클 찾기

**Q. 사이클을 찾는다는 것은?**

사이클을 검출(detect) 한다는 것은 그래프내에 사이클이 있는가? 있다면 총 몇 개 존재하는가 ? 그리고 사이클에 포함된 노드의 개수는 몇 개인가? 등을 알아내는 것이다.

어떠한 이유로 그래프 자료구조를 이용해 다양한 문제를 풀다보면 그래프내 사이클을 찾는 알고리즘들이 필요하게 된다.

예를들어 최소신장트리 - MST를 생성하려면 그래프내 사이클이 없어야 하는데 MST를 생성하는 알고리즘 중 하나인 [크러스컬(Kruskal) 알고리즘](https://jackpot53.tistory.com/73) 에서도 필요하다.

사이클을 검출하는 방법이 몇가지 있는데 여기서는 다양한 에제를 통해 사이클 검출하는 알고리즘을 확인해 보자.

 

 

**Q. [서로수집합(Disjoint Set) - 합집합-찾기(union–find)](https://jackpot53.tistory.com/91) 으로 사이클 검출이 가능하다고 하던데 ?**

Disjoin Set에 대해서 모르면 우선 [서로수집합(Disjoint Set) - 합집합-찾기(union–find)](https://jackpot53.tistory.com/91)를 반드시 선행 학습해야 한다.

서로수 집합의 원소를 정점(or 노드)라고 하면 같은 집합(subgraph)에 포함되어 있는 정점들끼리는 이미 에지로 연결된 것들이고 다른 집합(subgraph)에 있는 정점과는 서로 연결되어 있지 않다는 것을 기반으로 한다. 

 

***Union-Find Algorithm\*** 은 그래프내 셀프루프(self-loop : 자기자신을 가리키는 간선)을 포함하면 안되고 **무방향그래프에서 사이클을 찾는데 유용**하다. 

그림 2와 같은 그래프가 있을때 **0 → 1** **→ 3** **→ 2** **→ 0** 으로 순환되는 사이클이 1개 존재하는데 이것을 Union-Find Algorithm으로 검출하는 것을 예로 들어보자. 

처음에는 정점들을 disjoint set 들로 만들기위해 루트노드가 자기자신을 가리키는 트리 5개가 만들어진다.



![img](https://blog.kakaocdn.net/dn/26rOv/btqwARxQHeZ/idKqsLZivgevAa1SkMPve1/img.png)그림2. 초기 disjoint set



 

그림2는 S1 **∪NION** S0 = {0, 1} 을 하고 0을 부모로 한다.

 



![img](https://blog.kakaocdn.net/dn/dNkTaq/btqwAk8APpU/LoQ7JUZIc2dRkZVsvkm5e1/img.png)그림2 S1 ∪NION S0 = {0, 1} 결과



**disjoint set 에서 UNION을 하려면 서로 연결하려는 정점의 루트노드가 서로 달라야 한다**
여기서 S1, S0 는 서로 루트노드가 다르기 때문에 UNION이 가능하다. ([서로수집합(Disjoint Set) - 합집합-찾기(union–find)](https://jackpot53.tistory.com/91) 코드 참고)

| 123456789 | public void union(int p, int q) {    int rootP = find(p);    int rootQ = find(q);    if (rootP == rootQ) return;     parent[rootQ] = rootP;     count--;  } |
| --------- | ------------------------------------------------------------ |
|           |                                                              |

 

그림3는 S2 **∪NION** S0 = {0, 1, 2} 을 하고 0을 부모로 한다.

 



![img](https://blog.kakaocdn.net/dn/E8xIJ/btqwAHI1klx/JDgGQsNqz7RCxpHPPFstg0/img.png)그림3 S2 ∪NION S0 = {0, 1, 2}



그림4는 S3 **∪NION** S0 = {0, 1, 2, 3 } 을 하고 1을 부모로 한다.



![img](https://blog.kakaocdn.net/dn/xHvej/btqwyCCl7Mj/KQfleaU4FKxrMKPmXn3XlK/img.png)그림4 S3 ∪NION S0 = {0, 1, 2}



그림5는 S4 **∪NION** S0 = {0, 1, 2, 3 } 을 하고 3을 부모로 하였다.

이제 모든 정점에 에지가 연결되었고 사이클이 없는 스패닝트리(spanning tree)가 완성되었다. 



![img](https://blog.kakaocdn.net/dn/bxNcGQ/btqwyPO1GnN/yot1LOXsbFf6OcUdrEJn2k/img.png)그림5. 그림4 S4 ∪NION S0 = {0, 1, 2, 3, 4}



 

그림6은 3 -> 2를 에지를 연결하려 시도하고 있다.

***Union-Find Algorithm\*** 을 이용하여 3과, 2의 루트노드를 찾아볼것이다. 

3, 2는 루트노드 0의 자식노드 또는 손자노드이기 때문에 같은 집합에 있다.
**disjoint set 에서 UNION을 하려면 서로 연결하려는 정점의 루트노드가 서로 달라야 한다는 규칙을 어기게된고**

이런경우 ***사이클***이 생성된것을 알아낼 수 있다.

 



![img](https://blog.kakaocdn.net/dn/bpKUju/btqwzAqiIeA/GTKekvbeldLApe6ZWvn871/img.png)그림6. 3 -> 2 에지를 연결할때 사이클이 생긴다.



 

## SCC로 사이클 찾기

### 1. 사이클을 이루는 정점 확인

\1) **BFS**



### 2. 사이클 존재 여부만 확인

\1) **최소신장트리(MST)**

 \- findParent 으로 부모가 동일하지 않은 정점만 연결 (이것을 카운팅)

 \- 모든 정점을 방문하지 못하는 경우, 간선의 개수가 N-1 이 아니다.

 \- 크루스칼 알고리즘, union-find 이용

