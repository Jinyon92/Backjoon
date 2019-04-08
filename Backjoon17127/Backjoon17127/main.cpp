#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int visit[11];

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &v[i]);
    }
    int range = n-3;
    int index = 0;
    int max_num = 0;
    int ans = 0;
    for(int i=0; i<=n-range; i++)
    {
        int mul = 1;
        for(int j=i; j<range+i; j++)
        {
            mul *= v[j];
        }
        if(mul > max_num)
        {
            index = i;
            max_num = mul;
        }
    }
    for(int i=index; i<index+range; i++)
    {
        visit[i] = 1;
    }
    for(int i=0; i<n; i++)
    {
        if(!visit[i])
        {
            ans += v[i];
        }
    }
    ans += max_num;
    printf("%d", ans);
    return 0;
}
