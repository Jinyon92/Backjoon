#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[100001];
int level[100001];
int ans[100001];
int answer[100001];
int n;

int find(int u)
{
    if(u == parent[u]) return u;
    return find(parent[u]);
}

void update(int u, int v, int cnt){
    parent[u] = v;
    ans[u] = cnt;
    for(int i=1; i<=n; i++){
        if(parent[i] == u){
            ans[i] = cnt;
            parent[i] = v;
        }
    }
}

void merge(int u, int v, int cnt)
{
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(level[u] > level[v]) swap(u, v);
    update(u,v,cnt);
    if(level[u] == level[v])
        ++level[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int m,q;
    cin>>n>>m>>q;
    vector< vector<int> > team(m+1);
    int val;
    for(int i=1; i<=n; i++){
        parent[i] = i;
        level[i] = 1;
        cin>>val;
        team[val].push_back(i);
    }
    int start,end;
    for(int i=1; i<=q; i++){
        cin>>start>>end;
        merge(start, end, i);
    }
    bool chk = true;
    for(int i=1; i<=m; i++){
        int key = parent[team[i][0]];
        answer[i] = ans[team[i][0]];
        for(int j=1; j<team[i].size(); j++){
            if(key != parent[team[i][j]]){
                chk = false;
                break;
            }
            answer[i] = max(answer[i],ans[team[i][j]]);
        }
        if(!chk){
            break;
        }
    }
    for(int i=1; i<=m; i++){
        if(team[i].size() == 1){
            answer[i] = 0;
        }
    }
    if(chk){
        for(int i=1; i<=m; i++)
        {
            cout<<answer[i]<<"\n";
        }
    }else{
        cout<<-1;
    }
    return 0;
}
