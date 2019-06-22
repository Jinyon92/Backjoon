#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 100002
using namespace std;

struct INFO {
    int x,y;
    int p,q;
    bool jewel;
    int index;
    bool answer;
    INFO(int x1 = 0, int y1 = 0, bool j = false, int a = 999999) : x(x1), y(y1), p(1), q(0), jewel(j), index(a) {}
};

bool cmp(const INFO &A, const INFO &B){
    if(1LL * A.q * B.p != 1LL * A.p*B.q)
        return 1LL * A.q * B.p < 1LL * A.p*B.q;
    if(A.y != B.y)
        return A.y < B.y;
    
    return A.x < B.x;
}

bool comp(const INFO &A, const INFO &B){
    return A.index < B.index;
}
long long ccw(const INFO &A, const INFO &B, const INFO &C) {
    return 1LL * (A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y);
}
INFO p[MAX];
INFO jewel[MAX];
INFO camera[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        jewel[i] = INFO(x,y);
    }
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        p[i] = INFO(x,y);
    }
    sort(p, p+m, cmp);
    for(int i=1; i<m; i++){
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }
    sort(p+1, p+m, cmp);
    stack<int> s;
    s.push(0);
    s.push(1);
    
    int next = 2;
    while(next < m){
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
    int idx = 0;
    while(!s.empty()){
        int now = s.top();
        s.pop();
        camera[idx] = INFO(p[now].x,p[now].y);
        idx++;
    }
    int j_idx = 0;
    for(int i=idx; i<idx+n; i++){
        camera[i] = INFO(jewel[j_idx].x,jewel[j_idx].y,true,j_idx);
        j_idx++;
    }
    sort(camera, camera+idx+n, cmp);
    int start_idx = 0;
    for(int i=0; i<idx+n; i++){
        if(camera[i].jewel){
            start_idx++;
            camera[i].answer = false;
        }else{
            break;
        }
    }
    for(int i=start_idx+1; i<idx+n; i++){
        camera[i].p = camera[i].x - camera[start_idx].x;
        camera[i].q = camera[i].y - camera[start_idx].y;
    }
    sort(camera+1, camera+idx+n, cmp);
    int cnt = 0;
    INFO first;
    INFO second;
    
    stack<int> jew;
    for(int i=start_idx; i<idx+n; i++){
        if(jew.empty()){
            if(!camera[i].jewel && cnt == 0){
                first.x = camera[i].x;
                first.y = camera[i].y;
                cnt = 1;
            }
            else if(!camera[i].jewel && cnt == 1){
                second.x = camera[i].x;
                second.y = camera[i].y;
                cnt = 0;
            }
            else if(camera[i].jewel){
                jew.push(i);
            }
        }
        else{
            if(camera[i].jewel){
                jew.push(i);
            }
            else if(!camera[i].jewel){
                if(cnt == 0){
                    first.x = camera[i].x;
                    first.y = camera[i].y;
                    cnt = 1;
                }
                else if(cnt == 1){
                    second.x = camera[i].x;
                    second.y = camera[i].y;
                    cnt = 0;
                }
                while(!jew.empty()){
                    int now = jew.top();
                    jew.pop();
                    if(cnt == 0){
                        if(ccw(first, second, camera[now]) > 0){
                            camera[now].answer = true;
                        }else{
                            camera[now].answer = false;
                        }
                    }else{
                        if(ccw(second, first, camera[now]) > 0){
                            camera[now].answer = true;
                        }else{
                            camera[now].answer = false;
                        }
                    }
                }
            }
        }
    }
    sort(camera, camera+idx+n, comp);
    for(int i=0; i<n; i++){
        if(camera[i].answer){
            cout<<"Y";
        }else{
            cout<<"N";
        }
    }
    return 0;
}

