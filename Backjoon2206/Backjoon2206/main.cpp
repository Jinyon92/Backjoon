#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
typedef pair<int, int> pai;

int map[1001][1001];
int ans[1001][1001][2];
int n,m;
int a[4] = {1,0,-1,0};
int b[4] = {0,1,0,-1};
queue< pair<pai, int> > que;

int bfs()
{
    que.push(make_pair(make_pair(1,1),1));
    while(!que.empty())
    {
        auto now = que.front();
        int x = now.first.first;
        int y = now.first.second;
        int block = now.second;
        que.pop();
        if(x==n && y==m)
        {
            return ans[x][y][block]+1;
        }
        for(int i=0; i<4; i++)
        {
            int nextX = x+a[i];
            int nextY = y+b[i];
            if(nextX < 1 || nextX > n  || nextY < 1 || nextY > m)
            {
                continue;
            }
            if(map[nextX][nextY] == 1 && block)
            {
                que.push(make_pair(make_pair(nextX, nextY), block-1));
                ans[nextX][nextY][block-1] = ans[x][y][block] + 1;
            }
            else if(map[nextX][nextY] == 0 && ans[nextX][nextY][block] == 0)
            {
                que.push(make_pair(make_pair(nextX, nextY), block));
                ans[nextX][nextY][block] = ans[x][y][block] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int result;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }
    result = bfs();
    printf("%d", result);
    return 0;
}

