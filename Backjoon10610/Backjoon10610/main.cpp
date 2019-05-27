#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    vector<int> n;
    int a;
    for(int i=0; i<s.length(); i++){
        a = s[i] - '0';
        n.push_back(a);
    }
    sort(n.begin(), n.end(), greater<int>());
    int size = n.size();
    int sum = 0;
    if(n[size - 1] != 0){
        cout<<-1;
    }else{
        for(int i=0; i<size - 1; i++){
            sum += n[i];
        }
        if(sum % 3 == 0){
            for(int i=0; i<size; i++){
                cout<<n[i];
            }
        }else{
            cout<<-1;
        }
    }
    return 0;
}
