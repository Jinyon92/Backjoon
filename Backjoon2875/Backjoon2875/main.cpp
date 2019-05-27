#include<iostream>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int team = 0;
    while(1){
        n -= 2;
        m -= 1;
        if(n < 0 || m < 0){
            n += 2;
            m += 1;
            break;
        }
        team += 1;
    }
    k -= (n+m);
    if(k>0){
        while(1){
            k -= 3;
            team -= 1;
            if(k <= 0) break;
        }
    }
    cout<<team;
    return 0;
}
