#include<iostream>
#include<cstring>
using namespace std;

int one[8],two[8],three[8],four[8];
int one_top = 0, two_top = 0, three_top = 0, four_top = 0;
int one_right, two_left, two_right, three_left, three_right, four_left, ans;
int visited[5];

void init(){
    one_right = one_top + 2;
    two_left = two_top - 2; two_right = two_top + 2;
    three_left = three_top - 2; three_right = three_top + 2;
    four_left = four_top - 2;
    if(one_right == 8) one_right = 0; if(one_right == 9) one_right = 1;
    if(two_right == 8) two_right = 0; if(two_right == 9) two_right = 1;
    if(three_right == 8) three_right = 0; if(three_right == 9) three_right = 1;
    if(two_left == -2) two_left = 6; if(two_left == -1) two_left = 7;
    if(three_left == -2) three_left = 6; if(three_left == -1) three_left = 7;
    if(four_left == -2) four_left = 6; if(four_left == -1) four_left = 7;
}

void rotate_wheel(int n, int d){
    if(n == 1){
        visited[1] = 1;
        bool flag = false;
        if(one[one_right] != two[two_left]) {flag = true;}
        if(d == 1){
            one_top -= 1;
            if(one_top == -1) one_top = 7;
            if(flag && !visited[2]) rotate_wheel(2,-1);
        }else{
            one_top += 1;
            if(one_top == 8) one_top = 0;
            if(flag && !visited[2]) rotate_wheel(2,1);
        }
    }else if(n == 2){
        visited[2] = 1;
        bool flag1 = false;
        bool flag2 = false;
        if(one[one_right] != two[two_left]) {flag1 = true;}
        if(two[two_right] != three[three_left]) {flag2 = true;}
        if(d == 1){
            two_top -= 1;
            if(two_top == -1) two_top = 7;
            if(flag1 && !visited[1]) rotate_wheel(1,-1);
            if(flag2 && !visited[3]) rotate_wheel(3,-1);
        }else{
            two_top += 1;
            if(two_top == 8) two_top = 0;
            if(flag1 && !visited[1]) rotate_wheel(1,1);
            if(flag2 && !visited[3]) rotate_wheel(3,1);
        }
    }else if(n == 3){
        visited[3] = 1;
        bool flag1 = false;
        bool flag2 = false;
        if(two[two_right] != three[three_left]) {flag1 = true;}
        if(three[three_right] != four[four_left]) {flag2 = true;}
        if(d == 1){
            three_top -= 1;
            if(three_top == -1) three_top = 7;
            if(flag1 && !visited[2]) rotate_wheel(2,-1);
            if(flag2 && !visited[4]) rotate_wheel(4,-1);
        }else{
            three_top += 1;
            if(three_top == 8) three_top = 0;
            if(flag1 && !visited[2]) rotate_wheel(2,1);
            if(flag2 && !visited[4]) rotate_wheel(4,1);
        }
    }else if(n == 4){
        visited[4] = 1;
        bool flag = false;
        if(three[three_right] != four[four_left]) {flag = true;}
        if(d == 1){
            four_top -= 1;
            if(four_top == -1) four_top = 7;
            if(flag && !visited[3]) rotate_wheel(3,-1);
        }else{
            four_top += 1;
            if(four_top == 8) four_top = 0;
            if(flag && !visited[3]) rotate_wheel(3,1);
        }
    }
}

int main()
{
    for(int i=0; i<8; i++){
        scanf("%1d", &one[i]);
    }
    for(int i=0; i<8; i++){
        scanf("%1d", &two[i]);
    }
    for(int i=0; i<8; i++){
        scanf("%1d", &three[i]);
    }
    for(int i=0; i<8; i++){
        scanf("%1d", &four[i]);
    }
    int k,num,direction;
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>num>>direction;
        init();
        rotate_wheel(num, direction);
        memset(visited, 0, sizeof(visited));
    }
    if(one[one_top] == 1) ans += 1;
    if(two[two_top] == 1) ans += 2;
    if(three[three_top] == 1) ans += 4;
    if(four[four_top] == 1) ans += 8;
    cout<<ans;
    return 0;
}
