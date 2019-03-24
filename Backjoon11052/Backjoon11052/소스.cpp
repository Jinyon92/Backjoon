#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int dp[10001];
int arr[10001];

int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &arr[i]);
		dp[i] = arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i - j > 0)
			{
				dp[i] = max(dp[i], dp[i - j] + arr[j]);
			}
			else {
				break;
			}
		}
	}
	printf("%d", dp[n]);
	return 0;
}