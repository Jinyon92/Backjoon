#include<iostream>
#include<string>
#include<set>
using namespace std;

set<string> store;
string s;
void dfs(int leftPos, int rightPos, string str){
    if(leftPos == 0 && rightPos == s.size()-1){
        store.insert(str);
        return;
    }else{
        if(leftPos > 0) dfs(leftPos - 1, rightPos, str + s[leftPos - 1] + str);
        if(rightPos < s.size() - 1) dfs(leftPos, rightPos + 1, str + str + s[rightPos + 1]);
    }
}

int main()
{
    cin>>s;
    for(int i=0; i<s.size(); i++){
        string temp = "";
        temp += s[i];
        dfs(i,i,temp);
    }
    cout<<store.size();
    return 0;
}
