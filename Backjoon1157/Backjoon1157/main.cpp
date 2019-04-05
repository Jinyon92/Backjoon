#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    int arr[26] = {0};
    int max = 0;
    char answer;
    getline(cin, s);
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] >= 65 && s[i] <= 90)
        {
            arr[s[i] - 65] += 1;
        }
        else if(s[i] >= 97 && s[i] <= 122)
        {
            arr[s[i] - 97] += 1;
        }
    }
    for(int i=0; i<26; i++)
    {
        if(max < arr[i])
        {
            answer = i + 65;
            max = arr[i];
        }
        else if(max == arr[i])
        {
            answer = '?';
        }
    }
    printf("%c", answer);
    return 0;
}
