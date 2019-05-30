#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int MAX = INT_MAX;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<int> lis(n, MAX);
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
