#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

struct SHARK{
    int y,x,move;
};
bool cmp(SHARK a, SHARK b){
    if(a.y != b.y) return a.y < b.y;
    else return a.x < b.x;
}
int map[20][20], visited[20][20];
int n, ans, shark_size, shark_eat;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
queue<SHARK> q;
vector<SHARK> candi;

void bfs(){
    while (!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++){
            SHARK cur = q.front(); q.pop();
            for(int dir = 0; dir<4; dir++){
                SHARK next;
                next.y = cur.y + dy[dir];
                next.x = cur.x + dx[dir];
                next.move = cur.move + 1;
                if(next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) continue;
                
                if(!visited[next.y][next.x] && (map[next.y][next.x] == 0 || map[next.y][next.x] == shark_size)){
                    visited[next.y][next.x] = 1;
                    q.push(next);
                }
                else if(!visited[next.y][next.x] && map[next.y][next.x] < shark_size){
                    visited[next.y][next.x] = 1;
                    candi.push_back(next);
                }
            }
        }
        
        if(candi.size() != 0){
            sort(candi.begin(), candi.end(), cmp);
            ans += candi[0].move;
            map[candi[0].y][candi[0].x] = 0;
            shark_eat += 1;
            if(shark_eat == shark_size){
                shark_size++;
                shark_eat = 0;
            }
            while (!q.empty()) {
                q.pop();
            }
            candi[0].move = 0;
            q.push(candi[0]);
            memset(visited, 0, sizeof(visited));
            candi.clear();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    
    SHARK shark;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin>>map[y][x];
            if(map[y][x] == 9){
                shark.y = y; shark.x = x; shark.move = 0;
                shark_size = 2; shark_eat = 0;
                map[y][x] = 0; visited[y][x] = 1;
                q.push(shark);
            }
        }
    }
    bfs();
    cout<<ans;
    return 0;
}
