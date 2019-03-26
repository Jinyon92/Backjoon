#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

int current[1001][1001];
queue< pair<int,int> > que;
int a[4] = {0,1,0,-1};
int b[4] = {1,0,-1,0};
int n,m;

int bfs()
{
    while(!que.empty())
    {
        auto now = que.front();
        int x = now.first;
        int y = now.second;
        if(x==n-1)
        {
            return 1;
        }
        que.pop();
        for(int i=0; i<4; i++)
        {
            int nextX = x+a[i];
            int nextY = y+b[i];
            if(nextX < 0 || nextX >=1000 || nextY <0 || nextY >=1000)
            {
                continue;
            }
            if(current[nextX][nextY] == 0)
            {
                que.push(make_pair(nextX, nextY));
                current[nextX][nextY] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<1000; i++)
    {
        for(int j=0; j<1000; j++)
        {
            current[i][j] = 1;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%1d", &current[i][j]);
            if(i==0 && current[i][j] == 0)
            {
                que.push(make_pair(i, j));
            }
        }
    }
    int ans = bfs();
    if(ans == 1)
    {
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
