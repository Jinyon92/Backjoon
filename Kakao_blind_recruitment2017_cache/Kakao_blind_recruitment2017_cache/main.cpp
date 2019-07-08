#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    for(int i=0; i<cities.size(); i++){
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        auto it = find(cache.begin(), cache.end(), city);
        if(it != cache.end()){
            answer += 1;
            cache.erase(it);
        }else{
            answer += 5;
            if(cache.size() == cacheSize && cacheSize != 0){
                cache.erase(cache.end());
            }
        }
        if(cacheSize != 0){
            cache.insert(cache.begin(), city);
        }
    }
    return answer;
}
