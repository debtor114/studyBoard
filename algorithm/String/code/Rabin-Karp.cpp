#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

int t[100], moduloT[100];

int main() {
    string T, P;
    cin >> T >> P;

    int n = T.length();
    int m = P.length();
    int p = 13;


    // t_0 구하기
    for (int i = 0; i < m; i++)
        t[0] += (T[i]-48)*(pow(10, m-i-1));

    // t_s (1~n-m)구하기
    for (int i = 1; i <= n-m; i++) {
        t[i] = 10*(t[i-1] - pow(10, m-1)*(T[i-1]-48)) + (T[i+m-1]-48);
    }

    // modulo
    for (int i = 0; i <= n-m; i++) {
        moduloT[i] = t[i]%p;
    }

    // 패턴 숫자로 바꿔주고 나머지연산
    int intP = stoi(P);
    int moduleP = intP % p;

    // 나머지 비교
    for (int i = 0; i <= n-m; i++)
        if (moduleP == moduloT[i]) {
            if (intP == t[i]) printf("hit at [%d ... %d]\n", i+1, i+m);
            else printf("spurious hit at [%d ... %d]\n", i+1, i+m);     
        }

    return 0;

}