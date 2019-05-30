#include<iostream>
using namespace std;

int arr[51][51];
int res[51][51];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&res[i][j]);
        }
    }
    int cnt = 0;
    for(int i=0; i<=n-3; i++){
        for(int j=0; j<=m-3; j++){
            if(arr[i][j] != res[i][j]){
                for(int k=i; k<i+3; k++){
                    for(int z=j; z<j+3; z++){
                        if(arr[k][z] == 1){
                            arr[k][z] = 0;
                        }else{
                            arr[k][z] = 1;
                        }
                    }
                }
                cnt++;
            }
        }
    }
    bool flag = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] != res[i][j]){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    if(flag)
        cout<<cnt;
    else
        cout<<-1;
    return 0;
}
