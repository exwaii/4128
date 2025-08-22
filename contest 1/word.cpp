#include <bits/stdc++.h>

using namespace std;

int check_symmetric(string &s, int start, int end) {
    if (start >= end) {
        return 1;
    }
    return s[start] == s[end] && check_symmetric(s, start + 1, end - 1);
}

void solve() {
    int n;
    string w;
    cin >> n >> w;
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int counter, result = 0, length = w.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // cout << i << ' ' << j << '\n';    
            if (b[i][j] == w[0]) {
                // ->
                if (j + length <= n) {
                    counter = 0;
                    while (++counter < length) {
                        if (b[i][j + counter] != w[counter]) {
                            break;
                        }
                    } 
                    result += (counter == length);
                    // cout << "right " << (counter == length) << "\n"; 
                }
                // <-
                if (j >= length - 1) {
                    counter = 0;
                    while (++counter < length) {
                        if (b[i][j - counter] != w[counter]) {
                            break;
                        }
                    }
                    result += (counter == length);
                    // cout << "left " << (counter == length) << "\n"; 
                }
                // down
                if (i + length <= n) {
                    counter = 0;
                    while (++counter < length) {
                        if (b[i + counter][j] != w[counter]) {
                            break;
                        }
                    } 
                    result += (counter == length);
                    // cout << "down " << (counter == length) << "\n"; 
                }
                // up
                if (i >= length - 1) {
                    counter = 0;
                    while (++counter < length) {
                        if (b[i - counter][j] != w[counter]) {
                            break;
                        }
                    }
                    result += (counter == length);
                    // cout << "up " << (counter == length) << "\n"; 
                }
                // down right
                if (i + length <= n && j + length <= n) {
                    counter = 0;
                    while (++counter < length) {
                        if (b[i + counter][j + counter] != w[counter]) {
                            break;
                        }
                    }
                    result += (counter == length);
                    // cout << "down right " << (counter == length) << "\n"; 
                }
                // down left
                if (j >= length - 1 && i + length <= n) {
                    counter = 0;
                    while (++counter < length) {
                        if (b[i + counter][j - counter] != w[counter]) {
                            break;
                        }
                    }
                    result += (counter == length);
                    // cout << "down left " << (counter == length) << '\n'; 

                }
                // up left
                if (i >= length - 1 && j >= length - 1) {
                    counter = 0;
                    while (++counter < length) {
                        if (b[i - counter][j - counter] != w[counter]) {
                            break;
                        }
                    }
                    result += (counter == length);
                    // cout << "up left " << (counter == length) << "\n"; 
                }
                // up right
                if (i >= length - 1 && j + length <= n) {
                    counter = 0;
                    while (++counter < length) {
                        if (b[i - counter][j + counter] != w[counter]) {
                            break;
                        }
                    }
                    result += (counter == length);
                    // cout << "up right " << (counter == length) << "\n"; 
                }
            }
        }
    }
    if (check_symmetric(w, 0, length - 1)) {
        // cout << "impostor\n";
        result /= 2;
        if (length == 1) {
            result /= 4;
        }
    }
    cout << result << "\n";
}

int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
