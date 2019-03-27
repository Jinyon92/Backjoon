#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;

vector< pair<int, int> > tree[100001];
queue<int> que;
int visit[100001];
int sum[100001];
int sMax, sPos;

void bfs(int i)
{
    que.push(i);
    while(!que.empty())
    {
        int start = que.front();
        que.pop();
        visit[start] = 1;
        for(auto now : tree[start])
        {
            int cur = now.first;
            int wei = now.second;
            if(visit[cur] == 0)
            {
                que.push(cur);
                sum[cur] = sum[start] + wei;
                if(sum[cur] > sMax)
                {
                    sMax = sum[cur];
                    sPos = cur;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int start, end, weight;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &start);
        while(1)
        {
            scanf("%d", &end);
            if(end == -1)
            {
                break;
            }
            scanf("%d", &weight);
            tree[start].push_back(make_pair(end, weight));
        }
    }
    bfs(1);
    fill(visit, visit+100001, 0);
    fill(sum, sum+100001, 0);
    sMax = 0;
    bfs(sPos);
    printf("%d", sMax);
    return 0;
}
