#include <iostream>
using namespace std;

int dp[31][31];

int main()
{
    int T;
    cin>>T;
    int n,m;
    for(int i=1; i<=30; i++) dp[1][i] = i;
    for(int i=2; i<=30; i++){
        for(int j=i; j<=30; j++){
            int k=j-1;
            while(i-1 <= k){
                dp[i][j] += dp[i-1][k];
                k--;
            }
        }
    }
    for(int test_case = 0; test_case < T; test_case++){
        cin>>n>>m;
        cout<<dp[n][m]<<"\n";
    }
    return 0;
}
