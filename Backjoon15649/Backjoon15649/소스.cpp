#include<iostream>
#include<vector>

using namespace std;
vector<bool> visit;
vector<int> ans;
int n, m;

void solve()
{
	if (ans.size() == m)
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			ans.push_back(i);
			solve();
			visit[i] = false;
			ans.pop_back();
		}
	}
}

int main()
{
	cin >> n >> m;
	visit = vector<bool>(n + 1, false);
	solve();
}