#include<iostream>
#include<algorithm>
using namespace std;

int multi[101];
int schedule[101];

int main()
{
    int n, k;
    cin>>n>>k;
    for(int i=0; i<k; i++){
        cin>>schedule[i];
    }
    int ans = 0;
    for(int i=0; i<k; i++){
        bool plugin = false;
        
        for(int j=0; j<n; j++){
            if(multi[j] == schedule[i]){
                plugin = true;
                break;
            }
        }
        if(plugin) continue;
        
        for(int j=0; j<n; j++){
            if(!multi[j]){
                multi[j] = schedule[i];
                plugin = true;
                break;
            }
        }
        if(plugin) continue;
        
        int idx, deviceIdx = -1;
        for(int j=0; j<n; j++){
            int lastidx = 0;
            for(int a=i+1; a<k; a++){
                if(multi[j] == schedule[a]) break;
                lastidx++;
            }
            if(lastidx > deviceIdx){
                deviceIdx = lastidx;
                idx = j;
            }
        }
        ans++;
        multi[idx] = schedule[i];
    }
    cout<<ans;
    return 0;
}
