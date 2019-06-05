#include<iostream>
using namespace std;

int graph[151];
int visit[151];
int n,k,ans;

void dfs(int node, int cnt)
{
    if(node == k){
        ans = cnt;
        return;
    }
    else{
        visit[node] = 1;
        int next = graph[node];
        if(!visit[next]){
            dfs(next, cnt+1);
        }
    }
}

int main()
{
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>graph[i];
    }
    ans = -1;
    dfs(0,0);
    cout<<ans;
    return 0;
}
