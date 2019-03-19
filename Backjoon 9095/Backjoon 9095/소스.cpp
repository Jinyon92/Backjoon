#include<iostream>
#include<vector>
using namespace std;

int dp[12];
vector<int> ans;

int main()
{
	int n;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		ans.push_back(num);
	}
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 12; i++)
	{
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << dp[ans[i]] << endl;
	}
	return 0;
}