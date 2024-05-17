#include <iostream>

#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<pair<int,int> > m;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        m.push(make_pair(a[i], i));
    }

    long long sum = 0;
    while(!m.empty()) {
        pair<int,int> p = m.top();
        m.pop();
        int x = p.first;
        int i = p.second;

        if(x == a[i]) {
            if(i+1 < n && abs(a[i+1] - a[i]) > 1) {
                sum += a[i] - a[i+1] -1;
                a[i+1] = a[i]-1;
                m.push(make_pair(a[i+1], i+1));
            }
            if(i > 0 && abs(a[i-1] - a[i]) > 1) {
                sum += a[i] - a[i-1] -1;
                a[i-1] = a[i]-1;
                m.push(make_pair(a[i-1], i-1));
            }
        }
    }

    cout << sum << endl;
}
