#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int arr[300001];

int main()
{
    int n,ans,maks;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n, cmp);
    ans = 1; maks = arr[0]+1;
    for(int i=1; i<n; i++){
        if(arr[i]+n >= maks)
            ans++;
        maks = max(maks, arr[i]+i+1);
    }
    cout<<ans;
    return 0;
}
