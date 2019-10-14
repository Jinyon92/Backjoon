#include<iostream>
#include<queue>
using namespace std;

struct INFO{
    int ry,rx,by,bx,cnt;
} start;
int n,m;
char map[10][10];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int bfs(){
    queue<INFO> q;
    bool visited[10][10][10][10] = {false,};
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = true;
    
    int ret = 0;
    while(!q.empty()){
        auto now = q.front(); q.pop();
        if(now.cnt > 10) break;
        if(map[now.ry][now.rx] == 'O' && map[now.by][now.bx] != 'O'){
            ret = 1; break;
        }
        
        for(int dir = 0; dir<4; dir++){
            int next_ry = now.ry;
            int next_rx = now.rx;
            int next_by = now.by;
            int next_bx = now.bx;
            
            while(1){
                if(map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O'){
                    next_ry += dy[dir]; next_rx += dx[dir];
                }else{
                    if(map[next_ry][next_rx] == '#'){
                        next_ry -= dy[dir]; next_rx -= dx[dir];
                    }
                    break;
                }
            }
            while(1){
                if(map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O'){
                    next_by += dy[dir]; next_bx += dx[dir];
                }else{
                    if(map[next_by][next_bx] == '#'){
                        next_by -= dy[dir]; next_bx -= dx[dir];
                    }
                    break;
                }
            }
            
            if(next_ry == next_by && next_rx == next_bx){
                if(map[next_ry][next_rx] != 'O'){
                    int red_dist = abs(now.ry - next_ry) + abs(now.rx - next_rx);
                    int blue_dist = abs(now.by - next_by) + abs(now.bx - next_bx);
                    if(red_dist > blue_dist){
                        next_ry -= dy[dir]; next_rx -= dx[dir];
                    }else{
                        next_by -= dy[dir]; next_bx -= dx[dir];
                    }
                }
            }
            
            if(!visited[next_ry][next_rx][next_by][next_bx]){
                visited[next_ry][next_rx][next_by][next_bx] = true;
                q.push({next_ry,next_rx,next_by,next_bx,now.cnt+1});
            }
        }
    }
    return ret;
}

int main()
{
    cin>>n>>m;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin>>map[y][x];
            if(map[y][x] == 'R'){
                start.ry = y; start.rx = x;
            }
            if(map[y][x] == 'B'){
                start.by = y; start.bx = x;
            }
        }
    }
    start.cnt = 0;
    cout<<bfs();
    return 0;
}
