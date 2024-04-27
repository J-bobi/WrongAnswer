#include <iostream>

using namespace std;

struct node {
    int x,y;
};


int n,m;
char arr[100][100];
bool visited[100][100];

void dfs(int i, int j) {
    if(i < 0 || i >=n || j < 0 || j >= m || visited[i][j] || arr[i][j] == '#') {
        return;
    }

    visited[i][j] = 1;

    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);

}

int main() {
    cin >> n;
    cin >> m;


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        dfs(i,m-1);
        dfs(i,0);
    }
    for(int j = 0; j < m; j++) {
        dfs(0,j);
        dfs(n-1,j);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == '.' && visited[i][j]) {
                cout << ".";
            }
            else if(arr[i][j] == '.' && !visited[i][j]) {
                cout << "~";
            }
            else {
                cout << "#";
            }
        }
        cout << "\n";
    }


}