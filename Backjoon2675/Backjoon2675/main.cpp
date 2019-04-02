#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        string s;
        int length;
        scanf("%d", &length);
        cin>>s;
        for(int i=0; i<s.length(); i++)
        {
            for(int j=0; j<length; j++)
            {
                cout<<s[i];
            }
        }
        cout<<"\n";
    }
    return 0;
}
