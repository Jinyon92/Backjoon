#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

int n,m,start_node,end_node;
struct NODE{
    int end, c;
};
vector<NODE> edge[1001];
int cost[1001];

void dijkstra(){
    priority_queue< pair<int, int> > pq;
    pq.push({0,start_node});
    
    while(!pq.empty()){
        int now_node = pq.top().second;
        pq.pop();
        
        for(int i=0; i<edge[now_node].size(); i++){
            int after_cost = cost[now_node] + edge[now_node][i].c;
            int pre_cost = cost[edge[now_node][i].end];
            
            if(pre_cost > after_cost){
                cost[edge[now_node][i].end] = after_cost;
                pq.push({-1*after_cost, edge[now_node][i].end});
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    int from, to, c;
    for(int i=0; i<m; i++){
        cin>>from>>to>>c;
        edge[from].push_back({to, c});
    }
    cin>>start_node>>end_node;
    for(int i=1; i<=n; i++){
        cost[i] = INT_MAX;
    }
    cost[start_node] = 0;
    dijkstra();
    
    cout<<cost[end_node];
    return 0;
}
