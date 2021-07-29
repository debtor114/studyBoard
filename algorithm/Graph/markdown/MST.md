# MST (Minimum Spanning Trees)

#### 선수지식: Disjoint-set, union-find



**신장 트리란?**

: 그래프 내의 모든 정점을 포함하는 트리



### **최소 신장 트리 문제**

: Connected, Undirected, Weighted 그래프에서 가중치가 가장 적게 신장 트리를 만드는 문제
<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/MST_intro1.png?raw=true" style="zoom: 33%;" />  <img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/MST_intro2.png?raw=true" style="zoom: 33%;" />



- N개의 정점을 모두 포함하며 (Connected) Cycle이 없게 하려면 필요한 간선의 최소 갯수는 N-1개이다.

  

#### **모델 설계, 의사코드**

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



#### **safe edge**

: 트리 A가 MST의 부분집합 일 때, A에 간선 E(u, v)를 추가해도 여전히 A가 MST의 부분집합이라면 간선 E (u, v)는 safe edge라고 한다.

=> safe edges만 추가하여 트리 A를 구성한다면 MST를 만들 수 있을 것이다.



safe edge 찾기

전체 그래프의 모든 정점을 모아놓은 집합을 V, 모든 간선을 모아놓은 집합을 E라고 하자.

또한, S는 V의 부분집합, T는 E의 부분집합이라고 하자.

Ex) 

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/MST_intro2.png?raw=true" style="zoom: 60%;" />

위 그래프에서 V = {A, B, C, D, E, F, G, H} , E = {AB, AH, BC, BE, CB, DE, EF,  FG, FH , HG} 이다.

- cut: 그래프 내부에 선을 그었을 때, 그래프가 두 파티션 (S, V-S)로 나눠지게 하는 선

- crosses: 말그대로 cut에 교차한다는 뜻

  => 간선의 한 쪽 정점이 S, 나머지 한 쪽 정점이 V-S에 포함되어 있으면 그 edge는 cut을 crosses한다고 한다.

![intro.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/crossEdge.png?raw=true)

- respect: E의 부분집합 T의 모든 간선이 crosses edge가 아니라면  cut은 A(연두색 정점으로만 이루어진 집합)를 respect한다 라고 한다. 
- light edge: cut을 crosses하는 간선 중 가장 가중치가 낮은 간선





#### **왜 light edge는 safe한가?**

A를 MST의 부분집합이라고 가정하고 cut (S, V-S)는 A를 respect 할때, (u, v)가 light edge이면 A에 대해 safe edge이므로 A에 포함시킬 수 있다.



증명) 

i. A를 포함하고 있는 T라는 MST가 있다고 가정하자. 이 T 트리는 (u, v) light edge를 포함하지 않는다.

ii. A를 포함하고 있는 또다른 트리 $ T^{\prime} $ 라는 MST가 있다고 가정하자. 

​	이 $ T^{`\prime} $ 트리는 (u, v) light edge를 포함한다.  $ T^{\prime} = A \cup \{ (u, v) \} $

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724144718713.png?raw=true" alt="image-20210724144718713" style="zoom:50%;" />



iii. 정점 u와 v는 cut (S, V-S)에 의해 서로 반대편에 있기 때문에 반대편으로 넘어가기 위해서는 최소 한개의 cut을 crosses하는 간선이 필요하다. 여기선 (x, y)가 그러한 간선이 되므로 T에 (x, y) 간선을 추가해보자.



iv. T트리에서 간선 (x, y)를 제외하면 두개의 컴포넌트로 나뉘게 된다. 다시 간선 (u, v)를 T에 포함시키면 $ T^{\prime} $ 트리가 형성된다.



$ w(T^{\prime}) = w(T) - w(x, y) + w(u, v) \leq w(T) $ 

이 되므로 $ T^{\prime} $ 는 MST일 수 밖에 없다. 

따라서 $ A \cup \{(u, v)\} \subseteq T^{\prime} $ 이므로 light edge인 (u, v)는 safe하다.





## 크루스칼 알고리즘

- 디자인 패턴: 그리디 알고리즘



#### 구현

내림차순으로 가중치를 정렬하고 여러 트리로 구성되어 있는 숲을 만드는 것이다.

두개의 components를 light edge를 추가하므로 하나의 component로 합친다.

- 두 components의 cut을 cross하는 light edge를 선택한다.
- 만약 사이클을 형성하는 edge라면 선택하지 않는다.





#### 의사코드

```pseudocode
MST-Kruskal (G, w)
	R = E;
	F = 0;
	while (!R.empty()) 
		Remove the light edge, (u, v), from R;
		if ( (u, v) does not make a cycle in F )
			Add (u, v) to F;
			
	return F;
```







#### 작동 과정

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724150413769.png?raw=true" alt="image-20210724150413769" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724150441288.png?raw=true" alt="image-20210724150441288" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724150520887.png?raw=true" alt="image-20210724150520887" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724150538057.png?raw=true" alt="image-20210724150538057" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724150553087.png?raw=true" alt="image-20210724150553087" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724150636909.png?raw=true" alt="image-20210724150636909" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724150659100.png?raw=true" alt="image-20210724150659100" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724150710652.png?raw=true" alt="image-20210724150710652" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724150743243.png?raw=true" alt="image-20210724150743243" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724150810152.png?raw=true" alt="image-20210724150810152" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724150825898.png?raw=true" alt="image-20210724150825898" style="zoom:50%;" />



#### 코드

```c++
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple> 		// c++ 17 

using namespace std;

int parent[1000];
vector < tuple <int, int, int> > Edge;

int V, E;

int getRoot(int x) {  
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
}

void unionSet(int a, int b) { 
    int x = getRoot(a);
    int y = getRoot(b);

    if(x < y) parent[y] = x;
    else parent[x] = y;
}

bool find(int a, int b) { 
    int x = getRoot(a);
    int y = getRoot(b);
    if(x == y) return true;
    else return false;
}

int main() {	
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        Edge.push_back(make_tuple(w, u, v));
    }

	sort(Edge.begin(), Edge.end());


    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int cost = 0;
    for (int i = 0; i < Edge.size(); i++) {
        int u, v , w;
        u = get<1>(Edge[i]);
        v = get<2>(Edge[i]);
        w = get<0>(Edge[i]);
        if (!find(u, v)) {
            unionSet(u, v);
            cost += w;
        }
    }

    cout << cost << endl;
    
    return 0;
}
```





#### 시간복잡도: $ O(E \log E) $







## Prim's algorithm

#### 설계

하나의 트리 A를 만들고 그 만드는 과정에서 A는 항상 트리를 유지해야한다.

임의의 정점 r을 root로 두고 시작한다.

각 과정에서  cut ($ V_A, V-V_A $)을 cross하는 light edge를 찾는다.

$ \pi[v] $: v의 부모로 설정하고 부모가 없거나 v=root이면 NIL로 표기핰다.

light edge를 빠르게 찾기 위해 우선순위 큐를 사용한다.



모든 정점을 안보이는 정점으로 설정해놓는다.

임의의 점 r을 루트로 트리를 형성한다.

r의 인접한 정점을 fringe로 분류한다.

fringe가 빌 때 까지 Tree의 정점 t와 fringe 안에 있는 정점 중 가장 가벼운 정점 v를 선택해서 트리에 추가한다.

그러면 트리에 (t, v)라는 간선이 추가되고 v에 인접한 모든 정점을 다시 fringe로 재분류한다.





#### 작동과정

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724154825744.png?raw=true" alt="image-20210724154825744" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724155038933.png?raw=true" alt="image-20210724155038933" style="zoom:33%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724155436703.png?raw=true" alt="image-20210724155436703" style="zoom:33%;" />

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724155735698.png?raw=true" alt="image-20210724155735698" style="zoom:33%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724160047065.png?raw=true" alt="image-20210724160047065" style="zoom:33%;" />



....

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724160359893.png?raw=true" alt="image-20210724160359893" style="zoom:33%;" />

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724160500865.png?raw=true" alt="image-20210724160500865" style="zoom:33%;" />



#### 의사코드

```pseudocode
MST-prim (G, w, r)
	Q = V[G];
	for each u in Q
		key[u] = INF;
		parent[u] = NIL;
		
	key[root] = 0;
	parent[root] = NULL;
	
	while (!Q.empty())
		u = ExtractMin(Q);
		
    for each v in Adj[u]
    	if (v in Q and w(u,v) < key[v])
    		parent[v] = u;
    		key[v] = w(u, v);
```





#### 코드로 보는 동작

i. INF로 초기화, 임의의 정점을 root로 설정

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724160828753.png?raw=true" alt="image-20210724160828753" style="zoom:50%;" />

  

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724161656677.png?raw=true" alt="image-20210724161656677" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724162219426.png?raw=true" alt="image-20210724162219426" style="zoom:50%;" />

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724162055629.png?raw=true" alt="image-20210724162055629" style="zoom:50%;" />



ii. 거리가 10에서 5로 업데이터 되면서 간선도 바뀐다 (10->3 => 5->2)



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724163314629.png?raw=true" alt="image-20210724163314629" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724163119331.png?raw=true" alt="image-20210724163119331" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724163149372.png?raw=true" alt="image-20210724163149372" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724163226813.png?raw=true" alt="image-20210724163226813" style="zoom:50%;" />



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210724162828351.png?raw=true" alt="image-20210724162828351" style="zoom:50%;" />







#### C++ 코드

```c++
```





#### 시간복잡도

어떤 자료구조를 사용하느냐에 따라 다름



