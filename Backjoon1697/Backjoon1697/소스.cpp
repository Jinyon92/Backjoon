#include<iostream>
#include<queue>
using namespace std;

queue<int> que;
int visit[100001];

int bfs(int n, int k)
{
	int time = 0;
	que.push(n);
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; i++)
		{
			int now = que.front();
			que.pop();
			if (now == k)
			{
				return time;
			}
			if (now - 1 >= 0 && visit[now - 1] == 0)
			{
				que.push(now - 1);
				visit[now - 1] = 1;
			}
			if (now * 2 <= 100000 && visit[now * 2] == 0)
			{
				que.push(now * 2);
				visit[now * 2] = 1;
			}
			if (now + 1 <= 100000 && visit[now + 1] == 0)
			{
				que.push(now + 1);
				visit[now + 1] = 1;
			}
		}
		time += 1;
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	int ans = bfs(n, k);
	cout << ans;
	return 0;
}