#include<iostream>
#include<cmath>
using namespace std;

int server[10000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, pow_n, h, idx, num, cnt;
    long long total, div, sum;
    total = 0;
    cin>>n;
    pow_n = pow(n,2);
    for(int i=0; i<pow_n; i++){
        cin>>h;
        server[h]++;
        total += h;
    }
    sum = 0; idx = 0; num = pow_n; cnt = 0;
    while(((double)sum / (double)total * 100) < 50){
        num -= server[idx++];
        sum += num;
        cnt++;
    }
    cout<<cnt;
    return 0;
}
