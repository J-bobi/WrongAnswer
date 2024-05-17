#include <iostream>

using namespace std;

bool on(pair<double,double> a, pair<double,double> b, pair<double,double> p) {
    pair<double,double> v = make_pair(b.first-a.first,b.second-a.second);
    pair<double,double> w = make_pair(p.first-a.first,p.second-a.second);
    
    double l1 = v.first*w.first + v.second*w.second;
    return 0 <= l1 && l1 <= (v.first*v.first+v.second*v.second);
}

bool f(pair<double,double> a, pair<double,double> b, pair<double,double> c, pair<double,double> d ) {
    pair<double, double> v = make_pair(b.first - a.first, b.second - a.second);
    pair<double, double> w = make_pair(d.first - c.first, d.second - c.second);

    double aa = v.first;
    double bb = -w.first;
    double cc = v.second;
    double dd = -w.second;

    double det = aa * dd - bb * cc;
    if(det == 0) return on(a,b,c) || on(a,b,d) || on(c,d,a) || on(c,d,b);

    double i_a = dd / det;
    double i_b = -bb / det;
    double i_c = -cc / det;
    double i_d = aa / det;

    double z_x = c.first - a.first;
    double z_y = c.second - a.second;
    double t = i_a * z_x + i_b * z_y;
    double ww = i_c * z_x + i_d * z_y;

    return 0 <= t && t <= 1 && 0 <= ww && ww <= 1;
}

int main() {
    int n = 0;
    cin >> n;


    bool a[n];
    for(int i = 0; i < n; i++) {
        double ax,ay,bx,by,cx,cy,dx,dy;
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

        a[i] = f(make_pair(ax,ay), make_pair(bx,by), make_pair(cx,cy), make_pair(dx,dy));

    }

    for(int i = 0; i < n; i++) {
        cout << (a[i] ? "YES":"NO") << endl;
    }
}