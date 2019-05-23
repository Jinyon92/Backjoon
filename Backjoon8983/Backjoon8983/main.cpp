#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int cal(int x, int a, int b)
{
    return abs(x-a)+b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int m,n,l;
    cin>>m>>n>>l;
    vector<int> sand(m);
    vector< pair<int, int> >animal(n);
    
    for(int i=0; i<m; i++)
        cin>>sand[i];
    for(int i=0; i<n; i++){
        cin>>animal[i].first>>animal[i].second;
    }
    sort(animal.begin(),animal.end());
    sort(sand.begin(), sand.end());
    int idx = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        while(idx != m-1 && sand[idx+1] - animal[i].first < 0){
            idx++;
        }
        if(cal(sand[idx], animal[i].first, animal[i].second) <= l){
            ans++;
            continue;
        }
        if(idx != m-1){
            if(cal(sand[idx+1], animal[i].first, animal[i].second) <= l){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
