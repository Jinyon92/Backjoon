#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s1, s2;
    cin>>s1>>s2;
    
    s1.insert(s1.begin(), '0');
    s2.insert(s2.begin(), '0');
    int len1 = s1.size();
    int len2 = s2.size();
    
    for(int i=0; i<len1; i++){
        dp[i][0] = i;
    }
    for(int i=0; i<len2; i++){
        dp[0][i] = i;
    }
    for(int i=1; i<len1; i++){
        for(int j=1; j<len2; j++){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }
    }
    cout<<dp[len1-1][len2-1];
    return 0;
}
