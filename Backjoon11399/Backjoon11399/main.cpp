#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ATM;
int sum[1001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int num;
        scanf("%d", &num);
        ATM.push_back(num);
    }
    sort(ATM.begin(),ATM.end());
    sum[0] = ATM[0];
    for(int i=1; i<n; i++)
    {
        sum[i] = sum[i-1] + ATM[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += sum[i];
    }
    printf("%d", ans);
    return 0;
}
