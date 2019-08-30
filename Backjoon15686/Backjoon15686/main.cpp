#include<stdio.h>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

int n, m, type, ans;
struct POSI {
    int x,y;
};
vector<POSI> house, shop, pick;

void dfs(int pos){
    if(pick.size() == m){
        int candi = 0;
        for(int i=0; i<house.size(); ++i){
            int minst = 98765421;
            for(int j=0; j<pick.size(); ++j){
                minst = min(minst, abs(house[i].y - pick[j].y) + abs(house[i].x - pick[j].x));
            }
            candi += minst;
        }
        ans = min(candi, ans);
        return;
    }
    for(int i=pos; i<shop.size(); ++i){
        pick.push_back(shop[i]);
        dfs(i+1);
        pick.pop_back();
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    POSI target;
    for(int y=0; y<n; ++y){
        for(int x=0; x<n; ++x){
            scanf("%d", &type);
            if(type == 1){
                target.y = y; target.x = x;
                house.push_back(target);
            }else if(type == 2){
                target.y = y; target.x = x;
                shop.push_back(target);
            }
        }
    }
    ans = INT_MAX;
    dfs(0);
    printf("%d", ans);
    return 0;
}
