#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;


void bfs(vector<string> &grid) {
    queue<pair<int,int> > q;
    
    map<pair<int,int>,pair<int,int> > last;
    
    q.push(make_pair(1,1));
    
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        if(grid[p.first+1][p.second] == ' '){
            q.push(make_pair(p.first+1, p.second));
            last[make_pair(p.first+1,p.second)] = p;
            grid[p.first+1][p.second] = 'v';
        }
        if(grid[p.first-1][p.second] == ' '){
            q.push(make_pair(p.first-1, p.second));
            last[make_pair(p.first-1,p.second)] = p; 
            grid[p.first-1][p.second] = 'v';
        }
        if(grid[p.first][p.second+1] == ' '){
            q.push(make_pair(p.first, p.second+1));
            last[make_pair(p.first,p.second+1)] = p;
            grid[p.first][p.second+1] = 'v';
        }
        if(grid[p.first][p.second-1] == ' '){
            q.push(make_pair(p.first, p.second-1));
            last[make_pair(p.first,p.second-1)] = p;
            grid[p.first][p.second-1] = 'v';
        }
        
    }

    pair<int,int> p = make_pair(1, grid[1].length()-2);
    do {
        grid[p.first][p.second] = '.';
        p = last[p];
    } while(p.first != 1 || p.second != 1);
    grid[1][1] = '.';
}


int main() {
    int n;
    cin >> n;

    vector<string> grid(n);

    getline(cin, grid[0]);
    for(int i = 0; i < n; i++) {
        getline(cin, grid[i]);
    }

    bfs(grid);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < grid[i].length(); j++) {
            if(grid[i][j] == 'v')
                cout << ' ';
            else
                cout << grid[i][j];
        }
        cout << "\n";
    }
}