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

