#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

double total[501];
double fail[501];
bool cmp(const pair<int, double> &a, const pair<int, double> &b){
    if(a.second != b.second) return a.second > b.second;
    else{
        return a.first < b.first;
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector< pair<int, double> > failRate(N);
    for(int i=0; i<stages.size(); i++){
        for(int j=stages[i]; j>=1; j--){
            total[j]++;
        }
    }
    for(int i=0; i<stages.size(); i++){
        fail[stages[i]]++;
    }
    for(int i=1; i<=N; i++){
        failRate[i-1].first = i;
        if(total[i] != 0)
            failRate[i-1].second = fail[i] / total[i];
        else
            failRate[i-1].second = 0;
    }
    sort(failRate.begin(), failRate.end(), cmp);
    for(int i=0; i<N; i++){
        answer.push_back(failRate[i].first);
    }
    return answer;
}
