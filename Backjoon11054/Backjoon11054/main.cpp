#include<iostream>
#include<algorithm>
using namespace std;

int dp[2][1001];
int a[1001];
int n;

void lis()
{
    for(int i=1; i<n; i++)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(a[j] < a[i])
            {
                dp[0][i] = max(dp[0][i], dp[0][j] + 1);
            }
        }
    }
}

void reverse_lis()
{
    for(int i=n-2; i>=0; i--)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[j] < a[i])
            {
                dp[1][i] = max(dp[1][i], dp[1][j] + 1);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        dp[0][i] = 1;
        dp[1][i] = 1;
    }
    lis();
    reverse_lis();
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = max(ans, dp[0][i] + dp[1][i]);
    }
    printf("%d", ans-1);
    return 0;
}
