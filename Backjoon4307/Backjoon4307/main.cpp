#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v;
    for(int k=0; k<n; k++)
    {
        int length, ant;
        int minAns = 0;
        int maxAns = 0;
        scanf("%d %d", &length, &ant);
        for(int i=0; i<ant; i++)
        {
            int num;
            scanf("%d", &num);
            v.push_back(num);
            int value1, value2;
            if(v[i] <= length/2)
            {
                value1 = v[i] - 0;
                value2 = length - v[i];
            }else{
                value1 = length - v[i];
                value2 = v[i] - 0;
            }
            if(num == 0)
            {
                value1 = 0;
                value2 = 0;
            }
            minAns = max(minAns, value1);
            maxAns = max(maxAns, value2);
        }
        v.clear();
        printf("%d %d\n",minAns, maxAns);
    }
    return 0;
}
