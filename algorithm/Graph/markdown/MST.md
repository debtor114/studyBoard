# MST (Minimum Spanning Trees)

**신장 트리란?**

: 그래프 내의 모든 정점을 포함하는 트리



**최소 신장 트리 문제**

: Connected, Undirected, Weighted 그래프에서 가중치가 가장 적게 신장 트리를 만드는 문제
<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/MST_intro1.png" style="zoom: 33%;" />  <img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/MST_intro2.png" style="zoom: 33%;" />



- N개의 정점을 모두 포함하며 (Connected) Cycle이 없게 하려면 필요한 간선의 최소 갯수는 N-1개이다.

  

모델 설계

```c++
GENERIC-MST(G, w) { // G: graph, w: weight
    // 아무 간선도 없는 빈 트리 A를 하나 만든다.
	Tree A = null;
    
    // A에 safe한 간선을 한 개씩 추가함으로서 MST를 구성한다.
	while (A != a spanning tree) {
		find an "safe edge" E(u,v) for A
		A = A U { E(u, v) } 
    }
	return A
}
```



**safe edge**

: 트리 A가 MST의 부분집합 일 때, A에 간선 E(u, v)를 추가해도 여전히 A가 MST의 부분집합이라면 간선 E (u, v)는 safe edge라고 한다.

=> safe edges만 추가하여 트리 A를 구성한다면 MST를 만들 수 있을 것이다.



safe edge 찾기

전체 그래프의 모든 정점을 모아놓은 집합을 V, 모든 간선을 모아놓은 집합을 E라고 하자.

또한, S는 V의 부분집합, T는 E의 부분집합이라고 하자.

Ex) 

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/MST_intro2.png" style="zoom: 60%;" />

위 그래프에서 V = {A, B, C, D, E, F, G, H} , E = {AB, AH, BC, BE, CB, DE, EF,  FG, FH , HG} 이다.

- cut: 그래프 내부에 선을 그었을 때, 그래프가 두 파티션 (S, V-S)로 나눠지게 하는 선

- crosses: 말그대로 cut에 교차한다는 뜻

  => 간선의 한 쪽 정점이 S, 나머지 한 쪽 정점이 V-S에 포함되어 있으면 그 edge는 cut을 crosses한다고 한다.

![intro.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/crossEdge.png?raw=true)

- respect: E의 부분집합 T의 모든 간선이 crosses edge가 아니라면  cut은 A를 respect한다 라고 한다.
- light edge: cut을 crosses하는 간선 중 가장 가중치가 낮은 간선





왜 light edge는 safe한가?

https://codingtrainee.tistory.com/68

