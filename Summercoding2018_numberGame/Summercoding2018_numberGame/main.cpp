#include <vector>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    stack<int> ast;
    stack<int> bst;
    for(int i=0; i<A.size(); i++){
        ast.push(A[i]);
        bst.push(B[i]);
    }
    while(!ast.empty()){
        int a = ast.top();
        int b = bst.top();
        if(b > a){
            answer++;
            bst.pop();
        }
        ast.pop();
    }
    return answer;
}
