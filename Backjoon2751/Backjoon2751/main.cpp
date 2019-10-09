#include<iostream>
using namespace std;
int arr[1000000];

void quicksort(int i, int j){
    if(i>=j) return;
    int pivot = arr[(i+j) / 2];
    int left = i;
    int right = j;
    
    while(left <= right){
        while(arr[left] < pivot) left++;
        while(arr[right] > pivot) right--;
        if(left <= right){
            swap(arr[left], arr[right]);
            left++; right--;
        }
    }
    quicksort(i,right);
    quicksort(left,j);
}

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
    quicksort(0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\n";
    }
    return 0;
}
