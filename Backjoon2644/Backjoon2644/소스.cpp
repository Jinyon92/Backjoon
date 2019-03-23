#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> family[101];
queue< pair<int,int> > que;
int visit[101];
int counter;
int verify;

void Bfs(int n)
{
	bool exit = false;
	while (!que.empty())
	{
		auto now = que.front();
		int x = now.second;
		que.pop();
		visit[x] = 1;
		for (auto p : family[x])
		{
			if (p == n)
			{
				counter = now.first;
				exit = true;
				break;
			}
			if (visit[p] == 0)
			{
				que.push(pair<int, int>(now.first + 1, p));
			}
		}
		if (exit)
		{
			verify = 1;
			break;
		}
	}
}

int main()
{
	counter = 1;
	int n;
	scanf_s("%d", &n);
	int ans1, ans2;
	scanf_s("%d %d", &ans1, &ans2);
	int num;
	scanf_s("%d", &num);
	que.push(pair<int,int>(counter,ans1));
	int parent, child;
	for (int i = 0; i < num; i++)
	{
		scanf_s("%d %d", &parent, &child);
		family[parent].push_back(child);
		family[child].push_back(parent);
	}
	Bfs(ans2);
	if (verify == 0)
	{
		counter = -1;
	}
	printf("%d", counter);
	return 0;
}