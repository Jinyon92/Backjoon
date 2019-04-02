#include<iostream>
#include<queue>
using namespace std;

int map[51][51];
int m,n;
int a[4] = {0,1,0,-1};
int b[4] = {1,0,-1,0};
queue< pair<int, int> > que;

void dfs(int x, int y, int cnt)
{
    map[x][y] = cnt;
    for(int i=0; i<4; i++)
    {
        int nextX = x+a[i];
        int nextY = y+b[i];
        if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
        {
            continue;
        }
        if(map[nextX][nextY] == 1)
        {
            dfs(nextX, nextY, cnt);
        }
    }
}

int main()
{
    int t,k;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        int cnt = 1;
        scanf("%d %d %d", &m, &n, &k);
        for(int i=0; i<k; i++)
        {
            int x,y;
            scanf("%d %d", &x, &y);
            map[x][y] = 1;
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(map[i][j] == 1)
                {
                    cnt += 1;
                    dfs(i,j,cnt);
                }
            }
        }
        printf("%d\n", cnt-1);
    }
    return 0;
}
