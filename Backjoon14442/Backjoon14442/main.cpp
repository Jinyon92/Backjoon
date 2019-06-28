#include<iostream>
#include<queue>
using namespace std;

struct node{
    int a,b,block;
};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char map[1001][1001];
bool visit[1001][1001][11];
queue<node> q;
int n,m,ans,k;

void bfs(){
    while(!q.empty()){
        int s = q.size();
        while(s--){
            auto now = q.front();
            int x = now.a;
            int y = now.b;
            if(x == n-1 && y == m-1){
                cout<<ans+1;
                return;
            }
            q.pop();
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
                if(map[nx][ny] == '0' && !visit[nx][ny][now.block]){
                    visit[nx][ny][now.block] = 1;
                    q.push({nx,ny,now.block});
                }
                else if(map[nx][ny] == '1' && now.block < k && !visit[nx][ny][now.block+1]){
                    visit[nx][ny][now.block+1] = 1;
                    q.push({nx,ny,now.block+1});
                }
            }
        }
        ans++;
    }
    cout<<-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        cin>>map[i];
    }
    q.push({0,0,0});
    bfs();
}
