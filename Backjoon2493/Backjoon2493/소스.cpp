#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

stack< pair<int, int> > st;

int main()
{
	int n;
	scanf_s("%d", &n);
	int num;
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &num);
		while (!st.empty())
		{
			if (st.top().second > num)
			{
				printf("%d ", st.top().first);
				break;
			}
			st.pop();
		}
		if (st.empty())
		{
			printf("0 ");
		}
		st.push(make_pair(i, num));
	}
	return 0;
}