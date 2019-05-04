#include<iostream>
#include<algorithm>
using namespace std;

int a[4] ={1,0,-1,0};
int b[4] ={0,1,0,-1};
int visit[26];
char map[20][20];
int ans;
int r,c;

void dfs(int cnt, int x, int y)
{
    for(int i=0; i<4; i++){
        int nextX = x+a[i];
        int nextY = y+b[i];
        if(nextX >=r || nextX <0 || nextY >=c || nextY <0) continue;
        int ascii = map[nextX][nextY]-65;
        if(!visit[ascii]){
            visit[ascii]++;
            dfs(cnt+1,nextX,nextY);
            visit[ascii]--;
        }else{
            ans = max(ans, cnt);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>r>>c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin>>map[i][j];
    visit[map[0][0]-65] = 1;
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
