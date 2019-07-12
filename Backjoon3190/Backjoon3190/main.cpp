#include<iostream>
#include<queue>
using namespace std;

int map[100][100];
int n,k,l,x,y,cnt;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
queue< pair<int, int> > q;
bool flag = true;

void move_baam(int s, int d){
    if(!flag) return;
    for(int i=0; i<s; i++){
        int ny = y + dy[d];
        int nx = x + dx[d];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n){
            cnt++;
            flag = false;
            return;
        }
        cnt++;
        if(map[ny][nx] == 0){
            map[ny][nx] = 2;
            q.push(make_pair(ny, nx));
            auto tail = q.front();
            map[tail.first][tail.second] = 0;
            q.pop();
        }
        else if(map[ny][nx] == 1){
            map[ny][nx] = 2;
            q.push(make_pair(ny,nx));
        }
        else if(map[ny][nx] == 2){
            flag = false;
            return;
        }
        y = ny;
        x = nx;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>k;
    int ay,ax;
    for(int i=0; i<k; i++){
        cin>>ay>>ax;
        map[ay-1][ax-1] = 1;
    }
    cin>>l;
    int dir = 3;
    char choice;
    int initT;
    x=0; y=0; cnt = 0;
    map[y][x] = 2;
    q.push(make_pair(y,x));
    int lastT = 0;
    for(int i=0; i<l; i++){
        cin>>initT>>choice;
        move_baam(initT-lastT, dir);
        if(dir == 3 && choice == 'L'){
            dir = 0;
        }else if(dir == 3 && choice == 'D'){
            dir = 1;
        }else if(dir == 0 && choice == 'L'){
            dir = 2;
        }else if(dir == 0 && choice == 'D'){
            dir = 3;
        }else if(dir == 1 && choice == 'L'){
            dir = 3;
        }else if(dir == 1 && choice == 'D'){
            dir = 2;
        }else if(dir == 2 && choice == 'L'){
            dir = 1;
        }else if(dir == 2 && choice == 'D'){
            dir = 0;
        }
        lastT = initT;
    }
    if(flag){
        move_baam(100, dir);
    }
    cout<<cnt;
    return 0;
}
