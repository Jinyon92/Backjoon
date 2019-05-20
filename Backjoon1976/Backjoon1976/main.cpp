#include<iostream>
using namespace std;

int parent[201];
int level[201];

int find(int u)
{
    if(u == parent[u]){
        return u;
    }
    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    
    if(u == v) return;
    if(level[u] > level[v])
        swap(u, v);
    
    parent[u] = v;
    if(level[u] == level[v])
        ++level[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        parent[i] = i;
        level[i] = 1;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int val;
            cin>>val;
            
            if(j > i && val == 1)
                merge(i,j);
        }
    }
    bool chk = true;
    int val;
    cin>>val;
    
    int u = find(val);
    for(int i=0; i<m-1; i++){
        cin>>val;
        if(u != find(val)){
            chk = false;
            break;
        }
    }
    chk ? cout<<"YES" : cout<<"NO";
    return 0;
}
