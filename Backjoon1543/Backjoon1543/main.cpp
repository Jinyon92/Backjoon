#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    char doc[2501];
    char find[51];
    cin>>doc>>find;
    int cnt = 0;
    char *pos;
    pos = doc;
    while(strstr(pos, find) != NULL){
        pos = strstr(pos, find);
        pos = pos + strlen(find);
        cnt++;
    }
    cout<<cnt;
    return 0;
}
