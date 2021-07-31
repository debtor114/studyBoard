#include <iostream>

using namespace std;

int arr[10001];

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int answer = 0;

    int start = 0;
    int end = 0;
    int partial_sum = 0;

    while (end <= N)
    {
        // cout << start << " " << end-1 << "  sum: " << partial_sum;
        if (partial_sum >= M) {
            //cout << " v (만족하는 부분배열)";
            partial_sum -= arr[start++];

        }
        else if (partial_sum < M)
            partial_sum += arr[end++];
        
        // 구간합 == M , 구간합 > M 일때 수정해서 적용
        if (partial_sum >= M) 
            answer++;

        // cout << endl;
    }

    cout << answer << "\n";
    return 0;
}