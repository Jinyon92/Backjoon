#include<iostream>
#include<queue>
#include<set>
#include<string.h>
using namespace std;

int map[50][50], visited[50][50];
int n, L, R, ans = 0;
queue< pair<int, int> > q;
set< pair<int, int> > s;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

void calc(){
    int sum = 0;
    for(auto iter = s.begin(); iter != s.end(); iter++){
        sum += map[iter->first][iter->second];
    }
    int value = sum / s.size();
    for(auto iter = s.begin(); iter != s.end(); iter++){
        map[iter->first][iter->second] = value;
    }
    s.clear();
}

void bfs()
{
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        int y = now.first;
        int x = now.second;
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(!visited[ny][nx] && abs(map[y][x] - map[ny][nx]) >= L && abs(map[y][x] - map[ny][nx]) <= R){
                s.insert(make_pair(ny, nx));
                q.push(make_pair(ny, nx));
                visited[ny][nx] = 1;
            }
        }
    }
    if(s.size() == 1){
        s.clear();
    }else{
       calc();
    }
}

int main()
{
    cin>>n>>L>>R;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin>>map[y][x];
        }
    }
    while(1){
        int cnt = 0;
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                if(!visited[y][x]){
                    cnt++;
                    visited[y][x] = 1;
                    s.insert(make_pair(y, x));
                    q.push(make_pair(y, x));
                    bfs();
                }
            }
        }
        if(cnt == n*n){
            break;
        }else{
            ans++;
        }
        memset(visited, 0, sizeof(visited));
    }
    cout<<ans;
    return 0;
}
