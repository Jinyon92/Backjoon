#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(1000001,0);
    int ans = -1;
    for(int i=0; i<n; i++){
        int num;
        scanf("%d", &num);
        v[num]++;
    }
    for(int i=1; i<=1000000; i++){
        if(v[i] >= k){
            ans = i;
            break;
        }
    }
    cout<<ans;
    return 0;
}
