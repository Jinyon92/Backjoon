#include <iostream>
#include <queue>
using namespace std;

int n,k;
queue< pair<int,int> > que;
int visit[100001];

int bfs()
{
    int time = 0;
    que.push(make_pair(n, time));
    while(!que.empty())
    {
        int size = que.size();
        for(int i=0; i<size; i++)
        {
            int now = que.front().first;
            int cnt = que.front().second;
            visit[now] = 1;
            if(now == k)
            {
                return cnt;
            }
            if(now-1>=0 && visit[now-1] == 0)
            {
                que.push(make_pair(now-1,cnt+1));
            }
            if(now+1<=100000 && visit[now+1] == 0)
            {
                que.push(make_pair(now+1, cnt+1));
            }
            if(now*2<=100000 && visit[now*2] == 0)
            {
                que.push(make_pair(now*2, cnt+1));
            }
            que.pop();
        }
    }
    return 0;
}

int main() {
    int counter = 0;
    cin>>n>>k;
    int ans = bfs();
    while(!que.empty())
    {
        int a = que.front().first;
        int b = que.front().second;
        que.pop();
        if(a == k && b == ans)
        {
            counter += 1;
        }
    }
    cout<<ans<<"\n"<<counter;
    return 0;
}

