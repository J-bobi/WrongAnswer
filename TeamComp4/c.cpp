#include <iostream>
#include <iomanip>
using namespace std;

const int N = 500;
int n;

long double a[500];
long double b[500]; 

long double f(long double x) {
    long double sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += abs(x - a[i]);
    }
    for(int i = 0; i < n; i++) {
        sum += (x - b[i]) * (x - b[i]);
    }

    return sum;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        //cin >> b[i];
        //cout << a[i] << endl;
    }
    for(int i = 0; i < n; ++i) { 
        cin >> b[i];
        //cout << b[i] << endl;
    }

    long double L = -10;
    long double R = 100000;

    while(abs(R - L) > 0.0000000001) {
        long double f_L = f(L);
        long double f_R = f(R);
        long double w = L + ((R-L) / 3.0);
        long double u = L + (2.0 * (R - L) / 3.0);
        long double f_w = f(w);
        long double f_u = f(u);

        if(f_w < f_u) {
            R = u;
        } else if(f_w == f_u) {
            L = w;
            R = u;
        } else {
            L = w;
        }
        //cout << L << " " << R << endl;
    } 

    //cout << L << endl;
    //cout << R << endl;
    cout << setprecision(16) << ((R + L) / 2) << endl;
    //cout << f(1.99999997) << endl;
}