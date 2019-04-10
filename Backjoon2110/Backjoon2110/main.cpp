#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int visit[200001];

int main()
{
    int n,c;
    scanf("%d %d", &n, &c);
    vector<int> house(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &house[i]);
    }
    sort(house.begin(), house.end());
    
    int left = 1;
    int right = house[n-1] - house[0];
    int ans = 0;
    
    while(left<=right)
    {
        int mid = (left+right)/2;
        int cnt = 1;
        int st = house[0];
        
        for(int i=1; i<n; i++)
        {
            if(house[i] - st >= mid)
            {
                cnt +=1;
                st = house[i];
            }
        }
        if(cnt >= c)
        {
            ans = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    printf("%d", ans);
    return 0;
}
