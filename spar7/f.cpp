#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    char grid[105][105];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int dp[205];
    unordered_map<int, set<string>> m;

    int letters[205][26];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            letters[i + j][grid[i][j] - 'a']++;
        }
    }
    return 0;
}

int dfs(string s, int i, int j, char **grid) {

}