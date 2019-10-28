#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size();
    int n = lock.size();
    int rkey[4][20][20] = {0,};
    
    for(int y=0; y<m; y++){
        for(int x=0; x<m; x++){
            rkey[0][y][x] = key[y][x];
        }
    }
    for(int r=1; r<4; r++){
        for(int y=0; y<m; y++){
            for(int x=0; x<m; x++){
                rkey[r][y][x] = rkey[r-1][m-1-x][y];
            }
        }
    }
    int hom = 0;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            if(lock[y][x] == 0) hom++;
        }
    }
    for(int y=-m+1; y<n; y++){
        for(int x=-m+1; x<n; x++){
            int nowhom = 0;
            for(int i=0; i<m; i++){
                if(y+i < 0 || y+i >=n) continue;
                for(int j=0; j<m; j++){
                    if(x+j < 0 || x+j >= n) continue;
                    if(lock[y+i][x+j] == 0) nowhom++;
                }
            }
            if(hom != nowhom) continue;
            for(int r=0; r<4; r++){
                for(int i=0; i<m; i++){
                    if(y+i < 0 || y+i >=n) continue;
                    for(int j=0; j<m; j++){
                        if(x+j < 0 || x+j >= n) continue;
                        if(rkey[r][i][j] + lock[y+i][x+j] != 1){
                            goto exit;
                        }
                    }
                }
                return 1;
                exit:;
            }
        }
    }
    return 0;
}
