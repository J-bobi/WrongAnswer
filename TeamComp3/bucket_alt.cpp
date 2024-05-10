#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

map<vector<int>, int> memo;
set<vector<int> > visited;

int p(vector<int> v, int d) {
    cout << "depth = " << d << endl;
    // cout << v[0] << " " << v[1] << " " << v[2] << endl; 
    if(memo.find(v) != memo.end()) {
        return memo[v];
    }

    if(v[0] == 0) {
        memo[v] = 0;
        return 0;
    }

    int mn = INFINITY;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == j || v[i] < v[j]) continue;

            cout << " " << i << " " << j << endl;

            int missing = 3 - i - j;
            vector<int> w(3);
            w[missing] = v[missing];
            w[i] = v[i] - v[j];
            w[j] = 2 * v[j];

            sort(w.begin(), w.end());

            if(w == v) continue;

            mn = min(mn, p(w, d + 1) + 1);
        }
    }

    memo[v] = mn;
    return mn;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i <= n; ++i) {
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
    }
}