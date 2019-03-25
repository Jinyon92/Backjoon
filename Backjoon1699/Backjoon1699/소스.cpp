#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

int dp[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 100000; i++)
	{
		dp[i] = INT_MAX-1;
	}
	for (int i = 1; i*i <= 100000; i++)
	{
		dp[i*i] = 1;
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j*j <= 100000; j++)
		{
			if (i > j*j)
			{
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
			else {
				break;
			}
		}
	}
	cout << dp[n];
	return 0;
}