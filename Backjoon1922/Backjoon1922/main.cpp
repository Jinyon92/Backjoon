#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n,m;
int parent[1001];
int level[1001];
int ans;
priority_queue<tuple<int, int, int> >edges;

void makeset(int v){
    parent[v] = v;
    level[v] = 0;
}

int find(int v){
    if(parent[v] == v) return v;
    else return parent[v] = find(parent[v]);
}

void merge(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    
    if(level[root_a] < level[root_b]){
        parent[root_a] = root_b;
    }
    else if(level[root_a] > level[root_b]){
        parent[root_b] = root_a;
    }else{
        parent[root_b] = root_a;
        level[root_a]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        edges.push(make_tuple(-w,a,b));
    }
    
    for(int i=1; i<=n; i++){
        makeset(i);
    }
    
    while(!edges.empty()){
        auto edge = edges.top();
        edges.pop();
        
        int w = -get<0>(edge);
        int a = get<1>(edge);
        int b = get<2>(edge);
        
        if(find(a) != find(b)){
            merge(a,b);
            ans += w;
        }
    }
    
    cout<<ans;
    return 0;
}
