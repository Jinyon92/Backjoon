#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void hanoi(int cnt, int from, int temp, int to){
    if(cnt == 0) return;

    hanoi(cnt-1, from, to, temp);
    cout<<from<<" "<<to<<"\n";
    hanoi(cnt-1, temp, from, to);
}

string bigNumAdd(string num1, string num2){
    long long sum = 0;
    string result;

    while(!num1.empty() || !num2.empty() || sum){
        if(!num1.empty()){
            sum += num1.back() - '0';
            num1.pop_back();
        }

        if(!num2.empty()){
            sum += num2.back() - '0';
            num2.pop_back();
        }

        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string subOne(string num){
    int back = num.back() - '0';
    num.pop_back();
    back -= 1;
    num.push_back(back + '0');
    return num;
}

int main()
{
    int n;
    cin>>n;

    if(n <= 20){
        cout<< (1<<n)-1<<"\n";
        hanoi(n,1,2,3);
    }else{
        string num = "2";
        for(int i = 1; i < n; i++){
            string temp = bigNumAdd(num, num);
            num = temp;
        }
        cout<<subOne(num) << "\n";
    }
    return 0;
}

