#include <iostream>
#include <string>

using namespace std;

int main() {
  string T, P;
  cin >> T >> P;

  int n = T.length();
  int m = P.length();

  for (int s = 0; s < n-m; s++) {
    int count = 0;
    for (int i = 0; i < m; i++) {
      if (T[s+i] != P[i]) continue;
      else count++; 
    }

    if (count == m) printf("P found in T at [%d..%d]\n", s, s+m-1);
  }
  
 return 0; 
}