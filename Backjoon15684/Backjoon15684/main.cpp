#include<iostream>
using namespace std;

int ladder[31][11];
int n,m,h,ans;

bool check(){
    bool flag = true;
    for(int i=1; i<=n; i++){
        int pos = i;
        for(int j=1; j<=h; j++){
            if(ladder[j][pos] == 1){
                pos++;
            }else if(ladder[j][pos-1] == 1){
                pos--;
            }
        }
        if(pos != i) return flag = false;
    }
    return flag;
}

void dfs(int cnt, int sy, int sx){
    if(cnt >= ans) return;
    if(check()){
        ans = cnt;
        return;
    }
    if(cnt == 3) return;
    
    for(int y = sy; y<=h; y++){
        for(int x = sx; x<n; x++){
            if(ladder[y][x] == 0 && ladder[y][x+1] == 0 && ladder[y][x-1] == 0){
                ladder[y][x] = 1;
                dfs(cnt+1, y, x);
                ladder[y][x] = 0;
            }
        }
        sx = 1;
    }
}

int main()
{
    cin>>n>>m>>h;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        ladder[a][b] = 1;
    }
    ans = 4;
    dfs(0,1,1);
    if(ans == 4) ans = -1;
    cout<<ans;
    return 0;
}
