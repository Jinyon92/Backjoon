#include<iostream>
#include<cstring>
using namespace std;

int n, cnt;
int visit[100001];
int cycle[100001];
int group[100001];
void dfs(int node){
    visit[node] = 1;
    int next = group[node];
    if(!visit[next]) dfs(next);
    else if(!cycle[next]){
        for(int i=next; i != node; i=group[i])
            cnt++;
        cnt++;
    }
    cycle[node] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    for(int test_case = 0; test_case < T; test_case++){
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>group[i];
        }
        cnt = 0;
        for(int i=1; i<=n; i++){
            if(!visit[i])
                dfs(i);
        }
        cout<<n-cnt<<"\n";
        memset(visit, 0, sizeof(visit));
        memset(cycle, 0, sizeof(cycle));
    }
    return 0;
}
