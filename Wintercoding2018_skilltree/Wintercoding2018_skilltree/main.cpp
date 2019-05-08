#include <string>
#include <vector>
#include<iostream>
#include<map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<int, char> m;
    for(int i=0; i<skill.size(); i++){
        m.insert(make_pair(i,skill[i]));
    }
    for(auto tree : skill_trees){
        int now = 0;
        bool flag = true;
        for(int i=0; i<tree.size(); i++){
            for(int j=0; j<skill.size(); j++){
                if(tree[i] == m[j]){
                    if(now == j){
                        now++;
                    }else{
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            answer++;
        }
    }
    return answer;
}
