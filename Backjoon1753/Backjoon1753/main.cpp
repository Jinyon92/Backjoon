#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 987654321

int V,E,start_node;
struct NODE{
    int end, w;
};
vector<NODE> edge[20001];
int dist[20001];

void dijkstra(){
    priority_queue< pair<int, int> > pq;
    pq.push({0,start_node});
    
    while(!pq.empty()){
        int now_node = pq.top().second;
        pq.pop();
        
        for(int i=0; i<edge[now_node].size(); i++){
            int new_w = dist[now_node] + edge[now_node][i].w;
            int pre_w = dist[edge[now_node][i].end];
            
            if(new_w < pre_w){
                dist[edge[now_node][i].end] = new_w;
                pq.push({-1*new_w, edge[now_node][i].end});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>V>>E>>start_node;
    int from, to, w;
    for(int i=0; i<E; i++){
        cin>>from>>to>>w;
        edge[from].push_back({to,w});
    }
    for(int i=1; i<=V; i++){
        dist[i] = INF;
    }
    dist[start_node] = 0;
    dijkstra();
    
    for(int i=1; i<=V; i++){
        if(dist[i] != INF) cout<<dist[i]<<"\n";
        else cout<<"INF\n";
    }
    return 0;
}
