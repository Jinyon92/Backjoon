#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
    scanf("%d", &n);
    vector<int> card(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &card[i]);
    }
    sort(card.begin(),card.end());
    scanf("%d", &m);
    vector<int> search(m);
    for(int i=0; i<m; i++)
    {
        scanf("%d", &search[i]);
    }
    vector<int> ans;
    for(int k=0; k<m; k++)
    {
        int left = 0;
        int right = n-1;
        int tmp = 0;
        int sch = search[k];
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(card[mid] == sch)
            {
                tmp = 1;
                break;
            }
            else if(card[mid] > sch)
            {
                right = mid - 1;
            }else if(card[mid] < sch)
            {
                left = mid + 1;
            }
        }
        ans.push_back(tmp);
    }
    for(int i=0; i<m; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}
