#include<iostream>
#include<cstring>
using namespace std;

int n,L,ans;
int map[100][100];
int setup[100][100];

void solution()
{
    for(int y=0; y<n; y++){
        bool flag = true;
        int key = map[y][0];
        for(int x=1; x<n; x++){
            if(key == map[y][x]) {
                continue;
            }else if(key - 1 == map[y][x]){
                bool verify = true;
                if(x+L <= n){
                    setup[y][x] = 1;
                    for(int i=x+1; i<x+L; i++){
                        if(map[y][x] == map[y][i] && !setup[y][i]) {
                            setup[y][i] = 1;
                            continue;
                        }
                        else {
                            verify = false;
                            break;
                        }
                    }
                }else{
                    flag = false;
                    break;
                }
                if(verify){
                    x += L-1;
                    key = map[y][x];
                }else{
                    flag = false;
                    break;
                }
            }else if(key + 1 == map[y][x]){
                bool verify = true;
                if(x-L >= 0){
                    for(int i=x-1; i>=x-L; i--){
                        if(key == map[y][i] && !setup[y][i]) {
                            setup[y][i] = 1;
                            continue;
                        }
                        else {
                            verify = false;
                            break;
                        }
                    }
                }else{
                    flag = false;
                    break;
                }
                if(verify){
                    key = map[y][x];
                }else{
                    flag = false;
                    break;
                }
            }else{
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }
    memset(setup, 0, sizeof(setup));
    
    for(int x=0; x<n; x++){
        bool flag = true;
        int key = map[0][x];
        for(int y=1; y<n; y++){
            if(key == map[y][x]) {
                continue;
            }else if(key - 1 == map[y][x]){
                bool verify = true;
                if(y+L <= n){
                    setup[y][x] = 1;
                    for(int i=y+1; i<y+L; i++){
                        if(map[y][x] == map[i][x] && !setup[i][x]) {
                            setup[i][x] = 1;
                            continue;
                        }
                        else {
                            verify = false;
                            break;
                        }
                    }
                }else{
                    flag = false;
                    break;
                }
                if(verify){
                    y += L-1;
                    key = map[y][x];
                }else{
                    flag = false;
                    break;
                }
            }else if(key + 1 == map[y][x]){
                bool verify = true;
                if(y-L >= 0){
                    for(int i=y-1; i>=y-L; i--){
                        if(key == map[i][x] && !setup[i][x]) {
                            setup[i][x] = 1;
                            continue;
                        }
                        else {
                            verify = false;
                            break;
                        }
                    }
                }else{
                    flag = false;
                    break;
                }
                if(verify){
                    key = map[y][x];
                }else{
                    flag = false;
                    break;
                }
            }else{
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }
     
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>L;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin>>map[y][x];
        }
    }
    solution();
    cout<<ans;
    return 0;
}
