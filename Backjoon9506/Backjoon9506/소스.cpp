#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ans;

int solution(int n)
{
	int sum = 0;
	for (int i = 1; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			sum += i;
			ans.push_back(i);
			if (i > 1)
			{
				if (i*i == n)
				{
					break;
				}
				else {
					sum += (n / i);
					ans.push_back(n / i);
				}
			}
		}	
	}
	return sum;
}

int main()
{
	int n;
	while (true)
	{
		scanf_s("%d", &n);
		if (n == -1)
		{
			break;
		}
		int value = solution(n);
		sort(ans.begin(), ans.end());
		if (value == n)
		{
			printf("%d =", n);
			for (int i = 0; i < ans.size(); i++)
			{
				if (i+1 == ans.size())
				{
					printf(" %d\n", ans[i]);
				}
				else {
					printf(" %d +", ans[i]);
				}
			}
		}
		else {
			printf("%d is NOT perfect.\n", n);
		}
		ans.clear();
	}
	return 0;
}