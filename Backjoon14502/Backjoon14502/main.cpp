#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int map[8][8];
int n,m,ans;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
queue< pair<int, int> >q;

void bfs(){
    int temp[8][8];
    int visited[8][8] = {0,};
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            temp[y][x] = map[y][x];
            if(temp[y][x] == 2){
                q.push(make_pair(y, x));
            }
        }
    }
    
    while(!q.empty()){
        auto now = q.front();
        int y = now.first;
        int x = now.second;
        q.pop();
        for(int dir=0; dir<4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >=m) continue;
            if(temp[ny][nx] == 0 && !visited[ny][nx]){
                q.push(make_pair(ny, nx));
                temp[ny][nx] = 2;
                visited[ny][nx] = 1;
            }
        }
    }
    
    int ret = 0;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(temp[y][x] == 0)
                ret++;
        }
    }
    ans = max(ans,ret);
}

void pick_three(int cnt, int sy, int sx){
    if(cnt == 3){
        bfs();
        return;
    }
    
    for(int y=sy; y < n; y++){
        for(int x=sx; x<m; x++){
            if(map[y][x] == 0){
                map[y][x] = 1;
                pick_three(cnt+1, y, x);
                map[y][x] = 0;
            }
        }
        sx=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin>>map[y][x];
        }
    }
    pick_three(0,0,0);
    cout<<ans;
}
