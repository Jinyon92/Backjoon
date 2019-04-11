#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int n;
int arr[101][101];
int ans[101][101];
int visit[101];
vector<int> v[101];
queue<int> que;

void dfs(int pos)
{
    que.push(pos);
    while(!que.empty())
    {
        int start = que.front();
        que.pop();
        for(auto now : v[start])
        {
            if(!visit[now])
            {
                que.push(now);
                ans[pos][now] = 1;
                visit[now] = 1;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1)
            {
                v[i].push_back(j);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        memset(visit, 0, sizeof(visit));
        dfs(i);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
