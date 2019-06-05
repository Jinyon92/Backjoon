#include<iostream>
#include<string>
using namespace std;

int main()
{
    string n;
    int m;
    cin>>n>>m;
    int size = stoi(n);
    string tmp = "";
    for(int i=0; i<size; i++){
        tmp += n;
    }
    if(tmp.size() > m){
        tmp = tmp.substr(0,m);
    }
    cout<<tmp;
    return 0;
}
