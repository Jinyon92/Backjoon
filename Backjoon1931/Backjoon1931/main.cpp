#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< pair<int, int> >v;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.second != b.second)
    {
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(),v.end(), cmp);
    vector< pair<int, int> > ans;
    int begin = -1;
    for(auto now : v)
    {
        if(now.first >= begin)
        {
            ans.push_back(now);
            begin = now.second;
        }
    }
    cout<<ans.size()<<endl;
    for (auto x: ans)
        cout << "(" << x.first << "," << x.second << ") ";
    cout << endl;
    return 0;
}
