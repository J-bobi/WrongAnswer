#include <iostream>

using namespace std;

bool test(string s) {
    for(int i = 0; i <= s.length()/2; i++) {
        if(s[i] != s[s.length()-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {

    int t = 0;
    cin >> t;

    for(;t;t--) {
        string s;
        cin >> s;

        std::cout << (test(s) ? "YES" : "NO") << "\n";
    }
}