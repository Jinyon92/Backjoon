#include<iostream>
#include<queue>
using namespace std;

struct INFO{
    int u, v, w;
    
    bool operator < (const INFO& a) const {return a.w < w;}
};
int n,m, ans;
int parent[10001];
int level[10001];
priority_queue<INFO> edges;

int find(int u){
    if(u == parent[u]) return u;
    else return parent[u] = find(parent[u]);
}

void merge(int a, int b){
    int a_root = find(a);
    int b_root = find(b);
    
    if(level[a_root] < level[b_root]){
        parent[a_root] = b_root;
    }
    else if(level[a_root] > level[b_root]){
        parent[b_root] = a_root;
    }
    else{
        parent[b_root] = a_root;
        level[a_root]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        parent[i] = i;
        level[i] = 1;
    }
    
    int a,b,w;
    for(int i=1; i<=m; i++){
        cin>>a>>b>>w;
        edges.push({a,b,w});
    }
    
    while(!edges.empty()){
        auto edge = edges.top();
        edges.pop();
        
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        
        if(find(u) != find(v)){
            merge(u,v);
            ans += w;
        }
    }
    
    cout<<ans;
    return 0;
}
