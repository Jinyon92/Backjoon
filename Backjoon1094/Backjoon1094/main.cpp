#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int x;
    cin>>x;
    int cnt = 0;
    for(int i=0; i<=ceil(log2(x)) + 1; i++){
        if(x & (1 << i)){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
