#include<iostream>
#include<queue>
#include<algorithm>
#define INF 987654321
using namespace std;

int n,m;
struct POS {
    int y, x, d;
};
int map[50][50];
POS virus[10];
int virusCnt;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int countBits(int n){
    int cnt = 0;
    while(n){
        if(n & 1) cnt++;
        n = n >> 1;
    }
    return cnt;
}
int solve(){
    int ret = INF;
    for(int subset = 0; subset < 1 << virusCnt; subset++){
        if(countBits(subset) == m){
            queue<POS> q;
            bool visited[50][50] = {false,};
            for(int i=0; i<virusCnt; i++){
                if(subset & 1 << i){
                    visited[virus[i].y][virus[i].x] = true;
                    q.push(virus[i]);
                }
            }
            int dist = 0;
            while(!q.empty()){
                POS cur = q.front(); q.pop();
                if(map[cur.y][cur.x] != 2){
                    dist = max(dist, cur.d);
                }
                for(int dir = 0; dir<4; dir++){
                    int ny = cur.y + dy[dir];
                    int nx = cur.x + dx[dir];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                    if(visited[ny][nx] || map[ny][nx] == 1) continue;
                    visited[ny][nx] = true;
                    q.push({ny,nx,cur.d+1});
                }
            }
            bool flag = true;
            for(int y=0; y<n; y++){
                for(int x=0; x<n; x++){
                    if(!visited[y][x] && map[y][x] == 0) flag = false;
                }
            }
            if(flag) ret = min(ret, dist);
        }
    }
    if(ret == INF) ret = -1;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin>>map[y][x];
            if(map[y][x] == 2){
                virus[virusCnt++] = {y,x};
            }
        }
    }
    cout<<solve();
    return 0;
}
