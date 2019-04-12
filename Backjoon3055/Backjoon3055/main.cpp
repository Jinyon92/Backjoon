#include<iostream>
#include<vector>
#include<queue>
using namespace std;

char map[51][51];
int a[4] = {1,0,-1,0};
int b[4] = {0,1,0,-1};
queue< pair<int, int> > star_q;
queue< pair<int, int> > s_q;
vector< pair<int, int> >star_v;
vector< pair<int, int> >s_v;
int r,c;
bool isSearch = false;

void star_bfs()
{
    while(!star_q.empty())
    {
        auto now_star = star_q.front();
        int star_x = now_star.first;
        int star_y = now_star.second;
        star_q.pop();
        for(int i=0; i<4; i++)
        {
            int nextX = star_x + a[i];
            int nextY = star_y + b[i];
            if(nextX < 0 || nextX >= r || nextY < 0 || nextY >= c)
            {
                continue;
            }
            if(map[nextX][nextY] == '.' || map[nextX][nextY] == 'S')
            {
                map[nextX][nextY] = '*';
                star_v.push_back(make_pair(nextX, nextY));
            }
        }
    }
}
void s_bfs(int cnt)
{
    while(!s_q.empty())
    {
        auto now_s = s_q.front();
        int s_x = now_s.first;
        int s_y = now_s.second;
        s_q.pop();
        for(int i=0; i<4; i++)
        {
            int nextX = s_x + a[i];
            int nextY = s_y + b[i];
            if(nextX < 0 || nextX >= r || nextY < 0 || nextY >= c)
            {
                continue;
            }
            if(map[nextX][nextY] == '.')
            {
                map[nextX][nextY] = 'S';
                s_v.push_back(make_pair(nextX, nextY));
            }
            else if(map[nextX][nextY] == 'D')
            {
                isSearch = true;
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>r>>c;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 'S')
            {
                s_q.push(make_pair(i, j));
            }
            else if(map[i][j] == '*')
            {
                star_q.push(make_pair(i, j));
            }
        }
    }
    int cnt = 0;
    while(1)
    {
        cnt += 1;
        star_bfs();
        for(int i=0; i<star_v.size(); i++)
        {
            star_q.push(star_v[i]);
        }
        star_v.clear();
        s_bfs(cnt);
        for(int i=0; i<s_v.size(); i++)
        {
            s_q.push(s_v[i]);
        }
        s_v.clear();
        if(isSearch){
            break;
        }
        if(cnt > 2500)
        {
            break;
        }
    }
    if(cnt > 2500)
    {
        cout<<"KAKTUS";
    }else{
        cout<<cnt;
    }
    return 0;
}
