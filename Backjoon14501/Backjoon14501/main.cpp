#include<iostream>
#include<algorithm>
using namespace std;

int t[16];
int p[16];
int dp[16];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,ans = 0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>t[i]>>p[i];
        dp[i] = p[i];
    }
    for(int i=2; i<=n; i++){
        for(int j=i-1; j>0; j--){
            if(i-j >= t[j])
                dp[i] = max(dp[i], dp[j] + p[i]);
        }
    }
    for(int i=1; i<=n; i++){
        if(i+t[i] <= n+1){
            ans = max(ans,dp[i]);
        }
    }
    cout<<ans;
    return 0;
}
