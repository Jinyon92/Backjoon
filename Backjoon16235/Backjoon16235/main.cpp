#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TREE{
    int y, x, age;
};
int map[10][10], add[10][10];
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            cin>>add[y][x];
            map[y][x] = 5;
        }
    }
    TREE tree;
    vector<TREE> origin_tree;
    vector<TREE> young_tree;
    for(int i=0; i<m; i++){
        cin>>tree.y>>tree.x>>tree.age;
        tree.y -= 1; tree.x -= 1;
        origin_tree.push_back(tree);
    }
    queue<TREE> life_tree;
    queue<TREE> dead_tree;
    for(int i=0; i<k; i++){
        for(int j=0; j<young_tree.size(); j++){
            if(map[young_tree[j].y][young_tree[j].x] >= young_tree[j].age){
                map[young_tree[j].y][young_tree[j].x] -= young_tree[j].age;
                young_tree[j].age += 1;
                life_tree.push(young_tree[j]);
            }else{
                dead_tree.push(young_tree[j]);
            }
        }
        young_tree.clear();
        
        for(int j=0; j<origin_tree.size(); j++){
            if(map[origin_tree[j].y][origin_tree[j].x] >= origin_tree[j].age){
                map[origin_tree[j].y][origin_tree[j].x] -= origin_tree[j].age;
                origin_tree[j].age += 1;
                life_tree.push(origin_tree[j]);
            }else{
                dead_tree.push(origin_tree[j]);
            }
        }
        origin_tree.clear();
        
        while(!dead_tree.empty()){
            TREE cur_tree = dead_tree.front(); dead_tree.pop();
            map[cur_tree.y][cur_tree.x] += (cur_tree.age / 2);
        }
        
        while(!life_tree.empty()){
            TREE cur_tree = life_tree.front(); life_tree.pop();
            if(cur_tree.age % 5 == 0){
                TREE next_tree;
                for(int dir = 0; dir<8; dir++){
                    next_tree.y = cur_tree.y + dy[dir];
                    next_tree.x = cur_tree.x + dx[dir];
                    next_tree.age = 1;
                    if(next_tree.y < 0 || next_tree.y >= n || next_tree.x < 0 || next_tree.x >= n) continue;
                    young_tree.push_back(next_tree);
                }
            }
            origin_tree.push_back(cur_tree);
        }
        
        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                map[y][x] += add[y][x];
            }
        }
    }
    cout<<origin_tree.size() + young_tree.size();
    return 0;
}
