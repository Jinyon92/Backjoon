#include<iostream>
#include<deque>
#include<cstdio>
using namespace std;

struct info{
    int x,y,left,right;
};

int a[] = {1,-1};
int b[] = {0,0};
int n,m,L,R;
int map[1001][1001];
bool chk(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && !map[x][y];
}
deque<info> dq;

int main()
{
    cin>>n>>m>>L>>R;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
            if(map[i][j] == 2){
                map[i][j] = 1;
                dq.push_front({i,j,L,R});
            }
        }
    }
    info st; int nextX,nextY,ans;
    ans = 1;
    while(!dq.empty()){
        st = dq.front();
        dq.pop_front();
        for(int i=0; i<2; i++){
            nextX = st.x + a[i];
            nextY = st.y + b[i];
            if(!chk(nextX,nextY)) continue;
            
            dq.push_front({nextX,nextY,st.left,st.right});
            map[nextX][nextY] = 1; ans++;
        }
        
        if(st.left && chk(st.x,st.y-1)){
            dq.push_back({st.x,st.y-1,st.left-1,st.right});
            map[st.x][st.y-1] = 1; ans++;
        }
        if(st.right && chk(st.x,st.y+1)){
            dq.push_back({st.x,st.y+1,st.left,st.right-1});
            map[st.x][st.y+1] = 1; ans++;
        }
    }
    cout<<ans;
    return 0;
}
