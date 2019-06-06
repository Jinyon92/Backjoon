#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
#define MAX 100002
using namespace std;
typedef long long ll;

struct INFO {
    int x,y;
    int p,q;
    INFO(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}
};
bool comp(const INFO &A, const INFO &B){
    if(1LL * A.q * B.p != 1LL * A.p*B.q)
        return 1LL * A.q * B.p < 1LL * A.p*B.q;
    if(A.y != B.y)
        return A.y < B.y;
    
    return A.x < B.x;
}
ll ccw(const INFO &A, const INFO &B, const INFO &C) {
    return 1LL * (A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
}
INFO p[MAX];

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        p[i] = INFO(x,y);
    }
    sort(p, p+n, comp);
    for(int i=1; i<n; i++){
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }
    sort(p+1, p+n, comp);
    for(int i=0; i<n; i++){
        cout<<p[i].x<<","<<p[i].y<<" ";
    }
    stack<int> s;
    s.push(0);
    s.push(1);
    
    int next = 2;
    while(next < n){
        while(s.size() >= 2){
            int first, second;
            second = s.top();
            s.pop();
            first = s.top();
            
            if (ccw(p[first], p[second], p[next]) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(next++);
    }
    cout<<s.size();
    return 0;
}
