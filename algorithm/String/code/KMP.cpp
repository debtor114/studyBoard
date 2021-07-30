#include <iostream>
#include <string>
#include <vector>

using namespace std;


int fail[1000];

vector <int> result;


void getFailFunc(string P) {
	int M = 0;
	while (P[M]) M++;

	for (int i = 1, j = 0; i < M; i++) {
		while (j > 0 && P[i] != P[j]) 
            j = fail[j - 1];

		if (P[i] == P[j]) {
			fail[i] = ++j;
		} else {
			fail[i] = 0;
		}
	}
}

void KMP(string text, string pattern) {
    int t_len = text.length();
    int p_len = pattern.length();


    int begin = 0, m = 0;
    while(begin <= t_len - p_len) {
        // 일치개수(m)가 P의 길이보다 작고
        // T[begin+m]과의 문자가 일치하는 경우
        if(m < t_len && text[begin+m] == pattern[m]){
            m++;
            // P를 찾은 경우에 begin값을 저장한다.
            if(m == p_len) result.push_back(begin);
        }
        // 불일치하거나 P를 찾은 경우
        else {
            // 일치한적이 한번도 없고 불일치했다면 단순히 begin 옮기면 된다.
            if(m == 0)
                begin++;
            // 그게 아니라면 begin과 m을 위에서 말한 것처럼 초기화!
            else {
                begin += (m - fail[m-1]);
                m = fail[m-1];
            }
        }
    }
}



int main(void) {
    string T, P;
	cin >> T >> P;

    getFailFunc(P);

    KMP(T, P);
    if (result.empty()) cout << P << " 는 없는 단어입니다.\n";
    else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << "인덱스부터 일치합니다.\n";
        }
    }
	

	return 0;
}