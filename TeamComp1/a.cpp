#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DSU {
    vector<int> p;

    DSU(int n) {
        p.assign(n,-1);
    }

    int find_set(int v) {
        if(p[v] < 0) {
            return v;
        }
        p[v] = find_set(p[v]);
        return p[v];
    }

    void unite(int u, int v) {
        int pu = find_set(u);
        int pv = find_set(v);

        if(pu == pv) {
            return;
        }
        if(p[pu] > p[pv]) {
            swap(pu,pv);
        }
        p[pu] += p[pv];
        p[pv] = pu;
    }

};

int main() {
    int n,m;
    cin >> n >> m;

    map<string,int> id;
    vector<string> name(m);
    vector< vector<int> > e(m);

    for(int i = 0; i < m; i++) {
        string u,v;
        int t;
        cin >> u >> v >> name[i] >> t;
        if(id.find(u) == id.end()){
            id[u] = (int) id.size();
        }
        if(id.find(v) == id.end()) {
            id[v] = (int) id.size();
        }
        e[i].resize(4);
        e[i][0] = t;
        e[i][1] = i;
        e[i][2] = id[u];
        e[i][3] = id[v];
    }

    sort(e.begin(),e.end());

    DSU dsu(id.size());

    vector<bool> build(m, false);
    long long ans = 0;
    for(int i = 0; i < m; i++) {
        int t = e[i][0];
        int u = e[i][2];
        int v = e[i][3];
        if(dsu.find_set(u) != dsu.find_set(v)) {
            dsu.unite(u,v);
            build[e[i][1]] = true;
            ans += t;
        }
    }

    cout << n-1 << "\n" << ans << "\n";

    for(int i = 0; i < m; i++){
        if(build[i]) {
            cout << name[i] << '\n';
        }
    }

    return 0;
}