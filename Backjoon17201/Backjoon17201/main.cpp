#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(2*n);
    for(int i=0; i<2*n; i++){
        scanf("%1d",&arr[i]);
    }
    bool flag = true;
    for(int i=0; i<2*n-1; i++){
        if(arr[i] == arr[i+1]){
            flag = false;
            break;
        }
    }
    if(flag) cout<<"Yes";
    else cout<<"No";
    return 0;
}
