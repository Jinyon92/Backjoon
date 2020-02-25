#include<iostream>
using namespace std;

int map[10][10];
int visited[10][10];
int n, ans1, ans2;
int dy[4] = {1,1,-1,-1};
int dx[4] = {1,-1,1,-1};

void dfs(int cur_y, int cur_x, int add){
    visited[cur_y][cur_x] += add;
    
    int ny = cur_y;
    int nx = cur_x;
    while(1){
        ny += dy[0];
        nx += dx[0];
        if(ny >= n || nx >= n) break;
        
        visited[ny][nx] += add;
    }
    ny = cur_y;
    nx = cur_x;
    while(1){
        ny += dy[1];
        nx += dx[1];
        if(ny >= n || nx < 0) break;
        visited[ny][nx] += add;
    }
    ny = cur_y;
    nx = cur_x;
    while(1){
        ny += dy[2];
        nx += dx[2];
        if(ny < 0 || nx >= n) break;
        visited[ny][nx] += add;
    }
    ny = cur_y;
    nx = cur_x;
    while(1){
        ny += dy[3];
        nx += dx[3];
        if(ny < 0 || nx < 0) break;
        visited[ny][nx] += add;
    }
    
}

void black_search(int sy, int sx, int cnt){
    for(int y=sy; y<n; y++){
        for(int x=sx; x<n; x+=2){
            if(map[y][x] == 1 && visited[y][x] == 0){
                dfs(y,x,1);
                black_search(y,x+2,cnt+1);
                dfs(y,x,-1);
            }
        }
        if(y % 2 == 0) sx = 1;
        else sx = 0;
    }
    
    if(ans1 < cnt) ans1 = cnt;
}

void white_search(int sy, int sx, int cnt){
    for(int y=sy; y<n; y++){
        for(int x=sx; x<n; x+=2){
            if(map[y][x] == 1 && visited[y][x] == 0){
                dfs(y,x,1);
                white_search(y,x+2,cnt+1);
                dfs(y,x,-1);
            }
        }
        if(y % 2 == 0) sx = 0;
        else sx = 1;
    }
    
    if(ans2 < cnt) ans2 = cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin>>map[y][x];
        }
    }
    black_search(0,0,0);
    white_search(0,1,0);
    cout<<ans1 + ans2;
    return 0;
}
