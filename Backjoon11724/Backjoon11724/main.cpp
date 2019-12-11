#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<int> graph[1001];
int visited[1001];

void dfs(int node){
    for(auto now : graph[node]){
        if(!visited[now]){
            visited[now] = 1;
            dfs(now);
        }
    }
}

int main()
{
    cin>>n>>m;
    int start, end;
    for(int i=0; i<m; i++){
        cin>>start>>end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            ans++;
            visited[i] = 1;
            dfs(i);
        }
    }
    cout<<ans;
    return 0;
}
