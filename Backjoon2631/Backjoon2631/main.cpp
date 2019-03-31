#include<iostream>
#include<algorithm>
using namespace std;

int line[201];
int dp[201];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &line[i]);
        dp[i] = 1;
    }
    int ans = 0;
    for(int i=1; i<n; i++)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(line[j] < line[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(ans < dp[i])
        {
            ans = dp[i];
        }
    }
    printf("%d", n-ans);
    return 0;
}
