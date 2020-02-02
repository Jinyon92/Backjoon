#include<iostream>
using namespace std;

int n,m,k;
int arr[10][10];
int ans = -1e9;
bool visited[10][10];

void dfs(int y, int x, int cnt, int sum){
    if(cnt == k) ans = max(ans, sum);
    else if(x >= m) dfs(y+1,0,cnt,sum);
    else if(y != n){
        if(y-1 == -1 || !visited[y-1][x]){
            visited[y][x] = true;
            dfs(y,x+2,cnt+1,sum+arr[y][x]);
            visited[y][x] = false;
        }
        dfs(y,x+1,cnt,sum);
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin>>arr[y][x];
        }
    }
    dfs(0,0,0,0);
    cout<<ans;
    return 0;
}
