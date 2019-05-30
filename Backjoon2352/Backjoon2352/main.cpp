#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    const int MAX = 987654321;
    vector<int> v(n);
    vector<int> lis(n, MAX);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    for(int i=0; i<n; i++){
        auto it = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        lis[it] = v[i];
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(lis[i] != MAX){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
