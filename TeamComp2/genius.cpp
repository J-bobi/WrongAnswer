#include <iostream>
#include <set>

using namespace std;

#define impossible 0
#define take 1
#define dont 2

int main() {
    int n;
    cin >> n;

    int arr[n];
    int sum;
    for(int i = 0; i < n; i++) {
        cin >> arr[n-i-1];
        sum += arr[n-i-1];
    }

    int field[n+1][sum/2+2];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum/2; j++) {
            field[i][j] = impossible;
        }
    }

    field[0][0] = dont;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= sum/2; j++) {

            if(field[i-1][j] != impossible) {
                field[i][j] = dont;
            } else if(j - arr[i-1] >= 0 && field[i-1][j - arr[i-1]] != impossible) {
                field[i][j] = take;
            }
        }
    }

    int i=n,j=sum/2;
    while(i>0) {
        if(field[i][j] == take) {
            cout << "YES" << endl;
            j-= arr[i-1];
        } else {
            cout << "NO" << endl;
        }
        i--;
    }
}