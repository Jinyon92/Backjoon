#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,super,bu_super;
    long long ans = 0;
    cin>>n;
    vector<int> room(n);
    for(int i=0; i<n; i++){
        cin>>room[i];
    }
    cin>>super>>bu_super;
    for(int i=0; i<n; i++){
        ans += 1;
        room[i] = room[i] - super;
        if(room[i] > 0){
            int temp = room[i];
            int rest = temp % bu_super;
            temp /= bu_super;
            if(rest == 0){
                ans += temp;
            }else{
                ans += temp+1;
            }
        }
    }
    cout<<ans;
    return 0;
}
