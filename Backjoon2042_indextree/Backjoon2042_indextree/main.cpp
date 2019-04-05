#include<iostream>
#include<vector>
using namespace std;

void update(vector<long long> &tree, int i, long long num)
{
    while(i < tree.size())
    {
        tree[i] += num;
        i += (i&-i);
    }
}

long long sum(vector<long long> &tree, int i)
{
    long long ans = 0;
    while(i > 0)
    {
        ans += tree[i];
        i -= (i&-i);
    }
    return ans;
}

int main()
{
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    vector<long long> a(n+1);
    vector<long long> tree(n+1);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld", &a[i]);
        update(tree, i, a[i]);
    }
    for(int i=0; i<m+k; i++)
    {
        int num;
        scanf("%d", &num);
        if(num == 1)
        {
            int b;
            long long c;
            scanf("%d %lld", &b, &c);
            long long diff = c - a[b];
            a[b] = c;
            update(tree, b, diff);
        }
        else if(num == 2)
        {
            int l,r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", sum(tree, r) - sum(tree, l-1));
        }
    }
    return 0;
}
