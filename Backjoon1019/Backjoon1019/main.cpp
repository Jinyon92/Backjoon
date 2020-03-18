#include<iostream>
using namespace std;

long long ans[10];

void cal(long long A, long long ten){
    while(A){
        ans[A % 10] += ten;
        A /= 10;
    }
}

void solve(long long A, long long B, long long ten){
    while(A%10 != 0 && A <= B){
        cal(A, ten);
        A++;
    }
    
    if(A > B) return;
    
    while(B%10 != 9 && A <= B){
        cal(B, ten);
        B--;
    }
    long long value = B/10 - A/10 + 1;
    for(int i=0; i<10; i++){
        ans[i] += value * ten;
    }
    
    solve(A/10, B/10, ten*10);
}

int main()
{
    long long n;
    cin>>n;
    
    solve(1, n, 1);
    for(int i=0; i<10; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
