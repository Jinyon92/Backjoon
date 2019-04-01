#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int l,a,b,c,d;
    cin>>l>>a>>b>>c>>d;
    int cnt1, cnt2;
    cnt1 = 1;
    cnt2 = 1;
    while(1)
    {
        int temp = a;
        temp -= c*cnt1;
        if(temp <= 0)
        {
            break;
        }
        cnt1++;
    }
    while(1)
    {
        int temp = b;
        temp -= d*cnt2;
        if(temp <= 0)
        {
            break;
        }
        cnt2++;
    }
    int ans = max(cnt1, cnt2);
    cout<<l-ans;
    return 0;
}
