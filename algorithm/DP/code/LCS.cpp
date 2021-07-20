#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;

    int memo[1001][1001];

    cin >> s1 >> s2;

    // LCS Algorithm
    s1 = "0" + s1;
    s2 = "0" + s2;
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (i == 0 || j == 0) {
                memo[i][j] = 0;
                continue;
            }

            if (s1[i] == s2[j])  memo[i][j] = memo[i-1][j-1] + 1;
            else  memo[i][j] = max(memo[i-1][j], memo[i][j-1]);

        }
    }

    // Print LCS table
    printf("  ");
    for (int i = 0; i < s1.length(); i++) {
        if (i == 0) {
            for (int k = 0; k < s1.length(); k++)
                printf("%c ", s1[k]);

            printf("\n");
        }
        
        for (int j = 0; j < s2.length(); j++) {
            if (j == 0) printf("%c ", s2[i]);
            printf("%d ", memo[i][j]);
        }
        printf("\n");
    }

    // Find LCS string
    string LCS;
    int x = s1.length()-1;
    int y = s2.length()-1;
    int LCS_length = memo[x][y];

    while (LCS_length != 0) {
        if (memo[x-1][y] == LCS_length) x--;
        else if (memo[x][y-1] == LCS_length)  y--;
        else {
            LCS.push_back(s1[x] == s2[x] ? s1[x] : s2[y]);
            x--, y--;
            LCS_length--;
        }
    }

    // Print LCS string
    for (int i = LCS.length() - 1; i >= 0; i--)
        printf("%c", LCS[i]);

    printf("\n");
    return 0;

}