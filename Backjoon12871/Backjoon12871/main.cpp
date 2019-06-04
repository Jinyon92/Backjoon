#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    string t;
    cin>>s>>t;
    if(s.size() > t.size()){
        string tmp = "";
        tmp = s;
        s = t;
        t = tmp;
    }
    bool flag = true;
    t += t;
    int sidx = 0; int tidx = 0;
    while(tidx < t.size()){
        if(s[sidx] != t[tidx]){
            flag = false;
            break;
        }
        sidx++;
        tidx++;
        if(sidx == s.size()){
            sidx = 0;
        }
    }
    if(flag) cout<<1;
    else cout<<0;
    return 0;
}
