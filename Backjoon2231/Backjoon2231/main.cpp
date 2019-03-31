#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int init = 1;
    while(1)
    {
        int temp = init;
        int sum = init;
        while(temp > 0)
        {
            sum += temp%10;
            temp /= 10;
        }
        if(sum == n)
        {
            cout<<init;
            break;
        }
        if(init == n)
        {
            cout<<0;
            break;
        }
        init += 1;
    }
    return 0;
}
