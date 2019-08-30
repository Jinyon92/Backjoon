#include<iostream>
using namespace std;

int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int map[101][101];

int main()
{
    int n ,ans = 0;
    cin>>n;
    int x,y,d,g;
    for(int i=0; i<n; i++){
        cin>>x>>y>>d>>g;
        map[y][x] = 1;
        int curve_size = 0;
        int curve[1024] = {0,};
        curve[curve_size++] = d;
        
        for(int j=0; j<g; j++){
            for(int k=curve_size-1; k>=0; k--){
                curve[curve_size++] = (curve[k] + 1) % 4;
            }
        }
        
        for(int j=0; j<curve_size; j++){
            y = y + dy[curve[j]];
            x = x + dx[curve[j]];
            
            if(y < 0 || y > 101 || x < 0 || x> 101) continue;
            map[y][x] = 1;
        }
    }
    
    for(int j=0; j<100; j++){
        for(int k=0; k<100; k++){
            if(map[j][k] && map[j][k+1] && map[j+1][k] && map[j+1][k+1]) ans++;
        }
    }
    cout<<ans;
    return 0;
}
