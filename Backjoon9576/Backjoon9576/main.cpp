#include<iostream>
#include<vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main()
{
    int T;
    cin>>T;
    for(int test_case = 0; test_case <T; test_case++){
        int n,m;
        cin>>n>>m;
        vector< pair<int, int> > range;
        vector<bool> visit(n+1,false);
        int start, end;
        for(int i=0; i<m; i++){
            cin>>start>>end;
            range.push_back(make_pair(start, end));
        }
        sort(range.begin(), range.end(), cmp);
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=range[i].first; j<=range[i].second; j++){
                if(!visit[j]){
                    ans++;
                    visit[j] = true;
                    break;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
