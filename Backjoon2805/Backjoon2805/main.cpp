#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N,M;
    long long left = 0, right = 0;
    long long ret = 0;
    cin>>N>>M;
    
    vector<long long> tree(N);
    for(int i=0; i<N; i++){
        cin>>tree[i];
        if(tree[i] > right) right = tree[i];
    }
    
    while(left <= right){
        long long mid = (left + right) / 2;
        long long total = 0;
        
        for(int i=0; i<N; i++){
            if(tree[i] > mid) total += tree[i] - mid;
        }
        
        if(total >= M){
            if(ret < mid)
                ret = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    cout<<ret;
    return 0;
}
