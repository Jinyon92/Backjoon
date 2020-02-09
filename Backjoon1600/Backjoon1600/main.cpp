#include<iostream>
#include<queue>
using namespace std;

struct INFO {
    int y,x,horse,cnt;
};
int k,h,w;
int map[200][200];
queue<INFO> q;
bool visited[200][200][31];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int hdy[8] = {-2,-2,-1,-1,1,1,2,2};
int hdx[8] = {-1,1,-2,2,-2,2,1,-1};

int bfs(){
    q.push({0,0,0,0});
    visited[0][0][0] = true;
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        int y = now.y;
        int x = now.x;
        int horse = now.horse;
        int cnt = now.cnt;
        
        if(y == h-1 && x == w-1) return cnt;
        if(horse < k){
            for(int dir = 0 ; dir<8; dir++){
                int ny = y + hdy[dir];
                int nx = x + hdx[dir];
                if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                
                if(!visited[ny][nx][horse+1] && map[ny][nx] == 0){
                    visited[ny][nx][horse+1] = true;
                    q.push({ny,nx,horse+1,cnt+1});
                }
            }
        }
        
        for(int dir=0; dir<4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            
            if(!visited[ny][nx][horse] && map[ny][nx] == 0){
                visited[ny][nx][horse] = true;
                q.push({ny,nx,horse,cnt+1});
            }
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>k>>w>>h;
    
    for(int y=0; y<h; y++){
        for(int x=0; x<w; x++){
            cin>>map[y][x];
        }
    }
    
    int ans = bfs();
    cout<<ans;
    return 0;
}

