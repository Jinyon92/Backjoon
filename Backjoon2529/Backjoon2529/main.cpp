#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n;
char sign[10];
int visit[10];
vector<string> ans;

void dfs(int start, int cnt, string s)
{
    if(cnt == n)
    {
        ans.push_back(s);
        return;
    }
    else{
        for(int i=0; i<=9; i++)
        {
            if(!visit[i])
            {
                if(sign[cnt] == '<')
                {
                    if(start >= i)
                        continue;
                }else{
                    if(start <= i)
                        continue;
                }
                visit[i] = 1;
                s = s + char(48+i);
                dfs(i, cnt+1, s);
                visit[i] = 0;
                s.erase(cnt+1,1);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        cin>>sign[i];
    }
    string str = "";
    for(int i=0; i<=9; i++)
    {
        visit[i] = 1;
        str = char(48+i);
        dfs(i, 0, str);
        visit[i] = 0;
    }
    int size = ans.size();
    cout<<ans[size-1]<<"\n"<<ans[0];
    return 0;
}
