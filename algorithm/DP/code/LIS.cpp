#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
vector <int> arr, memo;
int dp[1001];


// Complexity: N^2 LIS code
void LIS() {
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                if (dp[i] == dp[j]) 
                    dp[i] = dp[j] + 1;
            }
        }
    }
}

// Complexity: N*logN LIS code
// 최장수열 자체를 구하지는 못하고 부분최장수열이 심지어 아닐수도 있다.
// 반례 { 1 3 2 5 6 7 2 5 3 1 } => 1 2 3 6 7
void fasterLIS() {
    memo.push_back(-1 * INT_MAX);
    for (int i = 0; i < N; i++) {
        if (arr[i] > memo.back()) memo.push_back(arr[i]);
        else {
            vector<int>::iterator iter = lower_bound(memo.begin(), memo.end(), arr[i]);
            *iter = arr[i];
            
        } 
    }

}

void checkLIS() {
    if (N >= 10000) {
        printf("LIS array\n");
        for (int i = 0; i < N; i++)
            printf("%d ", dp[i]);

        printf("\n");
    }

    else {
        printf("faster LIS array\n");
        int length = memo.size()-1;
        printf("%d\n", length);

    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }

    if (N >= 10000) LIS();
    else fasterLIS();

    checkLIS();
    return 0;
}