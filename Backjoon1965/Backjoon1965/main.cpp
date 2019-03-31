#include<iostream>
#include<algorithm>
using namespace std;

int box[1001];
int dp[1001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &box[i]);
        dp[i] = 1;
    }
    int ans = 0;
    for(int i=1; i<n; i++)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(box[j] < box[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        if(ans < dp[i])
        {
            ans = dp[i];
        }
    }
    printf("%d", ans);
    return 0;
}

