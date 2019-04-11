#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<limits.h>
using namespace std;

long long ans;

long long init(vector<long long> &a, vector<long long> &minTree, int node, int start, int end)
{
    if(start == end)
    {
        return minTree[node] = a[start];
    }else{
        return minTree[node] = min(init(a, minTree, node*2, start, (start+end)/2), init(a, minTree, node*2 + 1, (start+end)/2 + 1, end));
    }
}
void getResult(vector<long long> &minTree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start)
    {
        return;
    }
    if(left <= start && end <= right)
    {
        ans = min(ans, minTree[node]);
        return;
    }
    getResult(minTree, node*2, start, (start+end)/2, left, right);
    getResult(minTree, node*2 + 1, (start+end)/2 + 1, end, left, right);
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    vector<long long> a(n);
    for(int i=0; i<n; i++)
    {
        scanf("%lld", &a[i]);
    }
    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h+1);
    vector<long long> minTree(tree_size);
    init(a, minTree, 1, 0, n-1);
    
    for(int i=0; i<m; i++)
    {
        int left, right;
        scanf("%d %d", &left, &right);
        ans = LONG_MAX;
        getResult(minTree, 1, 0, n-1, left-1, right-1);
        printf("%lld\n", ans);
    }
    return 0;
}
