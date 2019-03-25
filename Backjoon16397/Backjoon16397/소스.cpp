#include<iostream>
#include<queue>
using namespace std;

int n, t, g;
queue< pair<int, int> > que;
int visit[100000];

int bfs()
{
	que.push(make_pair(n, 0));
	visit[n] = 1;
	while (!que.empty())
	{
		int now = que.front().first;
		int cnt = que.front().second;
		que.pop();

		if (cnt > t)
		{
			break;
		}
		if (now == g)
		{
			return cnt;
		}

		int A = now + 1;
		if (now < 100000 && visit[A] == 0)
		{
			visit[A] = 1;
			que.push(make_pair(A, cnt + 1));
		}

		int temp = now * 2;
		if (temp > 99999)
		{
			continue;
		}
		int B = temp;
		int digit = 1;
		while (temp)
		{
			temp /= 10;
			digit *= 10;
		}
		digit /= 10;
		B -= digit;
		if (B < 100000 && visit[B] == 0)
		{
			visit[B] == 1;
			que.push(make_pair(B, cnt + 1));
		}
	}
	return -1;
}

int main()
{
	cin >> n >> t >> g;
	int ans = bfs();
	if (ans == -1)
	{
		cout << "ANG";
	}
	else {
		cout << ans;
	}
	return 0;
}