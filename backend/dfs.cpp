#include <bits/stdc++.h>

using namespace std;

int l[] = {1, -1, 0, 0, -1, 1, -1, 1};
int c[] = {0, 0, 1, -1, -1, 1, 1, -1};

const int N = 1e4+10;

int maze[N][N];
bool mark[N][N];

int n;

void dfs(int x, int y){
    mark[x][y] = true;
    for(int i=0;i<sizeof(l)/sizeof(int);i++){
        int a = x + l[i];
        int b = y + c[i];

        if(a<0||a>=n||b<0||b>=n||mark[a][b]) continue;

        dfs(a, b);

    }
}

int main(){

    scanf()

    return 0;
}