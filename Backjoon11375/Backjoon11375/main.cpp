#include<iostream>
#include<vector>
using namespace std;

int n,m;
bool adj[1001][1001];
vector<int> aMatch,bMatch;
vector<bool> visit;

bool dfs(int here){
    if(visit[here]) return false;
    visit[here] = true;
    for(int there = 0; there < m; there++){
        if(adj[here][there]){
            if(bMatch[there] == -1 || dfs(bMatch[there])){
                aMatch[here] = there;
                bMatch[there] = here;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    int k, pos;
    for(int i=0; i<n; i++){
        cin>>k;
        for(int j=0; j<k; j++){
            cin>>pos;
            adj[i][pos-1] = 1;
        }
    }
    aMatch = vector<int>(n, -1);
    bMatch = vector<int>(m, -1);
    int ans = 0;
    for(int start = 0; start<n; start++){
        visit = vector<bool>(n, false);
        if(dfs(start))
            ans++;
    }
    cout<<ans;
    return 0;
}
