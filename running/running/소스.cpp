#include<iostream>
#include<vector>
using namespace std;

int tree[10001];

int sum(int i)
{
	int ans = 0;
	while (i > 0)
	{
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}

void update(int i, int num)
{
	while (i < 10001)
	{
		tree[i] += num;
		i += (i&-i);
	}
}

int main()
{
	int n;
	cin >> n;
	int num;
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		update(num, 1);
		ans.push_back(sum(num));
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}