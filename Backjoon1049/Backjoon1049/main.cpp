#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    vector< pair<int, int> > price(m);
    for(int i=0; i<m; i++){
        cin>>price[i].first>>price[i].second;
    }
    int x = n / 6;
    int r = n % 6;
    sort(price.begin(), price.end());
    int ans = 0;
    int c = price[0].first;
    sort(price.begin(), price.end(), cmp);
    int d = price[0].second;
    if(d*6 < c){
        ans += d*6*x;
    }else{
        ans += c*x;
    }
    if(d*r > c){
        ans += c;
    }else{
        ans += d*r;
    }
    cout<<ans;
    return 0;
}
