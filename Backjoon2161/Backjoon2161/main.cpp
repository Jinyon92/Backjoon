#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main()
{
    list<int> l;
    vector<int> ans;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        l.push_back(i);
    }
    while(l.size() != 1){
        int num = l.front();
        l.pop_front();
        ans.push_back(num);
        int num2 = l.front();
        l.pop_front();
        l.push_back(num2);
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<l.front();
    return 0;
}
