#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int T;
    cin>>T;
    int n,m;
    vector<int> v;
    for(int test_case = 1; test_case <=T; test_case++){
        cin>>n>>m;
        int num, idx = m; int ans = 0;
        for(int i=0; i<n; i++){
            cin>>num;
            v.push_back(num);
        }
        while(!v.empty()){
            int key = v[0]; bool flag = true;
            for(int i=1; i<v.size(); i++){
                if(key < v[i]){
                    flag = false;
                    v.erase(v.begin());
                    v.push_back(key);
                    if(idx == 0){
                        idx = v.size()-1;
                    }else{
                        idx--;
                    }
                    break;
                }
            }
            if(flag){
                ans++;
                v.erase(v.begin());
                if(idx == 0){
                    cout<<ans<<"\n";
                    break;
                }else{
                    idx--;
                }
            }
        }
        v.clear();
    }
    return 0;
}
