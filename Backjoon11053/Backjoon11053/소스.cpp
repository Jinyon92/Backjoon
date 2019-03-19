#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[1001];

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	int num;
	arr.push_back(0);
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (arr[i] - arr[j] > 0)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
			else
			{
				dp[i] = max(dp[i], 1);
			}
		}
	}
	int key = dp[1];
	for (int i = 2; i <= n; i++)
	{
		if (key < dp[i])
		{
			key = dp[i];
		}
	}
	cout << key;
	return 0;
}