#include<iostream>
#include<cstring>
using namespace std;

int prison[101];

int main()
{
    int t,n;
    cin>>t;
    for(int test_case = 0; test_case<t; test_case++){
        cin>>n;
        int ans = 0;
        for(int i=2; i<=n; i++){
            for(int j=1; j*i<=n; j++){
                if(prison[i*j] == 0){
                    prison[i*j] = 1;
                }else{
                    prison[i*j] = 0;
                }
            }
        }
        for(int i=1; i<=n; i++){
            if(prison[i] == 0)
                ans++;
        }
        cout<<ans<<"\n";
        memset(prison, 0, sizeof(prison));
    }
    return 0;
}
