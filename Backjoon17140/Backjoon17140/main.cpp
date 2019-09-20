#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct NUMBER{
    int num, cnt;
};
bool cmp(NUMBER a, NUMBER b){
    if(a.cnt != b.cnt) return a.cnt < b.cnt;
    else return a.num < b.num;
}
vector<NUMBER> number;
int arr[100][100];

int main()
{
    int r,c,k,time = 0;
    int rowsize = 3, colsize = 3;
    cin>>r>>c>>k;
    r--; c--;
    for(int y=0; y<rowsize; y++){
        for(int x=0; x<colsize; x++){
            cin>>arr[y][x];
        }
    }
    NUMBER n;
    while(time <= 100){
        if(arr[r][c] == k){
            break;
        }
        if(rowsize >= colsize){
            int cur_colmax = 0;
            for(int y=0; y<rowsize; y++){
                //vector에 저장하는 과정
                for(int x=0; x<colsize; x++){
                    if(arr[y][x] == 0) continue;
                    bool isExist = false;
                    for(int i=0; i<number.size(); i++){
                        if(number[i].num == arr[y][x]){
                            isExist = true;
                            number[i].cnt++;
                            arr[y][x] = 0;
                            break;
                        }
                    }
                    if(!isExist){
                        n.num = arr[y][x]; n.cnt = 1;
                        number.push_back(n);
                        arr[y][x] = 0;
                    }
                }
                //sort
                sort(number.begin(), number.end(), cmp);
                int idx = 0;
                for(int i=0; i<number.size() * 2; i+=2){
                    if(idx >= 50) break;
                    arr[y][i] = number[idx].num;
                    arr[y][i+1] = number[idx++].cnt;
                }
                cur_colmax = max(cur_colmax, idx*2);
                number.clear();
            }
            colsize = cur_colmax;
        }
        else{
            int cur_rowmax = 0;
            for(int x=0; x<colsize; x++){
                //vector 저장
                for(int y=0; y<rowsize; y++){
                    if(arr[y][x] == 0) continue;
                    bool isExist = false;
                    for(int i=0; i<number.size(); i++){
                        if(number[i].num == arr[y][x]){
                            isExist = true;
                            number[i].cnt++;
                            arr[y][x] = 0;
                            break;
                        }
                    }
                    if(!isExist){
                        n.num = arr[y][x]; n.cnt = 1;
                        number.push_back(n);
                        arr[y][x] = 0;
                    }
                }
                sort(number.begin(), number.end(), cmp);
                int idx = 0;
                for(int i=0; i<number.size() * 2; i+=2){
                    if(idx >= 50) break;
                    arr[i][x] = number[idx].num;
                    arr[i+1][x] = number[idx++].cnt;
                }
                cur_rowmax = max(cur_rowmax, idx*2);
                number.clear();
            }
            rowsize = cur_rowmax;
        }
        time++;
    }
    if(time > 100) time = -1;
    cout<<time;
    return 0;
}
