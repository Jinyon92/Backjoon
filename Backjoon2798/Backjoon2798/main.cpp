#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,m,num;
    cin>>n>>m;
    vector<int> card;
    for(int i=0; i<n; i++){
        cin>>num;
        card.push_back(num);
    }
    int sum = 0;
    int ans = 0;
    bool flag = false;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                sum = card[i] + card[j] + card[k];
                if(sum == m){
                    ans = sum;
                    flag = true;
                    break;
                }
                else if(sum > m){
                    continue;
                }
                else if(sum < m){
                    ans = max(ans, sum);
                }
            }
            if(flag)
                break;
        }
        if(flag)
            break;
    }
    cout<<ans;
    return 0;
}
