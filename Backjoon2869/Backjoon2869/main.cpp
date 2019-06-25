#include<iostream>
using namespace std;

int main()
{
    int A,B,V;
    cin>>A>>B>>V;
    int ans = (V-B)/(A-B);
    if((V-B)%(A-B) == 0){
        cout<<ans;
    }else{
        cout<<ans+1;
    }
    return 0;
}
