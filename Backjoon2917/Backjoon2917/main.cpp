#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,ans;
char map[500][500];
int tmp[500][500];
pair<int, int> start, finish;
queue< pair<int, int> > tree;
priority_queue< pair<int, pair<int, pair<int,int>>>> pq;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

void make_dist(){
    int dist = 1;
    
    while(!tree.empty()){
        int size = tree.size();
        for(int i=0; i<size; i++){
            auto now = tree.front();
            tree.pop();
            int y = now.first;
            int x = now.second;
            for(int dir=0; dir<4; dir++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                
                if(tmp[ny][nx] == 0){
                    tmp[ny][nx] = dist;
                    tree.push({ny,nx});
                }
            }
        }
        dist++;
    }
}

void bfs(){
    pq.push({tmp[start.first][start.second], {tmp[start.first][start.second], {start.first, start.second}}});
    
    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        
        int cur_dist = now.first;
        int min_dist = now.second.first;
        int y = now.second.second.first;
        int x = now.second.second.second;
        
        if(y == finish.first && x == finish.second){
            if(min_dist == -1) min_dist = 0;
            cout<<min_dist;
            break;
        }
        
        if(tmp[y][x] == -2) continue;
        tmp[y][x] = -2;
        
        for(int dir=0; dir<4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            
            if(tmp[ny][nx] != -2){
                pq.push({tmp[ny][nx], {min(tmp[ny][nx], min_dist),{ny, nx}}});
            }
        }
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
            
            if(map[y][x] == '+'){
                tree.push({y,x});
                tmp[y][x] = -1;
            }else if(map[y][x] == 'V'){
                start.first = y;
                start.second = x;
            }else if(map[y][x] == 'J'){
                finish.first = y;
                finish.second = x;
            }
        }
    }
    
    make_dist();
    bfs();
    return 0;
}
