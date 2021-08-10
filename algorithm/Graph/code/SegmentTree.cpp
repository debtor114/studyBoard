#include <iostream>
#include <vector> 


using namespace std; 

vector <int> arr;
int tree[1000]; 


// start: 시작 인덱스, end: 끝 인덱스  
// index: 구간 합을 수정하고자 하는 노드
// left, right: 구간 합을 구하고자 하는 범위
// new_value: 수정할 값 


int init(int start, int end, int node) { 
  if(start == end) return tree[node] = arr[start]; 
  int mid = (start + end) / 2;  
  
  return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1); } 


int sum(int start, int end, int node, int left, int right) { 
  // 범위 밖에 있는 경우 
  if(left > end || right < start) return 0; 
  
  // 범위 안에 있는 경우 
  if(left <= start && end <= right) return tree[node]; 
  
  // 그렇지 않다면 두 부분으로 나누어 합을 구하기 
  int mid = (start + end) / 2; 
  return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right); 

} 

void update(int start, int end, int node, int index, int new_value) { 
  // 범위 밖에 있는 경우  
  if(index < start || index > end) return; 
  
  // 범위 안에 있으면 내려가며 다른 원소도 갱신  
  tree[node] += new_value; 
  if (start == end) return; int mid = (start + end) / 2; 
  
  update(start, mid, node * 2, index, new_value); 
  update(mid + 1, end, node * 2 + 1, index, new_value); 

}


int main(void) { 

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    arr.push_back(input);
  }
  
  init(0, N - 1, 1); 
  
  int T;
  cin >> T;
  while (T--) {
    char query;
    int start, end;
    cin >> query;
    
    if (query == 's') {
      int start, end;
      cin >> start >> end;
      
      int ans = sum(0, N - 1, 1, start, end);
      cout << start << "~" << end << "의 구간 합: " << ans << '\n'; 
    }
    
    else if (query == 'u') {
      int index, new_val;
      cin >> index >> new_val;

      cout << "arr[" << index << "] += " << new_val << '\n'; 
      update(0, N - 1, 1, index, new_val);  
    }
  }

	return 0;
}