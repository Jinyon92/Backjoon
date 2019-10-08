#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct ROTATEINFO{
    int r,c,s;
};
int map[51][51];
int n,m,k;
ROTATEINFO info[6];

void copy_arr(int a[51][51], int b[51][51]){
    for(int y=0; y<=n; y++){
        for(int x=0; x<=m; x++){
            a[y][x] = b[y][x];
        }
    }
}
void rotate_cycle(ROTATEINFO info){
    int sy = info.r - info.s; int sx = info.c - info.s;
    int fy = info.r + info.s; int fx = info.c + info.s;
    while(1){
        int tmp1 = map[sy][fx];
        for(int x=fx; x > sx; x--){
            map[sy][x] = map[sy][x-1];
        }
        int tmp2 = map[fy][fx];
        for(int y=fy; y >sy+1; y--){
            map[y][fx] = map[y-1][fx];
        }
        map[sy+1][fx] = tmp1;
        tmp1 = map[fy][sx];
        for(int x=sx; x < fx-1; x++){
            map[fy][x] = map[fy][x+1];
        }
        map[fy][fx-1] = tmp2;
        for(int y=sy; y < fy-1; y++){
            map[y][sx] = map[y+1][sx];
        }
        map[fy-1][sx] = tmp1;
        sy++; sx++;
        fy--; fx--;
        if(sy == fy && sx == fx) break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>k;
    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            cin>>map[y][x];
        }
    }
    vector<int> v(k);
    for(int i=0; i<k; i++){
        cin>>info[i].r>>info[i].c>>info[i].s;
        v[i] = i;
    }
    int ret = 987654321;
    do{
        int temp[51][51] = {0,};
        copy_arr(temp, map);
        for(int i=0; i<k; i++){
            rotate_cycle(info[v[i]]);
        }
        for(int y=1; y<=n; y++){
            int sum = 0;
            for(int x=1; x<=m; x++){
                sum += map[y][x];
            }
            ret = min(ret, sum);
        }
        copy_arr(map, temp);
    }while(next_permutation(v.begin(), v.end()));
    
    cout<<ret;
    return 0;
}
