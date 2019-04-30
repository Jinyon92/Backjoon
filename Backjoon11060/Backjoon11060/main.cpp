#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
    }
    for(int i=2; i<=n; i++)
    {
        dp[i] = 10000000;
    }
    dp[1] = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=v[i]; j++)
        {
            if(i+j <= n)
                dp[i + j] = min(dp[i+j], dp[i] + 1);
        }
    }
    if(dp[n] >= 10000000)
        cout<<-1;
    else
        cout<<dp[n];
    return 0;
}
