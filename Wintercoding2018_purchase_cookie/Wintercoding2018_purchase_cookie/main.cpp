#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int size = cookie.size();
    if(size < 2) return 0;
    if(size == 2){
        if(cookie[0] == cookie[1]){
            return cookie[0];
        }else
            return 0;
    }
    for(int i=0; i<size-1; i++){
        int frontIndex = i;
        int backIndex = i+1;
        int frontSum = cookie[frontIndex];
        int backSum = cookie[backIndex];
        while(1){
            if(frontSum == backSum){
                answer = max(answer, frontSum);
            }
            if(frontIndex > 0 && frontSum <= backSum){
                frontIndex--;
                frontSum += cookie[frontIndex];
            }
            else if(backIndex < size-1 &&  frontSum >= backSum){
                backIndex++;
                backSum += cookie[backIndex];
            }
            else break;
        }
    }
    return answer;
}
