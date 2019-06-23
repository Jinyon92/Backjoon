#include<iostream>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    long long searchNum, numcount, numlength, ans, tenten;
    searchNum = 0; numcount = 9; numlength = 1; ans = 0; tenten = 1;
    int restK = k;
    while(restK > numcount * numlength){
        searchNum += numcount;
        restK -= numcount * numlength;
        numcount *= 10;
        numlength++;
    }
    searchNum += (restK-1)/numlength + 1;
    if(searchNum > n){
        ans = -1;
    }else{
        long long tmp = (restK-1)%numlength + 1;
        for(int i=0; i<numlength-1; i++){
            tenten *= 10;
        }
        for(int i=0; i<tmp; i++){
            ans = searchNum / tenten;
            searchNum %= tenten;
            tenten /= 10;
        }
    }
    cout<<ans;
    return 0;
}
