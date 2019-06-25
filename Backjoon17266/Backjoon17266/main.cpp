#include<iostream>
#include<vector>
using namespace std;

vector< pair<int, int> > v;
int light[100001];

int main()
{
    int n,m;
    cin>>n>>m;
    int left = 0;
    int right = n;
    int mid, height;
    pair<int, int> ans;
    for(int i=0; i<m; i++){
        cin>>light[i];
    }
    bool flag;
    while(left <= right){
        flag = true;
        mid = (left+right)/2;
        for(int i=0; i<m; i++){
            v.push_back(make_pair(light[i]-mid, light[i]+mid));
        }
        ans.first = v[0].first;
        ans.second = v[0].second;
        for(int i=1; i<m; i++){
            if(ans.second >= v[i].first){
                ans.second = v[i].second;
            }else{
                flag = false;
            }
        }
        if(flag){
            if(ans.first <= 0 && ans.second >= n){
                height = mid;
                right = mid - 1;
            }else{
                left = mid+1;
            }
        }else{
            left = mid+1;
        }
        v.clear();
    }
    cout<<height;
    return 0;
}
