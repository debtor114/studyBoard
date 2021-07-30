#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector <int> arr;
  
  int N, k;
  cin >> N >> k;
  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    arr.push_back(input);
  }
  
    int window_sum = 0;
    int max_sum = 0;
    int window_start = 0;
  
  
  for (int window_end = 0; window_end < arr.size(); window_end++) {
    window_sum += arr[window_end];
    
    if (window_end >= k-1) {
      max_sum = max(max_sum, window_sum);
      window_sum -= arr[window_start];
      window_start += 1;
    }
  }
  
  cout << "max: " << max_sum << endl;
  return 0;
  
}