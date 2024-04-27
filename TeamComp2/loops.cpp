#include <iostream>
#include <string>

using namespace std;

string t(string s) {
    int l = (s[s.length()-1]-'0') + 10 * (s[s.length()-2] - '0');

    string r = s;

    if( l < 28)
    for(int i = 0; i < 28; i++) {
        r[i] = s[(l+i)%28];
    }

    for(int i = 27; i >=0; i--) {
        if(++r[i] <= '9') 
            break;
        r[i] = '0';
    }

    return r;
}

int main() {

    string s;
    getline(cin, s);

    //cout << s << " " << t(s) << endl;

    int i = 0;
    string slow = s;
    string fast = s;

    do {
        slow = t(slow);
        fast = t(t(fast));
        i++;
    } while (slow != fast);

    i=0;
    do {
        fast = t(fast);
        i++;
    } while(slow != fast);

    cout << i << endl;
}