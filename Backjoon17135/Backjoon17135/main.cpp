#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int map[16][15];
int n,m,d,ans;
queue< pair<int, int> > q;
int dy[3] = {0, -1, 0};
int dx[3] = {-1, 0, 1};

int countBits(int n){
    int cnt = 0;
    while(n){
        if(n & 1) cnt++;
        n = n >> 1;
    }
    return cnt;
}
void copy_arr(int a[16][15], int b[16][15]){
    for(int y=0; y<=n; y++){
        for(int x=0; x<m; x++){
            a[y][x] = b[y][x];
        }
    }
}
void bfs(){
    bool visited[15][15] = {false,};
    int cnt = 0; bool flag = false;
    while(!q.empty()){
        if(cnt == d || flag) break;
        int size = q.size();
        for(int i=0; i<size; i++){
            auto now = q.front(); q.pop();
            int y = now.first; int x = now.second;
            for(int dir = 0; dir<3; dir++){
                int ny = y + dy[dir]; int nx = x + dx[dir];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if(!visited[ny][nx] && map[ny][nx] == 0){
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
                else if(!visited[ny][nx] && map[ny][nx] >= 1){
                    visited[ny][nx] = true;
                    if(map[ny][nx] == 1){
                        ans++; map[ny][nx] = 3;
                    }
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        cnt++;
    }
    
    while(!q.empty()) q.pop();
}
int solve(){
    int ret = 0;
    for(int subset = 0; subset < 1 << m; subset++){
        if(countBits(subset) == 3){
            int temp[16][15] = {0,};
            copy_arr(temp, map);
            for(int i=0; i<m; i++){
                if(subset & 1 << i){
                    map[n][i] = -1;
                }
            }
            for(int i=0; i<n; i++){
                for(int k=0; k<m; k++){
                    if(map[n][k] == -1){
                        q.push(make_pair(n, k));
                        bfs();
                    }
                }
                for(int y=n-2; y>=0; y--){
                    for(int x=0; x<m; x++){
                        if(map[y][x] == 3){
                            map[y+1][x] = 0;
                        }else{
                            map[y+1][x] = map[y][x];
                        }
                    }
                }
                for(int x=0; x<m; x++){
                    map[0][x] = 0;
                }
            }
            copy_arr(map, temp);
            ret = max(ret, ans);
            ans = 0;
        }
    }
    return ret;
}

int main()
{
    cin>>n>>m>>d;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin>>map[y][x];
        }
    }
    cout<<solve();
    return 0;
}
