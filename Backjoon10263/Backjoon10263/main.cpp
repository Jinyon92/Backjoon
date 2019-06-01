#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> tower(n);
    for(int i=0; i<n; i++){
        cin>>tower[i];
    }
    sort(tower.begin(), tower.end());
    int ans = n;
    for(int i=0; i<n; i++){
        ans = min(ans, tower[i] + n -i -1);
    }
    cout<<ans;
    return 0;
}
