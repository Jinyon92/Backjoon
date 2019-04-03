#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector< pair<int, int> > v(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &v[i].first, &v[i].second);
    }
    sort(v.begin(), v.end());
    int left, right;
    int ans = 0;
    left = v[0].first;
    right = v[0].second;
    for(int i=1; i<n; i++)
    {
        if(right < v[i].first)
        {
            ans += (right - left);
            left = v[i].first;
            right = v[i].second;
        }
        else{
            if(right < v[i].second)
            {
                right = v[i].second;
            }
        }
    }
    ans += (right - left);
    printf("%d", ans);
    return 0;
}
