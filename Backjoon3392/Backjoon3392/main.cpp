#include<iostream>
#include<algorithm>
using namespace std;

struct spot{
    int x1, y1, y2, counter;
};
bool cmp(spot s1, spot s2)
{
    return s1.x1 < s2.x1;
}
spot arr[20000];
int tree[120000];
int cnt[120000];
void update(int low, int high, int node, int start, int end, int counter)
{
    if(low > end || high < start) return;
    if(low <= start && end <= high){
        cnt[node] += counter;
    }else{
        update(low, high, node*2, start, (start+end)/2, counter);
        update(low, high, node*2+1, (start+end)/2 + 1, end, counter);
    }
    if(cnt[node]) tree[node] = end-start + 1;
    else{
        if(start == end) tree[node] = 0;
        else{
            tree[node] = tree[node*2] + tree[node*2 + 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    int a,b,c,d;
    for(int i=0; i<n; i++){
        cin>>a>>b>>c>>d;
        arr[i] = {a,b,d-1,1};
        arr[i+n] = {c,b,d-1,-1};
    }
    sort(arr,arr+n*2,cmp);
    int ans, last, dx;
    ans = 0; last = 0; dx = 0;
    for(int i=0; i<2*n; i++){
        if(i){
            dx = arr[i].x1 - last;
            ans += dx*tree[1];
        }
        update(arr[i].y1, arr[i].y2, 1, 0, 30000, arr[i].counter);
        last = arr[i].x1;
    }
    cout<<ans;
    return 0;
}

