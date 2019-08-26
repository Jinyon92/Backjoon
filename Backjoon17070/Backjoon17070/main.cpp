#include<iostream>
using namespace std;

int n, ans;
int map[16][16];

void dfs(int y, int x, int type){
    if(y == n-1 && x == n-1){
        ans++;
        return;
    }
    if(type == 1){
        if(x+1 < n){
            if(map[y][x+1] != 1){
                dfs(y,x+1,1);
            }
        }
        if(x+1 < n && y+1 < n){
            if(map[y][x+1] != 1 && map[y+1][x] != 1 && map[y+1][x+1] != 1){
                dfs(y+1, x+1, 2);
            }
        }
    }else if(type == 2){
        if(x+1 < n){
            if(map[y][x+1] != 1){
                dfs(y,x+1,1);
            }
        }
        if(x+1 < n && y+1 < n){
            if(map[y][x+1] != 1 && map[y+1][x] != 1 && map[y+1][x+1] != 1){
                dfs(y+1, x+1, 2);
            }
        }
        if(y+1 < n){
            if(map[y+1][x] != 1){
                dfs(y+1, x, 3);
            }
        }
    }else if(type == 3){
        if(x+1 < n && y+1 < n){
            if(map[y][x+1] != 1 && map[y+1][x] != 1 && map[y+1][x+1] != 1){
                dfs(y+1, x+1, 2);
            }
        }
        if(y+1 < n){
            if(map[y+1][x] != 1){
                dfs(y+1, x, 3);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin>>map[y][x];
        }
    }
    dfs(0,1,1);
    cout<<ans;
    return 0;
}
