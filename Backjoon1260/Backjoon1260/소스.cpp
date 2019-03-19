#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> graph[1001];
queue<int> que;
int n, m, v;
int isVisit[1001];
vector<int> ans;

void bfs(int node)
{
	ans.push_back(node);
	isVisit[node] ++;
	while (!que.empty())
	{
		auto now = que.front();
		que.pop();
		for (auto p : graph[now])
		{
			if (isVisit[p] == 0)
			{
				ans.push_back(p);
				isVisit[p] ++;
				que.push(p);
			}
			else {
				continue;
			}
		}
	}
}

void dfs(int node)
{
	isVisit[node] = 1;
	ans.push_back(node);
	for (int y : graph[node])
	{
		if (isVisit[y] == 0)
		{
			dfs(y);
		}
	}
}

int main()
{
	cin >> n >> m >> v;
	int start, end;
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(v);
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	ans.clear();
	for (int i = 0; i <= n; i++)
	{
		isVisit[i] = 0;
	}
	que.push(v);
	bfs(v);
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}