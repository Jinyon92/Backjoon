#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_NUM = 1000001;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &v[i]);
    }
    vector<int> lis(n, MAX_NUM);
    
    for(int i=0; i<n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        lis[it] = v[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(lis[i] != MAX_NUM)
        {
            ans += 1;
        }else{
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
