#include<iostream>
using namespace std;

int parent[1000001];
int level[1000001];

int find(int u)
{
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    
    if(u==v) return;
    if(level[u] > level[v]) swap(u, v);
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
    for(int i=1; i<=n; i++){
        parent[i] = i;
        level[i] = 1;
    }
    int binary, a, b;
    for(int i=0; i<m; i++){
        cin>>binary>>a>>b;
        if(binary == 0){
            merge(a,b);
        }else{
            int u = find(a);
            int v = find(b);
            if(u == v){
                cout<<"YES"<<"\n";
            }else{
                cout<<"NO"<<"\n";
            }
        }
    }
    return 0;
}
