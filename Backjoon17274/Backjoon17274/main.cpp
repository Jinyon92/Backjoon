#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    vector<int> front, back, key;
    int v1, v2, num;
    long long ans = 0;
    for(int i=0; i<n; i++){
        cin>>v1>>v2;
        front.push_back(v1);
        back.push_back(v2);
    }
    key = front;
    for(int i=0; i<m; i++){
        cin>>num;
        for(int j=0; j<n; j++){
            if(key[j] <= num){
                if(key[j] == front[j])
                    key[j] = back[j];
                else if(key[j] == back[j])
                    key[j] = front[j];
            }
        }
    }
    for(int i=0; i<n; i++){
        ans += key[i];
    }
    cout<<ans;
    return 0;
}
