#include<iostream>
#include<algorithm>
using namespace std;

int map[1000][1000];
int dp[1000][1000];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin>>map[y][x];
        }
    }
    dp[0][0] = map[0][0];
    for(int x=1; x<m; x++){
        dp[0][x] = dp[0][x-1] + map[0][x];
    }
    for(int y=1; y<n; y++){
        dp[y][0] = dp[y-1][0] + map[y][0];
    }
    for(int y=1; y<n; y++){
        for(int x=1; x<m; x++){
            dp[y][x] = max({dp[y-1][x-1] + map[y][x], dp[y-1][x] + map[y][x], dp[y][x-1] + map[y][x]});
        }
    }
    cout<<dp[n-1][m-1];
    return 0;
}
