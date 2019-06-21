#include<iostream>
#include<cstring>
using namespace std;

int alpha[26];

int main()
{
    int t;
    cin>>t;
    for(int test_case = 0; test_case<t; test_case++){
        string msg;
        cin>>msg;
        bool flag = true;
        int idx = 0;
        for(int i=0; i<msg.size(); i++){
            idx = msg[i]-65;
            alpha[idx]++;
            if(alpha[idx] == 3){
                if(msg[i] != msg[i+1]){
                    flag = false;
                    break;
                }else{
                    alpha[idx] = 0;
                    i++;
                }
            }
        }
        if(!flag)
            cout<<"FAKE"<<"\n";
        else
            cout<<"OK"<<"\n";
        memset(alpha, 0, sizeof(alpha));
    }
    return 0;
}
