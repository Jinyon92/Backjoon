#include<iostream>
#include<vector>
#include<queue>
using namespace std;

char map[501][501];
bool is_ans[501][501] = {false};
int visit[501][501];
int n,m;
int a[4] = {1,0,-1,0};
int b[4] = {0,1,0,-1};
queue< pair<int, int> > que;
vector< pair<int, int> > v;

void dfs(int i, int j)
{
    que.push(make_pair(i, j));
    while(!que.empty())
    {
        auto now = que.front();
        int x = now.first;
        int y = now.second;
        que.pop();
        visit[x][y] = 1;
        if(is_ans[x][y])
        {
            for(auto ans : v)
            {
                is_ans[ans.first][ans.second] = true;
            }
            v.clear();
            break;
        }
        int nextX, nextY;
        if(map[x][y] == 'D')
        {
            nextX = x + a[0];
            nextY = y + b[0];
        }
        else if(map[x][y] == 'R'){
            nextX = x + a[1];
            nextY = y + b[1];
        }
        else if(map[x][y] == 'U'){
            nextX = x + a[2];
            nextY = y + b[2];
        }else{
            nextX = x + a[3];
            nextY = y + b[3];
        }
        
        if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
        {
            is_ans[x][y] = true;
            for(auto ans : v)
            {
                is_ans[ans.first][ans.second] = true;
            }
            v.clear();
            break;
        }
        else{
            if(!visit[nextX][nextY])
            {
                que.push(make_pair(nextX, nextY));
                v.push_back(make_pair(x, y));
            }
            else if(visit[nextX][nextY] && is_ans[nextX][nextY])
            {
                is_ans[x][y] = true;
                for(auto ans : v)
                {
                    is_ans[ans.first][ans.second] = true;
                }
                v.clear();
                break;
            }
            else{
                v.clear();
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!is_ans[i][j] && !visit[i][j])
            {
                dfs(i, j);
            }
        }
    }
    
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(is_ans[i][j])
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
