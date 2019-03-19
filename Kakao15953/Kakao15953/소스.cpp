#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int prize_2017[7] = { 0,5000000, 3000000, 2000000, 500000, 300000, 100000 };
int prize_2018[6] = { 0,5120000, 2560000, 1280000, 640000, 320000 };
int a[101];
int b[101];
vector<int> ans;

int main()
{
	int t, rank, sum, answer, start, end;
	cin >> t;
	sum = 1;

	for (int j = 1; j <= 6; j++)
	{
		rank = j;
		sum = sum + rank - 1;
		for (int i = sum; i < sum + rank; i++)
		{
			a[i] = prize_2017[rank];
		}
	}

	sum = 0;
	for (int j = 1; j <= 5; j++)
	{
		rank = j - 1;
		sum = pow(2, rank);
		for (int i = sum; i < sum + sum; i++)
		{
			b[i] = prize_2018[rank + 1];
		}
	}
	for (int i = 0; i < t; i++)
	{
		cin >> start >> end;
		answer = a[start] + b[end];
		ans.push_back(answer);
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}