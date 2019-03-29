#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n,k;
int visit[2][500001];
queue< pair<int, int> >que;

bool isTrue(int i)
{
    if(i<0 || i>500001)
        return false;
    else
        return true;
}

void bfs(int pos, int time)
{
    if(isTrue(pos-1) && visit[(time+1) % 2][pos-1] < 0)
    {
        visit[(time+1) % 2][pos -1] = time+1;
        que.push(make_pair(pos-1,time+1));
    }
    if(isTrue(pos+1) && visit[(time+1) % 2][pos+1] < 0)
    {
        visit[(time+1)%2][pos+1] = time+1;
        que.push(make_pair(pos+1, time+1));
    }
    if(isTrue(2*pos) && visit[(time+1) % 2][pos*2] < 0)
    {
        visit[(time+1)%2][pos*2] = time+1;
        que.push(make_pair(pos*2, time+1));
    }
}

int main()
{
    cin>>n>>k;
    for(int i=0; i<500001; i++)
    {
        visit[0][i] = -1;
        visit[1][i] = -1;
    }
    que.push(make_pair(n, 0));
    visit[0][n] = 0;
    int qsize = 0;
    while(!que.empty())
    {
        qsize = que.size();
        for(int i=0; i<qsize; i++)
        {
            auto now = que.front();
            que.pop();
            bfs(now.first, now.second);
        }
    }
    int pos = k;
    int cnt = 0;
    int ans = 500001;
    while(pos <= 500000)
    {
        if(visit[cnt % 2][pos] > -1 && visit[cnt % 2][pos] <= cnt)
        {
            ans = min(ans, cnt);
        }
        cnt += 1;
        pos += cnt;
    }
    if(ans == 500001)
        cout<< -1;
    else
        cout<< ans;
    return 0;
}
