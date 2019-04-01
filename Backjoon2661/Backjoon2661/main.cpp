#include<iostream>
#include<string>
using namespace std;

int n;
bool stop = false;

bool isTrue(string str)
{
    int len = str.length();
    int loop = len/2;
    int start = len - 1;
    for(int i=1; i<=loop; i++)
    {
        if(str.substr(start-i,i) == str.substr(start, i))
        {
            return false;
        }
        start -= 1;
    }
    return true;
}

void dfs(int len, string s)
{
    if(stop)
    {
        return;
    }
    if(len == n)
    {
        stop = true;
        cout<<s<<endl;
        return;
    }
    else
    {
        for(int i=1; i<=3; i++)
        {
            if(isTrue(s+to_string(i)))
            {
                dfs(len+1, s+to_string(i));
            }
        }
    }
}

int main()
{
    cin>>n;
    dfs(1,"1");
    return 0;
}
