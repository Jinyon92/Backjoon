#include<iostream>
using namespace std;

bool wordcheck(string s)
{
    bool visit[26] = {false};
    for(int i=0; i<s.length(); i++)
    {
        if(visit[s[i] - 'a'])
        {
            return false;
        }else{
            visit[s[i] - 'a'] = true;
            char c = s[i];
            while(1)
            {
                i += 1;
                if(c != s[i])
                {
                    i -= 1;
                    break;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        if(wordcheck(s))
        {
            ans += 1;
        }
    }
    printf("%d", ans);
    return 0;
}
