#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int number[11];
int op[4];
int ans_min = INT_MAX; int ans_max = INT_MIN;
int n;

void dfs(int result, int cnt){
    if(cnt == n-1){
        ans_min = min(ans_min, result);
        ans_max = max(ans_max, result);
        return;
    }
    
    for(int i=0; i<4; i++){
        if(op[i] != 0){
            op[i]--;
            if(i == 0){
                dfs(result+number[cnt+1], cnt+1);
            }else if(i==1){
                dfs(result-number[cnt+1], cnt+1);
            }else if(i==2){
                dfs(result*number[cnt+1], cnt+1);
            }else{
                dfs(result/number[cnt+1], cnt+1);
            }
            op[i]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>number[i];
    }
    for(int i=0; i<4; i++){
        cin>>op[i];
    }
    dfs(number[0],0);
    cout<<ans_max<<"\n"<<ans_min;
    return 0;
}
