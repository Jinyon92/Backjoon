#include<iostream>
using namespace std;

int main()
{
    int row, col;
    cin>>row>>col;
    int ans = 1;
    if(row == 1){
        ans = 1;
        cout<<ans;
        return 0;
    }
    if(row < 3 && row >= 2){
        col -= 2;
        while(col > 0 && ans < 4){
            ans++;
            col -= 2;
        }
    }else{
        if(col <= 4){
            ans = col;
        }
        else if(col <= 6 && col > 4){
            ans = 4;
        }
        else{
            col -= 6;
            ans = 4;
            while(col > 0){
                col--;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
