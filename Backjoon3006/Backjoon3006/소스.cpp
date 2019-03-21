#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef pair<int, int> p;

p arr[100001];
int tree[100001];

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
	while (i < 100001)
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
		update(i, 1);
	}
	sort(arr, arr + n + 1);
	int a = 1;
	int b = n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			int temp = arr[a].second;
			printf("%d\n", sum(temp) - 1);
			update(temp, -1);
			a += 1;
		}
		else {
			printf("%d\n", sum(n) - sum(arr[b].second));
			update(arr[b].second, -1);
			b -= 1;
		}
	}
	return 0;
}