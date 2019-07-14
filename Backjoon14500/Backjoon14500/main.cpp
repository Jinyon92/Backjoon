#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int map[500][500];
int visited[500][500];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int n,m,ans;
queue< pair<int, int> > q;

void dfs(int y, int x, int cnt, int value){
    if(cnt == 3){
        ans = max(ans, value);
    }else{
        for(int dir = 0; dir<4; dir++){
            int ny = y+dy[dir];
            int nx = x+dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(!visited[ny][nx]){
                visited[ny][nx] = 1;
                dfs(ny,nx,cnt+1,value+map[ny][nx]);
                visited[ny][nx] = 0;
            }
        }
    }
}
void bfs(int y, int x){
    for(int dir = 0; dir<4; dir++){
        int ny = y+dy[dir];
        int nx = x+dx[dir];
        if(ny < 0 || ny >=n || nx < 0 || nx >= m) continue;
        q.push(make_pair(ny, nx));
    }
    
    int arr[5];
    int size = q.size();
    int value = 0;
    if(size == 4){
        for(int i=0; i<size; i++){
            arr[i] = map[q.front().first][q.front().second];
            q.pop();
            value += arr[i];
        }
        ans = max(ans,value);
    }
    else if(size == 5){
        for(int i=0; i<size; i++){
            arr[i] = map[q.front().first][q.front().second];
            q.pop();
        }
        value = arr[0]+arr[1]+arr[2]+arr[3];
        ans = max(ans,value);
        value = arr[0]+arr[2]+arr[3]+arr[4];
        ans = max(ans,value);
        value = arr[0]+arr[1]+arr[2]+arr[4];
        ans = max(ans,value);
        value = arr[0]+arr[1]+arr[3]+arr[4];
        ans = max(ans,value);
    }else{
        while(!q.empty()){
            q.pop();
        }
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
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            visited[y][x] = 1;
            dfs(y,x,0,map[y][x]);
            visited[y][x] = 0;
        }
    }
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            q.push(make_pair(y,x));
            bfs(y,x);
        }
    }
    cout<<ans;
    return 0;
}
