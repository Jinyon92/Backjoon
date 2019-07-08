#include <string>
#include <vector>
#include<iostream>
#include<cmath>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        ans[i] = arr1[i] | arr2[i];
    }
    for(int i=0; i<n; i++){
        string str = "";
        int cnt = 0;
        while(ans[i] != 1){
            cnt++;
            int binary = ans[i] % 2;
            if(binary == 0){
                str = " "+str;
            }else{
                str = "#"+str;
            }
            ans[i] /= 2;
        }
        str = "#"+str;
        while(cnt < n-1){
            str = " "+str;
            cnt++;
        }
        answer.push_back(str);
    }
    return answer;
}
