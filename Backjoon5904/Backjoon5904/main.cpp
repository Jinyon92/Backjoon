#include<iostream>
using namespace std;

int moo[28];
int N;

char solution(int d, int n){
    if(d==0) return n==1 ? 'm' : 'o';
    int rest = n - moo[d-1];
    if(rest < 0) return solution(d-1, n);
    if(rest <= d+3) return rest==1 ? 'm' : 'o';
    return solution(d-1, rest-d-3);
}
int main()
{
    cin>>N;
    moo[0] = 3;
    for(int i=1; i<28; i++){
        moo[i] = 2*moo[i-1] + i+3;
    }
    cout<<solution(27, N);
    return 0;
}
