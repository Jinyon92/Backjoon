#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int n, ans;
int opCnt, oprandCnt;
char str[20];

int calc(int oprand1, int oprand2, char op){
    int ret = 0;
    if(op == '+'){
        ret = oprand1 + oprand2;
    }else if(op == '-'){
        ret = oprand1 - oprand2;
    }else if(op == '*'){
        ret = oprand1 * oprand2;
    }
    return ret;
}

void dfs(int result, int opIdx){
    int nowResult = 0, nextResult = 0;
    if(opIdx >= n){
        ans = max(ans, result);
        return;
    }
    nowResult = calc(result, str[opIdx+1] - 48, str[opIdx]);
    dfs(nowResult, opIdx+2);
    
    if(opIdx+2 < n){
        nextResult = calc(str[opIdx+1] - 48, str[opIdx+3] - 48, str[opIdx+2]);
        nowResult = calc(result, nextResult, str[opIdx]);
        dfs(nowResult, opIdx+4);
    }
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>str[i];
    }
    ans = -INT_MAX;
    dfs(str[0] - 48, 1);
    cout<<ans;
    return 0;
}
