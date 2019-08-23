#include<iostream>
#include<algorithm>
using namespace std;

struct CCTV {
    int y,x,type;
};
int map[8][8];
int n, m, ans, cctv_size;
CCTV cctv[8];
const int rot_size[5] = {4,2,4,4,1};

void backup_arr(int a[8][8], int b[8][8]){
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            a[y][x] = b[y][x];
        }
    }
}

void update(int dir, CCTV cctv){
    dir = dir % 4;
    if(dir == 0){
        for(int x=cctv.x+1; x<m; x++){
            if(map[cctv.y][x] == 6) break;
            map[cctv.y][x] = -1;
        }
    }else if(dir == 1){
        for(int y=cctv.y-1; y>=0; y--){
            if(map[y][cctv.x] == 6) break;
            map[y][cctv.x] = -1;
        }
    }else if(dir == 2){
        for(int x=cctv.x-1; x>=0; x--){
            if(map[cctv.y][x] == 6) break;
            map[cctv.y][x] = -1;
        }
    }else if(dir == 3){
        for(int y=cctv.y+1; y<n; y++){
            if(map[y][cctv.x] == 6) break;
            map[y][cctv.x] = -1;
        }
    }
}

void dfs(int cctv_idx){
    if(cctv_idx == cctv_size){
        int candi = 0;
        for(int y=0; y<n; y++){
            for(int x=0; x<m; x++){
                if(map[y][x] == 0) candi++;
            }
        }
        ans = min(ans, candi);
        return;
    }
    int backup[8][8];
    int type = cctv[cctv_idx].type;
    for(int dir = 0; dir<rot_size[type]; dir++){
        backup_arr(backup, map);
        if(type == 0){
            update(dir, cctv[cctv_idx]);
        }else if(type == 1){
            update(dir, cctv[cctv_idx]);
            update(dir+2, cctv[cctv_idx]);
        }else if(type == 2){
            update(dir, cctv[cctv_idx]);
            update(dir+1, cctv[cctv_idx]);
        }else if(type == 3){
            update(dir, cctv[cctv_idx]);
            update(dir+1, cctv[cctv_idx]);
            update(dir+2, cctv[cctv_idx]);
        }else if(type == 4){
            update(dir, cctv[cctv_idx]);
            update(dir+1, cctv[cctv_idx]);
            update(dir+2, cctv[cctv_idx]);
            update(dir+3, cctv[cctv_idx]);
        }
        dfs(cctv_idx+1);
        backup_arr(map,backup);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin>>map[y][x];
            
            if(map[y][x] != 6 && map[y][x] != 0){
                cctv[cctv_size].y = y;
                cctv[cctv_size].x = x;
                cctv[cctv_size].type = map[y][x] - 1;
                cctv_size++;
            }
        }
    }
    ans = 987654321;
    dfs(0);
    cout<<ans;
    return 0;
}
