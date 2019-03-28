#include <iostream>
using namespace std;

int coin[11];

int main()
{
    bool result = false;
    int n,k;
    cin>>n>>k;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        cin>>coin[i];
    }
    int pos = 0;
    for(int i=0; i<n; i++)
    {
        int temp = k - coin[i];
        if(i==n-1)
        {
            pos = i;
            break;
        }
        if(temp < 0)
        {
            pos = i-1;
            break;
        }
    }
    
    for(int i=pos; i>=0; i--)
    {
        int temp = k;
        int counter = 0;
        while(1)
        {
            temp -= coin[i];
            if(temp == 0)
            {
                counter += 1;
                result = true;
                break;
            }
            if(temp<0)
            {
                break;
            }
            counter += 1;
        }
        k = k - coin[i]*counter;
        ans += counter;
        if(result)
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}
