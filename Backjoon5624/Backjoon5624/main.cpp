#include<iostream>
using namespace std;

int arr[5001];
bool range[400001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            int gap = arr[i] - arr[j];
            if(range[gap + 200000]){
                ans++;
                break;
            }
        }
        for(int j=0; j<=i; j++){
            range[arr[i] + arr[j] + 200000] = true;
        }
    }
    cout<<ans;
    return 0;
}
