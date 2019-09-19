#include<iostream>
#include<cstring>
using namespace std;

struct SHARK {
    int speed, dir, size;
};
SHARK map[100][100];
int R,C,M,ans;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

void catch_shark(int pos){
    for(int y=0; y<R; y++){
        if(map[y][pos].size != 0){
            ans += map[y][pos].size;
            map[y][pos].size = 0;
            break;
        }
    }
}
void move_shark(){
    SHARK backup[100][100];
    memcpy(backup, map, sizeof(map));
    memset(map, 0, sizeof(map));
    
    for(int y=0; y<R; y++){
        for(int x=0; x<C; x++){
            SHARK &cur = backup[y][x];
            if(cur.size > 0){
                int ny = y + cur.speed * dy[cur.dir]; int nx = x + cur.speed * dx[cur.dir];
                if(ny < 0 ){
                    ny = -ny;
                    cur.dir = 1;
                }
                if(ny > R - 1){
                    int a = ny / (R-1);
                    int b = ny % (R-1);
                    if(a % 2 == 0){
                        ny = b;
                    }else{
                        ny = R - 1 - b;
                        cur.dir = 0;
                    }
                }
                if(nx < 0){
                    nx = -nx;
                    cur.dir = 2;
                }
                if(nx > C-1){
                    int a = nx / (C-1);
                    int b = nx % (C-1);
                    if(a%2 == 0){
                        nx = b;
                    }else{
                        nx = C - 1 -b;
                        cur.dir = 3;
                    }
                }
                if(map[ny][nx].size < cur.size){
                    map[ny][nx] = cur;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>R>>C>>M;
    
    int r,c,s,d,z;
    for(int i=0; i<M; i++){
        cin>>r>>c>>s>>d>>z;
        map[r-1][c-1] = {s,d-1,z};
    }
    for(int pos = 0; pos < C; pos++){
        catch_shark(pos);
        move_shark();
    }
    cout<<ans;
    return 0;
}
