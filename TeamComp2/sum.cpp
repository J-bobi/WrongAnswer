#include <iostream>
#include <vector>

using namespace std;

const int n = 1 << 20;
int a[2*n+5];

struct SegmentTree {

    SegmentTree() {
        for(int i = 0; i < 2*n+5; i++)  {
            a[i] = 0;
        }
    }

    void add(int p, int x) {
        p+=n;
        a[p] += x;
        p/=2;
        while( p >= 1) {
            a[p] = a[2*p] + a[2*p+1];
            p/=2;
        }
    }

    int _sum(int l, int r, int nd, int nl, int nr) {
        if(r < nl || l > nr) return 0;
        if(nl >= l && r >= nr) return a[nd];
        int nm = (nl + nr) / 2;
        return _sum(l,r, 2*nd, nl, nm) + _sum(l, r,2*nd+1,nm+1,nr);
    }

    int sum (int l , int r) {
        return _sum(l,r,1,0,n-1);
    }

};

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    int nn;
    cin>> nn;

    SegmentTree st;
    /*
    for(int i = 0; i < n; i++) {
        st.add(5,5);
    }

    cout << st.sum(0,n-1) << endl;

    int z;
    for(int i = 0; i < n; i++) {
        z+=st.sum(0,n-1);
    }
    cout << z << endl;

    if(1)
    return 0;

    */
    for(int i = 0; i < nn; i++) {
        int x,y;
        string s;
        cin >> s >> x >> y;
        if( s== "ADD") {
            st.add(x,y);
        } else {
            cout << st.sum(x,y) << "\n";
        }
    }
}