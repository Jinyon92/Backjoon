#include<iostream>
#include<vector>
using namespace std;

long long factorial[20];
bool check[21];

int main()
{
    int n,k;
    cin>>n>>k;
    factorial[0] = 1;
    for(int i=1; i<=20; i++){
        factorial[i] = factorial[i-1] * i;
    }
    if(k==1){
        long long num;
        cin>>num;
        for(int i=0; i<n; i++){
            for(int j=1; j<=n; j++){
                if(num <= factorial[n-i-1] && check[j] == false){
                    cout<<j<<" ";
                    check[j] = true;
                    break;
                }
                else if(num > factorial[n-i-1] && check[j] == false){
                    num -= factorial[n-i-1];
                }
            }
        }
    }else{
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            for(int j=1; j<a[i]; j++){
                if(check[j] == false){
                    ans += factorial[n-i-1];
                }
            }
            check[a[i]] = true;
        }
        cout<<ans+1;
    }
    return 0;
}
