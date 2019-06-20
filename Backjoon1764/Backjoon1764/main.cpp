#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> v;
    set<string> ans;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    string str;
    for(int i=0; i<m; i++){
        cin>>str;
        if(binary_search(v.begin(), v.end(), str)){
            ans.insert(str);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto iter = ans.begin(); iter != ans.end(); iter++){
        cout<<*iter<<"\n";
    }
    return 0;
}

