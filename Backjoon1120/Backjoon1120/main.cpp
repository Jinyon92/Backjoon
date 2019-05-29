#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    int cnt = 0;
    int ans = 987654321;
    int size = s2.size() - s1.size();
    for(int i=0; i<=size; i++){
        cnt = 0;
        for(int j=i; j<i+s1.size(); j++){
            if(s1[j-i] != s2[j]){
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    cout<<ans;
    return 0;
}
