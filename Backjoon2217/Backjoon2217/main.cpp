#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int lope;
        scanf("%d", &lope);
        v.push_back(lope);
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        int value = (n-i)*v[i];
        ans = max(ans, value);
    }
    printf("%d", ans);
    return 0;
}
