#include<iostream>
#include<algorithm>
#include<cstdio>
#include<limits.h>
using namespace std;

int coin[101];
int dp[100001];

int main()
{
	int n, k;
	scanf_s("%d %d", &n, &k);
	for (int i = 1; i <= k; i++)
	{
		dp[i] = INT_MAX-1;
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &coin[i]);
		dp[coin[i]] = 1;
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - coin[j] > 0)
			{
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
			}
		}
	}
	if (dp[k] == INT_MAX-1)
	{
		dp[k] = -1;
	}
	printf("%d", dp[k]);
	return 0;
}