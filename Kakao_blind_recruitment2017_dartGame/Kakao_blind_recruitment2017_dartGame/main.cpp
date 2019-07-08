#include <string>
#include<iostream>
#include<cmath>
using namespace std;

const int MAX = 987654321;

int solution(string dartResult) {
    int answer = 0;
    string str = "";
    int first = MAX; int second = MAX; int third = MAX;
    for(int i=0; i<dartResult.size(); i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            str += dartResult[i];
        }else{
            if(dartResult[i] == 'S'){
                if(first == MAX){
                    first = stoi(str);
                }
                else if(second == MAX){
                    second = stoi(str);
                }
                else if(third == MAX){
                    third = stoi(str);
                }
            }
            else if(dartResult[i] == 'D'){
                if(first == MAX){
                    first = stoi(str);
                    first = pow(first,2);
                }
                else if(second == MAX){
                    second = stoi(str);
                    second = pow(second,2);
                }
                else if(third == MAX){
                    third = stoi(str);
                    third = pow(third,2);
                }
            }
            else if(dartResult[i] == 'T'){
                if(first == MAX){
                    first = stoi(str);
                    first = pow(first,3);
                }
                else if(second == MAX){
                    second = stoi(str);
                    second = pow(second,3);
                }
                else if(third == MAX){
                    third = stoi(str);
                    third = pow(third,3);
                }
            }
            else if(dartResult[i] == '*'){
                if(second == MAX){
                    first *= 2;
                }
                else if(third == MAX){
                    first *= 2;
                    second *= 2;
                }
                else if(third != MAX){
                    second *= 2;
                    third *= 2;
                }
            }
            else if(dartResult[i] == '#'){
                if(second == MAX){
                    first = -first;
                }
                else if(third == MAX){
                    second = -second;
                }
                else if(third != MAX){
                    third = -third;
                }
            }
            str ="";
        }
    }
    answer = first+second+third;
    return answer;
}

