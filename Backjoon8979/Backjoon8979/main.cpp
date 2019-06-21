#include<iostream>
#include<algorithm>
using namespace std;

struct medal{
    int country, gold, sliver, dong;
};
medal arr[1001];

bool cmp(medal & a, medal & b){
    if(a.gold != b.gold) return b.gold < a.gold;
    else{
        if(a.sliver != b.sliver) return b.sliver < a.sliver;
        else{
            if(a.dong != b.dong) return b.dong < a.dong;
        }
    }
    return b.dong < a.dong;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    cin>>n>>k;
    int c, g, s, d;
    for(int i=0; i<n; i++){
        cin>>c>>g>>s>>d;
        arr[i].country = c;
        arr[i].gold = g;
        arr[i].sliver = s;
        arr[i].dong = d;
    }
    sort(arr, arr+n, cmp);
    int idx = 0;
    for(int i=0; i<n; i++){
        if(k==arr[i].country){
            idx = i;
            break;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(arr[i].gold == arr[idx].gold && arr[i].sliver == arr[idx].sliver && arr[i].dong == arr[idx].dong){
            ans = i+1;
            break;
        }
    }
    cout<<ans;
    return 0;
}
