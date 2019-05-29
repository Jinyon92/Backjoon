#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    string tmp="";
    cin>>s;
    int ans = 0;
    bool minus = false;
    for(int i=0; i<=s.size(); i++){
        if(s[i] == '-' || s[i] == '+' || s[i] == '\0'){
            if(minus){
                ans -= stoi(tmp);
            }else{
                ans += stoi(tmp);
            }
            tmp ="";
            if(s[i] == '-') minus = true;
            continue;
        }
        tmp += s[i];
    }
    cout<<ans;
    return 0;
}
