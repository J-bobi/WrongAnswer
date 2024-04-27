#include <iostream>
#include <map>
#include <queue>
#include <cassert>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    map<string, int> id;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        if(id.find(s[i]) == id.end() ) id[s[i]] = i;
        assert(s[i].length() == 5);
    }

    vector<vector<int> > g(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            for( char c = (char)0; c < (char)128; c++) {
                string y = s[i];
                y[j]=c;
                if(id.find(y) != id.end()) {
                    g[i].push_back(id[y]);
                }
            }
        }
    }

    int m;
    cin >> m;

    for(int i =0; i < m ; i++) {
        string u,v;
        cin >> u>> v;
        assert(id.find(u) != id.end() && id.find(v) != id.end());
        vector<int> dist(n, n);
        dist[id[u]]=0;
        queue<int> q;
        q.push(id[u]);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(int y : g[x]) {
                if(dist[y]==n) {
                    dist[y] =dist[x]+1;
                    q.push(y);
                }
            }
        }
        if(dist[id[v]] == n) {
            cout << -1 << endl;
        }
        else {
            cout << dist[id[v]] << endl;
        }
    }
}