#include<iostream>
using namespace std;

int coin[6] = {500,100,50,10,5,1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int ans = 0;
    int pay;
    cin>>pay;
    int change = 1000 - pay;
    for(int i=0; i<6;){
        if(change >= coin[i]){
            change -= coin[i];
            ans++;
        }else{
            i++;
        }
    }
    cout<<ans;
    return 0;
}
