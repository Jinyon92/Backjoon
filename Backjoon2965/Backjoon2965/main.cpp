#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a[3];
    for(int i=0; i<3; i++)
    {
        cin>>a[i];
    }
    int ans;
    ans = max(a[1] - a[0], a[2] - a[1]);
    cout<<ans-1;
    return 0;
}
