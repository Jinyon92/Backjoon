#include<iostream>
using namespace std;

int arr[25];

void Print_Paren(int arr_size){
    for(int i=0; i<arr_size; i++){
        if(arr[i] == 1){
            cout<< "(";
        }else
            cout<< ")";
    }cout<<endl;
}

void Paren(int arr_size, int open, int close){
    if(open == 0 && close == 0){
        Print_Paren(arr_size);
        return;
    }
    if(open > 0){
        arr[arr_size] = 1;
        Paren(arr_size+1, open -1, close + 1);
    }
    if(close > 0){
        arr[arr_size] = 2;
        Paren(arr_size + 1, open, close - 1);
    }
}

int main()
{
    int n;
    cin>>n;
    Paren(0,n,0);
    return 0;
}
