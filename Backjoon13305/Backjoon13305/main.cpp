#include<iostream>
using namespace std;

long long length[100000];
long long price[100001];

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>length[i];
    }
    for(int i=0; i<n; i++){
        cin>>price[i];
    }
    long long p = price[0];
    long long ans = p * length[0];
    for(int i=1; i<n-1; i++){
        if(p > price[i])
            p = price[i];
        ans += p*length[i];
    }
    cout<<ans;
    return 0;
}
