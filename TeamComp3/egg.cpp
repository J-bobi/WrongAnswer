#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

double euc(double d1, double d2) {
    return sqrt(d1*d1+d2*d2);
}

int main() {
    int t;
    cin >> t;

    double x[t];
    double y[t];

    vector<int> arr(t);

    for(int i = 0; i < t; i++) {
        cin >> x[i] >> y[i];
        arr[i] = i;
    }

    double mind = INFINITY;
    do {
        double sum = 0;
        for(int i = 0; i < t; i++) {
            sum += euc(x[arr[i]]-x[(arr[(i+1)%t])] , y[arr[i]]-y[(arr[(i+1)%t])]);
        }
        mind = min(sum, mind);
    } while (next_permutation(arr.begin(), arr.end()));

    cout << std::setprecision(12) << mind << endl;
}