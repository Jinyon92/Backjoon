#include<iostream>
#include<vector>
using namespace std;
#define INF 987654321

int papercnt[6];
int ans = INF;

void dfs(int cnt, int x, int y, int size, vector< vector<int> >map)
{
    bool zeroCheck = true;
    if(cnt > ans) return;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(map[i][j] == 1){
                zeroCheck = false;
                break;
            }
        }
        if(!zeroCheck) break;
    }
    if(zeroCheck){
        if(ans > cnt-1) ans = cnt-1;
        if(ans == -1) ans = 0;
        return;
    }
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(i >= 10 || j >= 10 || map[i][j] == 0) return;
            map[i][j] = 0;
        }
    }
    int nextX = 0;
    int nextY = 0;
    bool flag = false;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(map[i][j] == 1){
                nextX = i; nextY = j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    for(int i=5; i>0; i--){
        if(papercnt[i] == 5) continue;
        papercnt[i]++;
        dfs(cnt+1, nextX, nextY, i, map);
        papercnt[i]--;
    }
}

int main()
{
    vector< vector<int> > map(10, vector<int>(10, 0));
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            cin>>map[i][j];
    dfs(0,0,0,0,map);
    if(ans == INF) cout<<-1;
    else cout<<ans;
    return 0;
}
