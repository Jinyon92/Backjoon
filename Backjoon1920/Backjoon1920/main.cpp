#include<iostream>
#include<algorithm>
using namespace std;

int a[100001];

void binary(int n, int key)
{
    int start = 0;
    int end = n-1;
    int mid;
    while(end >= start){
        mid = (start+end)/2;
        if(a[mid] == key){
            cout<<1<<"\n";
            return ;
        }
        else if(a[mid] > key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    cout<<0<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cin>>m;
    sort(a,a+n);
    int num;
    for(int i=0; i<m; i++){
        cin>>num;
        binary(n, num);
    }
    return 0;
}
