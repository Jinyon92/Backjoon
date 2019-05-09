#include<iostream>
#include<vector>
using namespace std;

int arr[100001];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> game(m+1, 0);
    vector<int> store(n);
    for(int i=1; i<=n; i++)
    {
        int num;
        cin>>num;
        game[num]++;
        store[i] = num;
    }
    for(int i=1; i<=m; i++)
    {
        if(game[i] == 1)
            game[i] = 0;
    }
    int idx = 0;
    for(int i=0; i<q*2; i++)
    {
        int start;
        bool isInput = true;
        cin>>start;
        int j=0;
        while(arr[j])
        {
            if(arr[j] == start)
            {
                isInput = false;
                break;
            }
            j++;
        }
        if(isInput)
        {
            arr[idx] = start;
            idx++;
        }
    }
    vector<int> ans(m+1);
    for(int i=0; i<n; i++)
    {
        int point = arr[i];
        game[store[point]] --;
        if(game[store[point]] == 0)
        {
            ans[store[point]] = i;
        }
        if(game[store[point]] == -1)
        {
            ans[store[point]] = 0;
        }
    }
    for(int i=1; i<=m; i++)
    {
        if(game[i] > 0)
        {
            ans[i] = -1;
        }
    }
    for(int i=1; i<=m; i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}
