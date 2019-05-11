#include<iostream>
#include<vector>
using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    int ans = (a.first*b.second)+(b.first*c.second)+(c.first*a.second);
    ans -= (b.first*a.second)+(c.first*b.second)+(a.first*c.second);
    if(ans > 0) return 1;
    else if(ans==0) return 0;
    else return -1;
}
int isIntersect(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
    int ab = ccw(a, b, c)*ccw(a, b, d);
    int cd = ccw(c, d, a)*ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b)swap(a, b);
        if (c > d)swap(c, d);
        return c <= b&&a <= d;
    }
    if(ab==0 || cd == 0){
        return 0;
    }
    return ab <= 0 && cd <= 0;
}

int main()
{
    vector< pair<int, int> > v;
    for(int i=0; i<4; i++){
        int start, end;
        cin>>start>>end;
        v.push_back(make_pair(start, end));
    }
    cout<<isIntersect(v[0], v[1], v[2], v[3]);
    return 0;
}
