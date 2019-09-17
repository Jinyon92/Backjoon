#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct POS{
    int y,x;
};
int R,C,T,ans;
int map[50][50];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
vector<POS> air_cleaner;
queue<POS> q;
void spread(){
    int temp[50][50] ={0,};
    while(!q.empty()){
        POS cur = q.front(); q.pop();
        POS next; int cnt = 0, value = map[cur.y][cur.x] / 5;
        for(int dir=0; dir<4; dir++){
            next.y = cur.y + dy[dir];
            next.x = cur.x + dx[dir];
            if(next.y < 0 || next.y >= R || next.x < 0 || next.x >= C || map[next.y][next.x] == -1) continue;
            cnt++;
            temp[next.y][next.x] += value;
        }
        temp[cur.y][cur.x] += (map[cur.y][cur.x] - value*cnt);
    }
    
    for(int y=0; y<R; y++){
        for(int x=0; x<C; x++){
            map[y][x] = temp[y][x];
        }
    }
    map[air_cleaner[0].y][air_cleaner[0].x] = -1;
    map[air_cleaner[1].y][air_cleaner[0].x] = -1;
}

void blow(){
    queue<int> up; up.push(0);
    queue<int> down; down.push(0);
    int air;
    for(int x=1; x<C-1; x++){
        up.push(map[air_cleaner[0].y][x]);
    }
    for(int y=air_cleaner[0].y; y>=0; y--){
        up.push(map[y][C-1]);
    }
    for(int x=C-2; x>=0; x--){
        up.push(map[0][x]);
    }
    for(int y=1; y<air_cleaner[0].y-1; y++){
        up.push(map[y][0]);
    }
    
    for(int x=1; x<C-1; x++){
        air = up.front(); up.pop();
        map[air_cleaner[0].y][x] = air;
    }
    for(int y=air_cleaner[0].y; y>=0; y--){
        air = up.front(); up.pop();
        map[y][C-1] = air;
    }
    for(int x=C-2; x>=0; x--){
        air = up.front(); up.pop();
        map[0][x] = air;
    }
    for(int y=1; y<air_cleaner[0].y; y++){
        air = up.front(); up.pop();
        map[y][0] = air;
    }
    
    for(int x=1; x<C-1; x++){
        down.push(map[air_cleaner[1].y][x]);
    }
    for(int y=air_cleaner[1].y; y<R; y++){
        down.push(map[y][C-1]);
    }
    for(int x=C-2; x>=0; x--){
        down.push(map[R-1][x]);
    }
    for(int y=R-2; y>air_cleaner[1].y+1; y--){
        down.push(map[y][0]);
    }
    
    for(int x=1; x<C-1; x++){
        air = down.front(); down.pop();
        map[air_cleaner[1].y][x] = air;
    }
    for(int y=air_cleaner[1].y; y<R; y++){
        air = down.front(); down.pop();
        map[y][C-1] = air;
    }
    for(int x=C-2; x>=0; x--){
        air = down.front(); down.pop();
        map[R-1][x] = air;
    }
    for(int y=R-2; y>air_cleaner[1].y; y--){
        air = down.front(); down.pop();
        map[y][0] = air;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>R>>C>>T;
    
    POS pos;
    for(int y=0; y<R; y++){
        for(int x=0; x<C; x++){
            cin>>map[y][x];
            if(map[y][x] == -1){
                pos.y = y; pos.x = x;
                air_cleaner.push_back(pos);
            }
            if(map[y][x] > 0){
                pos.y = y; pos.x = x;
                q.push(pos);
            }
        }
    }
    for(int i=0; i<T; i++){
        spread();
        blow();
        for(int y=0; y<R; y++){
            for(int x=0; x<C; x++){
                if(map[y][x] > 0){
                    pos.y = y; pos.x = x;
                    q.push(pos);
                }
            }
        }
    }
    for(int y=0; y<R; y++){
        for(int x=0; x<C; x++){
            ans += map[y][x];
        }
    }
    cout<<ans+2;
    return 0;
}
