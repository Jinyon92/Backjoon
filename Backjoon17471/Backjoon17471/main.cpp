#include<iostream>
#include<vector>
using namespace std;

int n;
int human[10];
bool visited[10];
vector< vector<int> > graph(10);
vector<int> region;
vector<int> n_region;

int countBits(int n){
    int cnt = 0;
    while(n){
        if(n & 1) cnt++;
        n = n >> 1;
    }
    return cnt;
}
void dfs(int start){
    for(auto now : graph[start]){
        for(auto reg : region){
            if(!visited[now] && now == reg){
                visited[now] = true;
                dfs(now);
            }
        }
    }
}
void n_dfs(int start){
    for(auto now : graph[start]){
        for(auto reg : n_region){
            if(!visited[now] && now == reg){
                visited[now] = true;
                n_dfs(now);
            }
        }
    }
}
bool is_verify(){
    for(int i=0; i<n; i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}
int solve(){
    int ret = 987654321;
    int div = n/2;
    for(int subset = 1; subset < 1 << n; subset++){
        if(countBits(subset) <= div){
            int value1 = 0, value2 = 0;
            for(int i=0; i<n; i++){
                if(subset & 1 << i){
                    region.push_back(i);
                }else{
                    n_region.push_back(i);
                }
            }
            visited[region[0]] = true;
            dfs(region[0]);
            visited[n_region[0]] = true;
            n_dfs(n_region[0]);
            if(is_verify()){
                for(int i=0; i<region.size(); i++){
                    value1 += human[region[i]];
                }
                for(int i=0; i<n_region.size(); i++){
                    value2 += human[n_region[i]];
                }
                int ans = abs(value1 - value2);
                ret = min(ans, ret);
            }
            for(int i=0; i<n; i++){
                visited[i] = false;
            }
            region.clear();
            n_region.clear();
        }
    }
    if(ret == 987654321) return -1;
    return ret;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>human[i];
    }
    int cnt, adj;
    for(int i=0; i<n; i++){
        cin>>cnt;
        for(int j=0; j<cnt; j++){
            cin>>adj;
            graph[i].push_back(adj-1);
            graph[adj-1].push_back(i);
        }
    }
    cout<<solve();
    return 0;
}
