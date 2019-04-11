#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    
    bool *arr = new bool[b+1];
    for(int i=0; i<b+1; i++)
    {
        arr[i] = true;
    }
    
    int j;
    for(int i=2; i<b+1; i++)
    {
        if(arr[i])
        {
            if(pow(i,2) > 1000001)
            {
                break;
            }else{
                for(j = pow(i,2); j < b+1;)
                {
                    arr[j] = false;
                    j = j+i;
                }
            }
        }
    }
    if(a==1)
        a += 1;
    for(int i=a; i<b+1; i++)
    {
        if(arr[i])
        {
            printf("%d\n", i);
        }
    }
    delete []arr;
    return 0;
}
