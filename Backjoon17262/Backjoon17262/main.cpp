#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

int main()
{
    int n;
    cin>>n;
    vector< pair<int, int> > time(n);
    for(int i=0; i<n; i++){
        cin>>time[i].first>>time[i].second;
    }
    sort(time.begin(), time.end(), cmp);
    int xPos = time[0].first;
    int yPos = time[0].second;
    int ansx = xPos;
    int ansy = yPos;
    bool flag = true;
    bool one = true;
    for(int i = 1; i<n; i++){
        if(yPos < time[i].first){
            flag = false;
            if(one){
                one = false;
                ansx = yPos;
            }
            ansy = time[i].first;
            xPos = time[i].first;
            yPos = time[i].second;
        }else{
            xPos = time[i].first;
            ansy = time[i].first;
            yPos = min(yPos, time[i].second);
        }
    }
    if(flag){
        cout<<0;
    }else{
        cout<<ansy-ansx;
    }
    return 0;
}
