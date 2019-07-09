#include <string>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> s1;
    multiset<string> s2;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    string temp = "";
    for(int i=0; i<str1.size()-1; i++){
        if(str1[i] >= 'a' && str1[i] <= 'z' && str1[i+1] >= 'a' && str1[i+1] <= 'z'){
            temp += str1[i];
            temp += str1[i+1];
            s1.insert(temp);
            temp ="";
        }
    }
    for(int i=0; i<str2.size()-1; i++){
        if(str2[i] >= 'a' && str2[i] <= 'z' && str2[i+1] >= 'a' && str2[i+1] <= 'z'){
            temp += str2[i];
            temp += str2[i+1];
            s2.insert(temp);
            temp ="";
        }
    }
    double total = s1.size() + s2.size();
    double intersectionNum = 0;
    for(auto it = s1.begin(); it != s1.end(); it++){
        auto iter = find(s2.begin(),s2.end(), *it);
        if(iter != s2.end()){
            s2.erase(iter);
            intersectionNum++;
        }
    }
    if(total != 0){
        double unionNum = total - intersectionNum;
        answer = 65536 * intersectionNum / unionNum;
    }else{
        answer  = 65536;
    }
    return answer;
}
