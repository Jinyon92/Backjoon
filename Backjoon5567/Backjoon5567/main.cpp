#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> graph[501];
queue< pair<int, int> > q;
int cnt;
int visit[501];

void bfs(){
    while(!q.empty()){
        auto now = q.front();
        int node = now.first;
        int depth = now.second;
        q.pop();
        if(depth <= 2){
            cnt++;
        }else
            break;
        for(auto next : graph[node]){
            if(!visit[next]){
                q.push(make_pair(next, depth+1));
                visit[next] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m, start, end;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>start>>end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    q.push(make_pair(1,0));
    visit[1] = 1;
    bfs();
    cout<<cnt-1;
    return 0;
}
