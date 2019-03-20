#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

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
	scanf("%d", &n);
	int left, right, l, r;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &left, &right);
		l = sum(left);
		r = sum(right);

		update(left, -l); update(left + 1, l);
		update(right, -r); update(right + 1, r);
		update(left + 1, 1);
		update(right, -1);
		
		printf("%d\n", l + r);
	}
	
	return 0;
}