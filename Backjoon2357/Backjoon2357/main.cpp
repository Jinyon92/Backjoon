#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<limits.h>
using namespace std;

#define MAX 1
#define MIN 2
long long ans_max;
long long ans_min;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end, int mode)
{
    if(start == end)
    {
        return tree[node] = a[start];
    }
    if(mode == MAX)
    {
        return tree[node] = max(init(a, tree, node*2, start, (start+end)/2, mode), init(a, tree, node*2 + 1, (start+end)/2 + 1, end, mode));
    }
    else
    {
        return tree[node] = min(init(a, tree, node*2, start, (start+end)/2, mode), init(a, tree, node*2 + 1, (start+end)/2 + 1, end, mode));
    }
}

void getResult(vector<long long> &minTree, vector<long long> &maxTree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start)
    {
        return;
    }
    if(left <= start && end <= right)
    {
        if(minTree[node] < ans_min)
        {
            ans_min = minTree[node];
        }
        if(maxTree[node] > ans_max)
        {
            ans_max = maxTree[node];
        }
        return;
    }
    getResult(minTree, maxTree, node*2, start, (start+end)/2, left, right);
    getResult(minTree, maxTree, node*2+1, (start+end)/2 + 1, end, left, right);
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    vector<long long> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h+1);
    vector<long long> maxTree(tree_size);
    vector<long long> minTree(tree_size);
    
    for(int i=0; i<n; i++)
    {
        scanf("%lld", &a[i]);
    }
    init(a, maxTree, 1, 0, n-1, MAX);
    init(a, minTree, 1, 0, n-1, MIN);
    
    for(int i=0; i<m; i++)
    {
        int left, right;
        scanf("%d %d", &left, &right);
        ans_max = 0;
        ans_min = LONG_MAX;
        getResult(minTree, maxTree, 1, 0, n-1, left-1, right-1);
        printf("%lld %lld\n", ans_min, ans_max);
    }
    return 0;
}
