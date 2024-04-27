#include <iostream>

using namespace std;

int t = 1;
int n;
int arr[1000];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        while(t % arr[i] != 0) {
            t++;
        }
    }

    cout << t <<endl;
}