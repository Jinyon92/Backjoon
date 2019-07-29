#include<iostream>
#include<queue>
using namespace std;

int n,m,r,c,d,ans;
int map[50][50];
queue< pair< pair<int, int> , int> > que;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

bool already_clean(int y, int x){
    for(int dir = 0; dir<4; dir++){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(map[ny][nx] == 1 || map[ny][nx] == 2) {continue;}
        else {return false;}
    }
    return true;
}

void bfs(){
    while(!que.empty()){
        auto now = que.front();
        int y = now.first.first;
        int x = now.first.second;
        int dir = now.second;
        que.pop();
        int nx,ny;
        if(already_clean(y, x)){
            if(dir == 0){
                ny = y + dy[2];
                nx = x + dx[2];
                if(map[ny][nx] == 1) return;
                else que.push(make_pair(make_pair(ny, nx), 0));
            }else if(dir == 1){
                ny = y + dy[3];
                nx = x + dx[3];
                if(map[ny][nx] == 1) return;
                else que.push(make_pair(make_pair(ny, nx), 1));
            }else if(dir == 2){
                ny = y + dy[0];
                nx = x + dx[0];
                if(map[ny][nx] == 1) return;
                else que.push(make_pair(make_pair(ny, nx), 2));
            }else{
                ny = y + dy[1];
                nx = x + dx[1];
                if(map[ny][nx] == 1) return;
                else que.push(make_pair(make_pair(ny, nx), 3));
            }
        }else{
            if(dir == 0){
                ny = y + dy[3];
                nx = x + dx[3];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if(map[ny][nx] == 0){
                    map[ny][nx] = 2;
                    que.push(make_pair(make_pair(ny, nx), 3));
                    ans += 1;
                }else{
                    que.push(make_pair(make_pair(y, x), 3));
                }
            }else if(dir == 1){
                ny = y + dy[0];
                nx = x + dx[0];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if(map[ny][nx] == 0){
                    map[ny][nx] = 2;
                    que.push(make_pair(make_pair(ny, nx), 0));
                    ans += 1;
                }else{
                    que.push(make_pair(make_pair(y, x), 0));
                }
            }else if(dir == 2){
                ny = y + dy[1];
                nx = x + dx[1];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if(map[ny][nx] == 0){
                    map[ny][nx] = 2;
                    que.push(make_pair(make_pair(ny, nx), 1));
                    ans += 1;
                }else{
                    que.push(make_pair(make_pair(y, x), 1));
                }
            }else{
                ny = y + dy[2];
                nx = x + dx[2];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if(map[ny][nx] == 0){
                    map[ny][nx] = 2;
                    que.push(make_pair(make_pair(ny, nx), 2));
                    ans += 1;
                }else{
                    que.push(make_pair(make_pair(y, x), 2));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m>>r>>c>>d;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin>>map[y][x];
        }
    }
    que.push(make_pair(make_pair(r, c),d));
    ans = 1;
    map[r][c] = 2;
    bfs();
    cout<<ans;
}
