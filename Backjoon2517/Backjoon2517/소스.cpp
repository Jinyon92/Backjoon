#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
#define MAX 500001
typedef pair<int, int> pai;

int tree[MAX];
int a[MAX];
pai arr[MAX];

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
	while (i < MAX)
	{
		tree[i] += num;
		i += (i&-i);
	}
}

int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; i++)
	{
		a[arr[i].second] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int ans = sum(n) - sum(a[i]) + 1;
		update(a[i], 1);
		printf("%d\n", ans);
	}
	return 0;
}