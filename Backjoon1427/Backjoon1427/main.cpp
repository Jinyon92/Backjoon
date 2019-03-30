#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    cin>>str;
    sort(str.begin(),str.end());
    reverse(str.begin(), str.end());
    cout<<str;
    return 0;
}
