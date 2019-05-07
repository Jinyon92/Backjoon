#include <string>
#include <vector>
#include <iostream>
#include<cmath>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> store;
    store.push_back(words[0]);
    int cnt = 1;
    bool flag = true;
    for(int i=1; i<words.size(); i++){
        cnt++;
        int len = words[i-1].size();
        if(words[i][0] == words[i-1][len-1]){
            for(auto now : store){
                if(now == words[i]){
                    flag = false;
                }
            }
            if(flag){
                store.push_back(words[i]);
            }else{
                break;
            }
        }else{
            flag = false;
            break;
        }
    }
    if(!flag){
        int person = 0;
        if(cnt % n == 0){
            person = n;
        }else{
            person = cnt % n;
        }
        answer.push_back(person);
        int wrong = ceil((double)cnt / n);
        answer.push_back(wrong);
    }else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
