#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int front, back, num;
    cin>>front>>back;
    int key = front;
    for(int i=0; i<m; i++){
        cin>>num;
        if(key <= num){
            if(key == front)
                key = back;
            else if(key == back)
                key = front;
        }
    }
    cout<<key;
    return 0;
}
