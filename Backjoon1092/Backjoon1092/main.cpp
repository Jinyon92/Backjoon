#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lefting[51];

int main()
{
    int n,m;
    cin>>n;
    vector<int> crain(n);
    for(int i=0; i<n; i++){
        cin>>crain[i];
    }
    cin>>m;
    vector<int> box(m);
    for(int i=0; i<m; i++){
        cin>>box[i];
    }
    sort(crain.begin(), crain.end());
    sort(box.begin(), box.end());
    int idx = 0;
    for(int i=0; i<m;){
        if(crain[idx] >= box[i]){
            lefting[idx]++;
            i++;
        }else{
            if(idx < n-1){
                idx++;
            }else{
                break;
            }
        }
    }
    bool flag = true;
    if(crain[n-1] < box[m-1]){
        flag = false;
    }
    int ans = 0;
    while(flag){
        bool find = false;
        for(int i=0; i<n; i++){
            if(lefting[i]){
                lefting[i]--;
                find = true;
            }
            else{
                for(int j=i-1; j>=0; j--){
                    if(lefting[j]){
                        lefting[j]--;
                        find = true;
                        break;
                    }
                }
            }
        }
        if(!find) break;
        ans++;
    }
    if(flag)
        cout<<ans;
    else
        cout<<-1;
    return 0;
}
