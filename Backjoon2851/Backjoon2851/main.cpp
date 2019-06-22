#include<iostream>
using namespace std;

int arr[10];

int main()
{
    for(int i=0; i<10; i++){
        cin>>arr[i];
    }
    int key1, key2;
    int sum = 0;
    int idx = 0;
    for(int i=0; i<10; i++){
        sum += arr[i];
        if(sum >= 100){
            idx = i;
            break;
        }
    }
    int ans = sum - arr[idx];
    key1 = 100 - ans;
    key2 = sum - 100;
    if(key1 > key2){
        cout<<sum;
    }
    else if(key1 < key2){
        cout<<ans;
    }else{
        cout<<sum;
    }
    return 0;
}
