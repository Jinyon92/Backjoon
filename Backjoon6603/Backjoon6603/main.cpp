#include<iostream>
using namespace std;

int n;
int lotto[13];
int ans[13];

void dfs(int start, int cnt)
{
    if(cnt == 6)
    {
        for(int i=0; i<6; i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i=start; i<n; i++)
    {
        ans[cnt] = lotto[i];
        dfs(i+1, cnt+1);
    }
}

int main()
{
    while(1)
    {
        scanf("%d", &n);
        if(n==0)
        {
            break;
        }
        for(int i=0; i<n; i++)
        {
            scanf("%d", &lotto[i]);
        }
        dfs(0, 0);
        printf("\n");
    }
    return 0;
}
