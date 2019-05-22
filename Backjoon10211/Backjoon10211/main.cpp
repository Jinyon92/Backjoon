#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    for(int test_case = 0; test_case < T; test_case++)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        dp[0] = max(0,arr[0]);
        for(int i=1; i<n; i++){
            dp[i] = max(0,dp[i-1]+arr[i]);
        }
        int ans = dp[0];
        for(int i=1; i<n; i++){
            ans = max(ans, dp[i]);
        }
        if(ans == 0){
            ans = arr[0];
            for(int i=1; i<n; i++){
                ans = max(ans, arr[i]);
            }
        }
        cout<<ans<<"\n";
        memset(dp, 0, sizeof(dp));
    }
    return 0;
}
