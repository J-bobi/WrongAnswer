#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<vector<int> > a;

    int cur = 0;
    int t = 1;

    vector<pair<int, int> > vp(n + 1);

    while (cur < n) {
        a.push_back(vector<int>(t, 0));
        for (int i = 0; i < t; ++i) {
            vp[cur + 1 + i].first = t - 1;
            vp[cur + 1 + i].second = i;
        }
        cur += t;
        ++t;
    }

    int m;
    cin >> m;

    while (m--) {
        int r;
        cin >> r;
        ++a[vp[r].first][vp[r].second];
    }

    const int MOD = 1073741723;

    for (int i = 0; i < t - 2; ++i) {
        for (int j = 0; j <= i; ++j) {
            a[i + 1][j] = (a[i + 1][j] + a[i][j]) % MOD;
            a[i + 1][j + 1] = (a[i + 1][j + 1] + a[i][j]) % MOD;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << a[vp[i].first][vp[i].second] << '\n';
    }

    return 0;
}