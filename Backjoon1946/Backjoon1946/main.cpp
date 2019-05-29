#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    int n;
    for(int test_case = 0; test_case < T; test_case++){
        cin>>n;
        vector< pair<int, int> > p(n);
        for(int i=0; i<n; i++){
            cin>>p[i].first>>p[i].second;
        }
        sort(p.begin(), p.end());
        int sy = p[0].second;
        int cnt = 1;
        for(int i=1; i<p.size(); i++){
            if(sy > p[i].second){
                cnt++;
                sy = p[i].second;
            }
        }
        cout<<cnt<<"\n";
        p.clear();
    }
    return 0;
}
