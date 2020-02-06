#include<iostream>
#include<algorithm>
using namespace std;

int N, ans;
struct INFO{
    int d, w;
}info[8];

void permutation(int choice){
    if(choice >= N){
        int cnt = 0;
        for(int i=0; i<N; i++){
            if(info[i].d <= 0) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    if(info[choice].d <= 0) permutation(choice+1);
    else{
        bool flag = false;
        for(int i=0; i<N; i++){
            if(choice == i || info[i].d <= 0) continue;
            
            info[i].d -= info[choice].w;
            info[choice].d -= info[i].w;
            flag = true;
            permutation(choice+1);
            info[i].d += info[choice].w;
            info[choice].d += info[i].w;
        }
        if(!flag) permutation(N);
    }
}

int main()
{
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>info[i].d>>info[i].w;
    }
    permutation(0);
    cout<<ans;
}
