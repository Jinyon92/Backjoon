#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int score[21][21];
int n, divide, ans = INT_MAX;
int visited[21], aTeam[10], bTeam[10];

void dfs(int cur ,int cnt){
    if(cnt == divide){
        int aidx = 0, bidx = 0, ascore = 0, bscore = 0;
        for(int i=1; i<=n; i++){
            if(visited[i]){
                aTeam[aidx++] = i;
            }else{
                bTeam[bidx++] = i;
            }
        }
        for(int i=0; i<divide-1; i++){
            for(int j=i+1; j<divide; j++){
                ascore += score[aTeam[i]][aTeam[j]] + score[aTeam[j]][aTeam[i]];
                bscore += score[bTeam[i]][bTeam[j]] + score[bTeam[j]][bTeam[i]];
            }
        }
        int tmp = abs(ascore - bscore);
        ans = min(tmp, ans);
        return;
    }
    
    for(int i=cur; i<=n; i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(i+1,cnt+1);
            visited[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int y=1; y<=n; y++){
        for(int x=1; x<=n; x++){
            cin>>score[y][x];
        }
    }
    divide = n / 2;
    visited[1] = 1;
    dfs(2,1);
    cout<<ans;
    return 0;
}
