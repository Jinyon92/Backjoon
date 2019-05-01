#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int dp[1001][1001];
int map[1001][1001];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(map[i][j] == 0)
                dp[i][j] = 0;
            else{
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    ans = ans*ans;
    cout<<ans;
    return 0;
}
