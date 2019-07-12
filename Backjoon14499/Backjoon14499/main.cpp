#include<iostream>
#include<queue>
using namespace std;

int dice[6];
int map[21][21];
int n,m;
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};

void move_dice(int d){
    int ndice[6];
    if(d == 0){
        ndice[3] = dice[4];
        ndice[1] = dice[5];
        ndice[5] = dice[3];
        ndice[4] = dice[1];
        ndice[2] = dice[2];
        ndice[0] = dice[0];
    }
    else if(d == 1){
        ndice[3] = dice[5];
        ndice[1] = dice[4];
        ndice[5] = dice[1];
        ndice[4] = dice[3];
        ndice[2] = dice[2];
        ndice[0] = dice[0];
    }
    else if(d == 2){
        ndice[4] = dice[4];
        ndice[5] = dice[5];
        ndice[1] = dice[0];
        ndice[2] = dice[1];
        ndice[3] = dice[2];
        ndice[0] = dice[3];
    }
    else{
        ndice[4] = dice[4];
        ndice[5] = dice[5];
        ndice[1] = dice[2];
        ndice[3] = dice[0];
        ndice[2] = dice[3];
        ndice[0] = dice[1];
    }
    for(int i=0; i<6; i++){
        dice[i] = ndice[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int sx,sy,k;
    cin>>n>>m>>sy>>sx>>k;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin>>map[y][x];
        }
    }
    int dir;
    for(int i=0; i<k; i++){
        cin>>dir;
        dir--;
        int ny = sy + dy[dir];
        int nx = sx + dx[dir];
        if(ny < 0 || ny >=n || nx < 0 || nx >= m) continue;
        move_dice(dir);
        
        if(map[ny][nx] == 0){
            map[ny][nx] = dice[1];
        }else{
            dice[1] = map[ny][nx];
            map[ny][nx] = 0;
        }
        cout<<dice[3]<<"\n";
        sy = ny; sx = nx;
    }
    return 0;
}
