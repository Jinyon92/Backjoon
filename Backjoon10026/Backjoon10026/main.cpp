#include<iostream>
#include<cstring>
using namespace std;

int n;
char paint[101][101];
int visit[101][101];
int a[4] = {1,0,-1,0};
int b[4] = {0,1,0,-1};

void dfs(int x, int y, char key)
{
    visit[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x+a[i];
        int ny = y+b[i];
        if(nx < 0 || nx >=n || ny < 0 || ny >= n) continue;
        if(paint[nx][ny] == key && !visit[nx][ny]){
            dfs(nx, ny, key);
        }
    }
}
void rg_dfs(int x, int y, char key)
{
    visit[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x+a[i];
        int ny = y+b[i];
        if(nx < 0 || nx >=n || ny < 0 || ny >= n) continue;
        if(paint[nx][ny] == key && !visit[nx][ny]){
            rg_dfs(nx,ny,key);
        }
        if(key == 'R' && paint[nx][ny] == 'G' && !visit[nx][ny]){
            rg_dfs(nx,ny,paint[nx][ny]);
        }
        if(key == 'G' && paint[nx][ny] == 'R' && !visit[nx][ny]){
            rg_dfs(nx,ny,paint[nx][ny]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>paint[i][j];
    
    char k;
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visit[i][j]){
                ans += 1;
                k = paint[i][j];
                dfs(i,j,k);
            }
        }
    }
    cout<<ans<<"\n";
    ans = 0;
    memset(visit, 0, sizeof(visit));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visit[i][j]){
                ans += 1;
                k = paint[i][j];
                rg_dfs(i,j,k);
            }
        }
    }
    cout<<ans;
    return 0;
}
