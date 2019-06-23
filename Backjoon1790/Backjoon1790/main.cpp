#include<iostream>
using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;
    long long totalnum, numcount, numlength, tenten, ans, calK;
    numcount = 9; numlength = 1; tenten = 1; totalnum = 0;
    calK = k;
    while(calK > numcount * numlength){
        totalnum += numcount;
        calK -= numcount * numlength;
        numcount *= 10;
        numlength++;
    }
    totalnum += (calK-1)/numlength + 1;
    if(totalnum > n){
        ans = -1;
    }else{
        long long tmp = (calK-1)%numlength + 1;
        for(int i=0; i<numlength - 1; i++){
            tenten *= 10;
        }
        for(int i=0; i<tmp; i++){
            ans = totalnum / tenten;
            totalnum %= tenten;
            tenten /= 10;
        }
    }
    cout<<ans;
    return 0;
}
