#include<iostream>
#include<algorithm>
using namespace std;

int n, ans;
struct BOARD{
    int map[20][20];
    
    void rotate(){
        int temp[20][20];
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                temp[y][x] = map[n-x-1][y];
            }
        }
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                map[y][x] = temp[y][x];
            }
        }
    }
    
    int get_max(){
        int ret = 0;
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                ret = max(ret, map[y][x]);
            }
        }
        return ret;
    }
    
    void up(){
        int temp[20][20];
        for(int x=0; x<n; x++){
            int flag = 0, target = -1;
            for(int y=0; y<n; y++){
                if(map[y][x] == 0) continue;
                if(flag == 1 && map[y][x] == temp[target][x]){
                    temp[target][x] *= 2; flag = 0;
                }else{
                    temp[++target][x] = map[y][x]; flag = 1;
                }
            }
            for(int i=target+1; i<n; i++){
                temp[i][x] = 0;
            }
        }
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                map[y][x] = temp[y][x];
            }
        }
        
    }
};
void dfs(BOARD cur, int cnt){
    if (cnt == 5) {
        int val = cur.get_max();
        ans = max(ans, val);
        return;
    }
    
    for(int dir=0; dir<4; dir++){
        BOARD next = cur;
        next.up();
        dfs(next, cnt+1);
        cur.rotate();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    BOARD board;
    cin>>n;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin>>board.map[y][x];
        }
    }
    ans = 0;
    dfs(board, 0);
    cout<<ans;
    return 0;
}

