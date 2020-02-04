#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

int m,n;
int map[100][100];
bool visited[100][100];
int target_y, target_x;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int ans = INT_MAX;

void dfs(int y, int x, int pre_dir, int cnt){
    if(ans <= cnt) return;
    if(y == target_y && x == target_x){
        ans = min(cnt, ans);
        return;
    }
    
    for(int dir=0; dir<4; dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        
        if(!visited[ny][nx] && map[ny][nx] == 1){
            visited[ny][nx] = true;
            if(pre_dir != dir) dfs(ny,nx,dir,cnt+1);
            else dfs(ny,nx,dir,cnt);
            visited[ny][nx] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>m>>n;
    cin>>target_y>>target_x;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin>>map[y][x];
        }
    }
    visited[0][0] = true;
    dfs(0,0,-1,0);
    cout<<ans-1;
    return 0;
}
