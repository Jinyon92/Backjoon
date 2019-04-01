#include<iostream>
using namespace std;

int n;
int col[16];
int ans;

bool isPossible(int a)
{
    for(int i=1; i<a; i++)
    {
        if(col[i] == col[a])
        {
            return false;
        }
        if(abs(col[i] - col[a]) == abs(i-a))
        {
            return false;
        }
    }
    return true;
}
void dfs(int row)
{
    if(row == n)
    {
        ans += 1;
    }
    else{
        for(int i=1; i<=n; i++)
        {
            col[row+1] = i;
            if(isPossible(row+1))
            {
                dfs(row+1);
            }else{
                col[row+1] = 0;
            }
        }
    }
    col[row] = 0;
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        col[1] = i;
        dfs(1);
    }
    printf("%d", ans);
    return 0;
}
