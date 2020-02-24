#include<iostream>
#include<queue>
using namespace std;

int n,m,t;
int circle[51][51];
bool isFlag;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
queue< pair<int, int> > q;

void rotate_circle(int num, int dir, int k){
    for(int y=1; y<=n; y++){
        if(y % num == 0){
            int loop = k;
            while(loop){
                if(dir == 0){
                    int tmp = circle[y][m];
                    for(int i=m-1; i>=1; i--){
                        circle[y][i+1] = circle[y][i];
                    }
                    circle[y][1] = tmp;
                }else{
                    int tmp = circle[y][1];
                    for(int i=2; i<=m; i++){
                        circle[y][i-1] = circle[y][i];
                    }
                    circle[y][m] = tmp;
                }
                loop--;
            }
        }
    }
}

void bfs(int key){
    while(!q.empty()){
        auto now = q.front();
        int y = now.first;
        int x = now.second;
        q.pop();
        
        for(int dir=0; dir<4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny <= 0 || ny > n) continue;
            
            if(nx == 0) nx = m;
            if(nx == m+1) nx = 1;
            
            if(circle[ny][nx] == key){
                circle[ny][nx] = 0;
                isFlag = true;
                q.push({ny,nx});
            }
        }
    }
    
}

void search_num(){
    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            if(circle[y][x]){
                q.push({y,x});
                bfs(circle[y][x]);
            }
        }
    }
}

void solve(){
    int sum = 0;
    int cnt = 0;
    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            if(circle[y][x]) {
                sum += circle[y][x];
                cnt++;
            }
        }
    }
    
    if(cnt != 0){
        double avg = (double)sum / cnt;
        for(int y=1; y<=n; y++){
            for(int x=1; x<=m; x++){
                if(circle[y][x]){
                    if(circle[y][x] > avg){
                        circle[y][x]--;
                    }else if(circle[y][x] < avg){
                        circle[y][x]++;
                    }
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
    
    cin>>n>>m>>t;
    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            cin>>circle[y][x];
        }
    }
    
    int num, dir, k;
    for(int i=0; i<t; i++){
        isFlag = false;
        cin>>num>>dir>>k;
        rotate_circle(num, dir, k);
        search_num();
        if(!isFlag){
            solve();
        }
    }
    
    int ans = 0;
    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            ans += circle[y][x];
        }
    }
    cout<<ans;
    return 0;
}
