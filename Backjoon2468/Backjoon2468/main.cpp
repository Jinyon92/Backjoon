#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int house[101][101];
int visit[101][101];
int a[4] = {1,0,-1,0};
int b[4] = {0,1,0,-1};
int n;

void dfs(int x, int y, int h)
{
    for(int i=0; i<4; i++)
    {
        int nextX = x+a[i];
        int nextY = y+b[i];
        if(nextX < 0 || nextX >=n || nextY < 0 || nextY >=n)
        {
            continue;
        }
        if(house[nextX][nextY] > h && !visit[nextX][nextY])
        {
            visit[nextX][nextY] += 1;
            dfs(nextX, nextY, h);
        }
    }
}

int main()
{
    int height = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &house[i][j]);
            height = max(height, house[i][j]);
        }
    }
    int ans = 0;
    for(int h=0; h<=height; h++)
    {
        int cnt = 0;
        memset(visit, 0, sizeof(visit));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(house[i][j] > h && !visit[i][j])
                {
                    visit[i][j] +=1;
                    cnt +=1;
                    dfs(i,j,h);
                }
            }
        }
        ans = max(ans, cnt);
    }
    printf("%d", ans);
    return 0;
}
