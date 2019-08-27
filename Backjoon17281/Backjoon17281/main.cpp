#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int record[50][9], nusung[3];

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, ans = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<9; j++){
            cin>>record[i][j];
        }
    }
    vector<int> d = {1,2,3,4,5,6,7,8};
    do{
        int inning = 0, player = 0, out = 0, score = 0;
        int ord[9]; ord[3] = 0;
        for(int i=0; i<3; i++){
            ord[i] = d[i];
        }
        for(int i=3; i<8; i++){
            ord[i+1] = d[i];
        }
        memset(nusung, 0, sizeof(nusung));
        
        while(inning < n){
            if(record[inning][ord[player]] == 0){
                out += 1;
            }else if(record[inning][ord[player]] == 1){
                if(nusung[2] == 1){
                    score += 1;
                    nusung[2] = 0;
                }
                if(nusung[1] == 1){
                    nusung[2] = 1;
                    nusung[1] = 0;
                }
                if(nusung[0] == 1){
                    nusung[1] = 1;
                }
                nusung[0] = 1;
            }else if(record[inning][ord[player]] == 2){
                if(nusung[2] == 1){
                    score += 1;
                    nusung[2] = 0;
                }
                if(nusung[1] == 1){
                    score += 1;
                    nusung[1] = 0;
                }
                if(nusung[0] == 1){
                    nusung[2] = 1;
                    nusung[0] = 0;
                }
                nusung[1] = 1;
            }else if(record[inning][ord[player]] == 3){
                if(nusung[2] == 1){
                    score += 1;
                    nusung[2] = 0;
                }
                if(nusung[1] == 1){
                    score += 1;
                    nusung[1] = 0;
                }
                if(nusung[0] == 1){
                    score += 1;
                    nusung[0] = 0;
                }
                nusung[2] = 1;
            }else if(record[inning][ord[player]] == 4){
                int add = 0;
                for(int i=0; i<3; i++){
                    if(nusung[i] == 1){
                        add++;
                        nusung[i] = 0;
                    }
                }
                score += add + 1;
            }
            player++;
            if(player == 9) player = 0;
            if(out == 3){
                inning += 1;
                out = 0;
                memset(nusung, 0, sizeof(nusung));
            }
        }
        ans = max(score, ans);
    }while(next_permutation(d.begin(), d.end()));
    cout<<ans;
    return 0;
}
