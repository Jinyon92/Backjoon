#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, k;
	scanf_s("%d %d", &n, &k);
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0)
		{
			ans.push_back(i);
		}
	}
	printf("%d", ans[k - 1]);
	return 0;
}