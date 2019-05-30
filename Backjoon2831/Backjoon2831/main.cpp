#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> h_m; vector<int> l_m;
    vector<int> h_w; vector<int> l_w;
    int h;
    for(int i=0; i<n; i++){
        cin>>h;
        if(h < 0){
            l_m.push_back(abs(h));
        }else{
            h_m.push_back(h);
        }
    }
    for(int i=0; i<n; i++){
        cin>>h;
        if(h < 0){
            l_w.push_back(abs(h));
        }else{
            h_w.push_back(h);
        }
    }
    sort(l_m.begin(), l_m.end()); sort(h_m.begin(), h_m.end());
    sort(l_w.begin(), l_w.end()); sort(h_w.begin(), h_w.end());
    int midx = 0;
    int widx = 0;
    int cnt = 0;
    while(l_m.size() > midx && h_w.size() > widx){
        if(l_m[midx] > h_w[widx]){
            cnt++; midx++; widx++;
        }else{
            midx++;
        }
    }
    midx = 0;
    widx = 0;
    while(h_m.size() > midx && l_w.size() > widx){
        if(h_m[midx] < l_w[widx]){
            cnt++; midx++; widx++;
        }else{
            widx++;
        }
    }
    cout<<cnt;
    return 0;
}
