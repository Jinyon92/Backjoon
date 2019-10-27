#include <string>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool is_verify(string str){
    int cnt = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '(') cnt++;
        else cnt--;
        
        if(cnt < 0) return false;
    }
    return true;
}

string solve(string u, string ans){
    if(u == "") return ans;
    
    int open = 0; int close = 0;
    for(int i=0; i<u.size(); i++){
        if(u[i] == '(') open++;
        else close++;
        
        if(open == close) break;
    }
    
    string temp_u = ""; string temp_v = "";
    for(int i=0; i<open*2; i++){
        temp_u += u[i];
    }
    for(int i=open*2; i<u.size(); i++){
        temp_v += u[i];
    }
    
    if(is_verify(temp_u)){
        ans += temp_u;
        return solve(temp_v, ans);
    }
    else{
        string tmp = "(";
        tmp += solve(temp_v, "");
        tmp += ")";
        string add = temp_u.substr(1, temp_u.size() - 2);
        string a;
        for(int i=0; i<add.size(); i++){
            if(add[i] == '(') a += ")";
            else a += "(";
        }
        tmp += a;
        ans += tmp;
        return ans;
    }
}

string solution(string p) {
    string answer = "";
    answer = solve(p,"");
    return answer;
}
