#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

char map[5][5];
int visited[5][5];
int selected[25];
int answer;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
queue< pair<int, int> > q;

bool isOver(){
    int count = 0;
    for(int i=0; i<25; i++){
        if(selected[i]){
            int y = i / 5;
            int x = i % 5;
            if(map[y][x] == 'Y') count++;
        }
    }
    if(count >= 4) return false;
    else return true;
}

bool isConnected(){
    bool checked[5][5] = {false,};
    for(int i=0; i<25; i++){
        if(selected[i]){
            int y = i/5;
            int x = i%5;
            visited[y][x] = 1;
            q.push({y,x});
            break;
        }
    }
    for(int i=0; i<25; i++){
        if(selected[i]){
            int y = i/5;
            int x = i%5;
            checked[y][x] = true;
        }
    }
    
    while(!q.empty()){
        auto now = q.front(); q.pop();
        int y = now.first;
        int x = now.second;
        checked[y][x] = false;
        
        for(int dir=0; dir<4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
            if(!visited[ny][nx] && checked[ny][nx]){
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
    }
    for(int i=0; i<25; i++){
        if(selected[i]){
            int y = i/5;
            int x = i%5;
            if(checked[y][x]) return false;
        }
    }
    
    return true;
}

void dfs(int idx, int cnt){
    if(cnt == 7){
        if(isOver()){
            if(isConnected()) answer++;
        }
        memset(visited, 0, sizeof(visited));
        return;
    }
    
    for(int i=idx; i<25; i++){
        if(selected[i]) continue;
        
        selected[i] = true;
        dfs(i+1, cnt+1);
        selected[i] = false;
    }
}

int main()
{
    for(int y=0; y<5; y++){
        for(int x=0; x<5; x++){
            cin>>map[y][x];
        }
    }
    dfs(0,0);
    cout<<answer;
    return 0;
}
