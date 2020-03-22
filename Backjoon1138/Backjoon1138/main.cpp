#include<iostream>
using namespace std;

int height[12];
int ans[12];

void move_arr(int idx, int finish)
{
    for(int i=idx-1; i >= finish; i--){
        ans[i+1] = ans[i];
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>height[i];
    }
    
    ans[1] = n;
    int cnt = 2;
    for(int i=n-1; i>=1; i--){
        if(height[i] == 0){
            move_arr(cnt, 1);
            ans[1] = i;
        }else{
            move_arr(cnt, 1+height[i]);
            ans[1+height[i]] = i;
        }
        cnt++;
    }
    
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
