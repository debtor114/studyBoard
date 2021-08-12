#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

unordered_map <string, int> hm;

int main() {
  hm.insert(make_pair("james", 1));
  hm.insert(make_pair("sujan", 11));
  hm.insert(make_pair("ace", 111));
  hm.insert(make_pair("homa", 1111));
  
  
  for (auto iter : hm) 
    cout << "name: " << iter.first << ", counts: " << iter.second << "\n";
  
  return 0;
  
}