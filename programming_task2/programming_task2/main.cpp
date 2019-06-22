#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k, ans;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int> kSum(n+1);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<=n-k; i++){
        for(int j=i; j<i+k; j++){
            kSum[i] += arr[j];
        }
    }
    dp[0] = max(0,arr[0]);
    for(int i=1; i<n; i++){
        dp[i] = max(0,dp[i-1]+arr[i]);
    }
    ans = kSum[0];
    for(int i=1; i<=n-k; i++){
        ans = max(ans, kSum[i] + dp[i-1]);
    }
    cout<<ans;
    return 0;
}
