#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

const int N = 305;
const int inf = 100000;
int dp[N][N][N];

int main() {
    int n;
    cin >> n;
    
    queue<vector<int> > q;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                dp[i][j][k] = inf;
                if (i + j + k >= N) continue;
                if (i == 0 || j == 0 || k == 0) {
                    dp[i][j][k] = 0;
                    vector<int> v(3);
                    v[0] = i;
                    v[1] = j;
                    v[2] = k;
                    q.push(v);
                }
            }
        }
    }

    int counter = 0;

    while (!q.empty()) {
        ++counter;
        if (counter > N * N * N + 5) {
            cout << counter << '\n';
            return 0;
        }
        vector<int> v = q.front();
        q.pop();
        for (int i = 0; i < 3; ++i) {
            if (v[i] % 2 == 0) {
                for (int j = 0; j < 3; ++j) {
                    if (i == j) continue;
                    int k = v[i] / 2;
                    vector<int> w(3);
                    w[i] = v[i] - k;
                    w[j] = v[j] + k;
                    w[3 - i - j] = v[3 - i - j];
                    if (dp[w[0]][w[1]][w[2]] > dp[v[0]][v[1]][v[2]] + 1) {
                        dp[w[0]][w[1]][w[2]] = 1 + dp[v[0]][v[1]][v[2]];
                        q.push(w);
                    }
                }
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        int ans = 0;
        for (int a = 0; a <= i; ++a) {
            for (int b = 0; b <= i - a; ++b) {
                int c = i - a - b;
                ans = max(ans, dp[a][b][c]);
            }
        }
        cout << ans << '\n';
    }


    /*for(int i = 0; i <= n; ++i) {
        int mx = 0;
        for(int a = 0; a <= i; ++a) {
            for(int b = 0; b <= i - a; ++b) {
                int c = i - a - b;
                vector<int> w;
                w.push_back(a);
                w.push_back(b);
                w.push_back(c);
                sort(w.begin(), w.end());
                mx = max(mx, p(w, 0));
            }
        }

        cout << i << ' ' <<  mx << endl;
    }*/
}