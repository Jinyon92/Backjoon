#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int get_on[4];
    int get_off[4];
    int sum[4];
    for(int i=0; i<4; i++)
    {
        scanf("%d %d", &get_off[i], &get_on[i]);
    }
    int ans = 0;
    sum[0] = get_on[0];
    for(int i=1; i<4; i++)
    {
        sum[i] =sum[i-1] + get_on[i] - get_off[i];
        ans = max(ans, sum[i]);
    }
    printf("%d", ans);
    return 0;
}
