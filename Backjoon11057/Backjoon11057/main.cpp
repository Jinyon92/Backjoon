#include<iostream>
using namespace std;

int dp[1001][11];
const int mod = 10007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    int ans = 0;
    for(int i=0; i<10; i++)
    {
        dp[1][i] = 1;
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<10; j++)
        {
            for(int k=j; k<10; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
            }
        }
    }
    for(int i=0; i<10; i++)
    {
        ans = (ans + dp[n][i]) % mod;
    }
    cout<<ans;
    return 0;
}
