#include <iostream>
#include <queue>

using namespace std;

int arr[1001];
int n;

void radix_sort(){
    queue<int> radix[10];
    int max = arr[0];
    int d = 1;
    
    for(int i=1; i<n; i++){
        if(max < arr[i]) max = arr[i];
    }
    
    while(max / 10){
        d *= 10;
        max /= 10;
    }
    
    int dMin = 1;
    int mod = 10;
    
    while(dMin <= d){
        for(int i=0; i<n; i++){
            radix[(arr[i] % mod) / dMin].push(arr[i]);
        }
        
        for(int i=0, j=0; i<10;){
            if(radix[i].size()){
                arr[j++] = radix[i].front();
                radix[i].pop();
            }
            else i++;
        }
        
        dMin *= 10;
        mod *= 10;
    }
}

int main()
{
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    radix_sort();
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\n";
    }
    return 0;
}
