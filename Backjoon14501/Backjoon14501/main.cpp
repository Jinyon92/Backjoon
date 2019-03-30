#include<iostream>
#include<algorithm>
using namespace std;

int dp[16];
int t[16];
int p[16];

int main()
{
    int n;
    cin>>n;
    int time, pay;
    for(int i=1; i<=n; i++)
    {
        cin>>time>>pay;
        t[i] = time;
        p[i] = pay;
        dp[i] = p[i];
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if(i-j >= t[j])
            {
                dp[i] = max(dp[i], dp[j] + p[i]);
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(i+t[i] <= n+1)
        {
            ans = max(ans, dp[i]);
        }
    }
    printf("%d", ans);
    return 0;
}
