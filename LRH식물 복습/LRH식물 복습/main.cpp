#include<iostream>
#include<cstdio>
using namespace std;

int tree[100001];

int sum(int i)
{
    int ans = 0;
    while(i > 0)
    {
        ans += tree[i];
        i -= (i&-i);
    }
    return ans;
}
void update(int i, int num)
{
    while(i <= 100000)
    {
        tree[i] += num;
        i += (i&-i);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int left, right;
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d", &left, &right);
        int l = sum(left);
        int r = sum(right);
        
        update(left,-l); update(left+1,l);
        update(right,-r); update(right+1, r);
        update(left+1, 1);
        update(right, -1);
        printf("%d\n", l+r);
    }
}
