#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = a[start];
    }
    else{
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2 +1, end);
    }
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff)
{
    if(index < start || index > end)
    {
        return;
    }
    tree[node] += diff;
    if(start != end)
    {
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2 + 1, end, index, diff);
    }
}

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    int h = ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> a(n+1, 0);
    vector<long long> tree(tree_size);
    init(a, tree, 1, 1, n);
    for(int i=0; i<k; i++)
    {
        int num;
        scanf("%d", &num);
        if(num==0)
        {
            int l,r;
            scanf("%d %d", &l, &r);
            if(l > r)
            {
                int temp = r;
                r = l;
                l = temp;
            }
            printf("%lld\n", sum(tree, 1, 1, n, l, r));
        }
        else if(num==1)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            long long diff = y - a[x];
            a[x] = y;
            update(tree, 1, 1, n, x, diff);
        }
    }
    return 0;
}
