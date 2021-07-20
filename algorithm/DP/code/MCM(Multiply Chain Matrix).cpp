#include <cstdio>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int matrics[1001][2];
    int d[2002];
    int M[1001][1001];
    int S[1001][1001];

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &matrics[i][0], &matrics[i][1]);
    }

    // Make d[i] array 
    d[0] = matrics[0][0];
    for (int i = 0; i < N; i++) {
        d[i+1] = matrics[i][1];
    }

    // Memoization  
    // if (i,i) = 0
    for (int i = 1; i <= N; i++)
        M[i][i] = 0;
    
    // else
    for (int r = 2; r <= N; r++) { // r is chain length
        for (int i = 1; i <= N-r+1; i++) {
            int j = i+r-1;
            M[i][j] = INT_MAX;
            for (int k = i; k < j; k++) { // k is diverging point
                if (M[i][j] > M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j]) {
                    M[i][j] = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
                    S[i][j] = k; 
                }    
            }
        }
    }

    // Print M, S array
    printf("\n");
    printf("M Array\n");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("S Array\n");

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", S[i][j]);
        }
        printf("\n");
    }

    return 0;
}