#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int a[8] = { -1,1,-1,1,1,0,-1,0 };
int b[8] = { 1,-1,-1,1,0,1,0,-1 };
int map[51][51];
int w, h;
int counter;
queue< pair<int,int> > que;
vector<int> ans;

void dfs()
{
	counter += 1;
	while (!que.empty())
	{
		auto now = que.front();
		que.pop();
		int x = now.first;
		int y = now.second;
		map[x][y] = 2;
		for (int i = 0; i < 8; i++)
		{
			int nextX = x + a[i];
			int nextY = y + b[i];
			if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w)
			{
				continue;
			}
			if (map[nextX][nextY] == 1)
			{
				que.push(pair<int, int>(nextX, nextY));
				map[nextX][nextY] = 2;
			}
		}
	}
}

int main()
{
	counter = 0;
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
		{
			break;
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1)
				{
					que.push(pair<int, int>(i, j));
					dfs();
				}
			}
		}
		ans.push_back(counter);
		counter = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				map[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}