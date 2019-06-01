#include<iostream>
using namespace std;
int t[101];
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int start,end;
    for(int i=0; i<3; i++){
        cin>>start>>end;
        for(int j=start; j<end; j++)
            t[j]++;
    }
    int sum = 0;
    for(int i=1; i<101; i++){
        if(t[i] == 3)
            sum += c*3;
        else if(t[i] == 2)
            sum += b*2;
        else if(t[i] == 1)
            sum += a;
    }
    cout<<sum;
    return 0;
}
