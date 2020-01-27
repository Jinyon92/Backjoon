#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> A;
char S[11][11];

bool isPossible(int idx){
    int sum = 0;
    for(int i=idx; i>=0; i--){
        sum += A[i];
        if(S[i][idx] == '0' && sum != 0) return false;
        if(S[i][idx] == '-' && sum >= 0) return false;
        if(S[i][idx] == '+' && sum <= 0) return false;
    }
    return true;
}

void BackTracking(int num){
    if(A.size() == n){
        for(int i=0; i<A.size(); i++){
            cout<<A[i]<<" ";
        }
        cout<<endl;
        exit(0);
    }
    
    for(int i = -10; i<=10; i++){
        A.push_back(i);
        if(isPossible(num)) BackTracking(num+1);
        A.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    char sign;
    for(int y=0; y<n; y++){
        for(int x=y; x<n; x++){
            cin>>sign;
            S[y][x] = sign;
        }
    }
    BackTracking(0);
    return 0;
}
