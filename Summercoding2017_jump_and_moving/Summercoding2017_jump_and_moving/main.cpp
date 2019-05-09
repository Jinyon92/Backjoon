
#include <iostream>
#include<cmath>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n != 0){
        if(n%2 == 0){
            n /= 2;
        }else{
            ans += 1;
            n /= 2;
        }
    }
    return ans;
}
