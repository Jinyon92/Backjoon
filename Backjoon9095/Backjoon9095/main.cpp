#include<iostream>
using namespace std;

int cnt;

void solve(int num){
    if(num < 0) return;
    if(num == 0) {
        cnt++;
        return;
    }
    
    int first = num - 1;
    solve(first);
    int second = num - 2;
    solve(second);
    int third = num - 3;
    solve(third);
}

int main()
{
    int tc;
    cin>>tc;
    
    int val;
    for(int t = 0; t<tc; t++){
        cin>>val;
        cnt = 0;
        solve(val);
        cout<<cnt<<"\n";
    }
    return 0;
}
