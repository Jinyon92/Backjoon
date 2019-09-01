#include<iostream>
#include<string.h>
using namespace std;

char qube[6][9][9];

void rotate_qube(char side, char dir){
    int temp_left, temp_right, temp_back, temp_front, temp_up, temp_down;
    int temp_arr[3][3];
    if(side == 'U' && dir == '+'){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                temp_arr[y][x] = qube[0][y][x];
            }
        }
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                qube[0][y][x] = temp_arr[2-x][y];
            }
        }
        for(int i=0; i<3; i++){
            temp_left = qube[1][0][i]; temp_right = qube[3][0][i];
            temp_back = qube[2][0][i]; temp_front = qube[5][0][i];
            qube[3][0][i] = temp_back;
            qube[5][0][i] = temp_right;
            qube[1][0][i] = temp_front;
            qube[2][0][i] = temp_left;
        }
    }else if(side == 'U' && dir == '-'){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                temp_arr[y][x] = qube[0][y][x];
            }
        }
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                qube[0][y][x] = temp_arr[x][2-y];
            }
        }
        for(int i=0; i<3; i++){
            temp_left = qube[1][0][i]; temp_right = qube[3][0][i];
            temp_back = qube[2][0][i]; temp_front = qube[5][0][i];
            qube[3][0][i] = temp_front;
            qube[5][0][i] = temp_left;
            qube[1][0][i] = temp_back;
            qube[2][0][i] = temp_right;
        }
    }else if(side == 'D' && dir == '+'){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                temp_arr[y][x] = qube[4][y][x];
            }
        }
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                qube[4][y][x] = temp_arr[2-x][y];
            }
        }
        for(int i=0; i<3; i++){
            temp_left = qube[1][2][i]; temp_right = qube[3][2][i];
            temp_back = qube[2][2][i]; temp_front = qube[5][2][i];
            qube[3][2][i] = temp_front;
            qube[5][2][i] = temp_left;
            qube[1][2][i] = temp_back;
            qube[2][2][i] = temp_right;
        }
    }else if(side == 'D' && dir == '-'){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                temp_arr[y][x] = qube[4][y][x];
            }
        }
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                qube[4][y][x] = temp_arr[x][2-y];
            }
        }
        for(int i=0; i<3; i++){
            temp_left = qube[1][2][i]; temp_right = qube[3][2][i];
            temp_back = qube[2][2][i]; temp_front = qube[5][2][i];
            qube[3][2][i] = temp_back;
            qube[5][2][i] = temp_right;
            qube[1][2][i] = temp_front;
            qube[2][2][i] = temp_left;
        }
    }else if(side == 'F' && dir == '+'){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                temp_arr[y][x] = qube[5][y][x];
            }
        }
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                qube[5][y][x] = temp_arr[2-x][y];
            }
        }
        for(int i=0; i<3; i++){
            temp_up = qube[0][2][i]; temp_right = qube[3][i][0];
            temp_down = qube[4][0][2-i]; temp_left = qube[1][2-i][2];
            qube[3][i][0] = temp_up;
            qube[4][0][2-i] = temp_right;
            qube[1][2-i][2] = temp_down;
            qube[0][2][i] = temp_left;
        }
    }else if(side == 'F' && dir == '-'){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                temp_arr[y][x] = qube[5][y][x];
            }
        }
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                qube[5][y][x] = temp_arr[x][2-y];
            }
        }
        for(int i=0; i<3; i++){
            temp_up = qube[0][2][i]; temp_right = qube[3][i][0];
            temp_down = qube[4][0][2-i]; temp_left = qube[1][2-i][2];
            qube[3][i][0] = temp_down;
            qube[4][0][2-i] = temp_left;
            qube[1][2-i][2] = temp_up;
            qube[0][2][i] = temp_right;
        }
    }else if(side == 'B' && dir == '+'){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                temp_arr[y][x] = qube[2][y][x];
            }
        }
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                qube[2][y][x] = temp_arr[2-x][y];
            }
        }
        for(int i=0; i<3; i++){
            temp_up = qube[0][0][i]; temp_left = qube[1][2-i][0];
            temp_down = qube[4][2][2-i]; temp_right = qube[3][i][2];
            qube[1][2-i][0] = temp_up;
            qube[4][2][2-i] = temp_left;
            qube[3][i][2] = temp_down;
            qube[0][0][i] = temp_right;
        }
    }else if(side == 'B' && dir == '-'){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                temp_arr[y][x] = qube[2][y][x];
            }
        }
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                qube[2][y][x] = temp_arr[x][2-y];
            }
        }
        for(int i=0; i<3; i++){
            temp_up = qube[0][0][i]; temp_left = qube[1][2-i][0];
            temp_down = qube[4][2][2-i]; temp_right = qube[3][i][2];
            qube[1][2-i][0] = temp_down;
            qube[4][2][2-i] = temp_right;
            qube[3][i][2] = temp_up;
            qube[0][0][i] = temp_left;
        }
    }else if(side == 'L' && dir == '+'){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                temp_arr[y][x] = qube[1][y][x];
            }
        }
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                qube[1][y][x] = temp_arr[2-x][y];
            }
        }
        for(int i=0; i<3; i++){
            temp_down = qube[4][i][0]; temp_back = qube[2][2-i][2];
            temp_up = qube[0][i][0]; temp_front = qube[5][i][0];
            qube[4][i][0] = temp_front;
            qube[2][2-i][2] = temp_down;
            qube[0][i][0] = temp_back;
            qube[5][i][0] = temp_up;
        }
    }else if(side == 'L' && dir == '-'){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                temp_arr[y][x] = qube[1][y][x];
            }
        }
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                qube[1][y][x] = temp_arr[x][2-y];
            }
        }
        for(int i=0; i<3; i++){
            temp_down = qube[4][i][0]; temp_back = qube[2][2-i][2];
            temp_up = qube[0][i][0]; temp_front = qube[5][i][0];
            qube[4][i][0] = temp_back;
            qube[2][2-i][2] = temp_up;
            qube[0][i][0] = temp_front;
            qube[5][i][0] = temp_down;
        }
    }else if(side == 'R' && dir == '+'){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                temp_arr[y][x] = qube[3][y][x];
            }
        }
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                qube[3][y][x] = temp_arr[2-x][y];
            }
        }
        for(int i=0; i<3; i++){
            temp_front = qube[5][i][2]; temp_down = qube[4][i][2];
            temp_back = qube[2][2-i][0]; temp_up = qube[0][i][2];
            qube[4][i][2] = temp_back;
            qube[2][2-i][0] = temp_up;
            qube[5][i][2] = temp_down;
            qube[0][i][2] = temp_front;
        }
    }else if(side == 'R' && dir == '-'){
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                temp_arr[y][x] = qube[3][y][x];
            }
        }
        for(int y=0; y<3; y++){
            for(int x=0; x<3; x++){
                qube[3][y][x] = temp_arr[x][2-y];
            }
        }
        for(int i=0; i<3; i++){
            temp_front = qube[5][i][2]; temp_down = qube[4][i][2];
            temp_back = qube[2][2-i][0]; temp_up = qube[0][i][2];
            qube[4][i][2] = temp_front;
            qube[2][2-i][0] = temp_down;
            qube[5][i][2] = temp_up;
            qube[0][i][2] = temp_back;
        }
    }
}
int main()
{
    int T;
    cin>>T;
    for(int test_case = 1; test_case<=T; test_case++){
        int n;
        cin>>n;
        memset(qube[0], 'w', sizeof(qube[0]));
        memset(qube[4], 'y', sizeof(qube[4]));
        memset(qube[5], 'r', sizeof(qube[5]));
        memset(qube[2], 'o', sizeof(qube[2]));
        memset(qube[1], 'g', sizeof(qube[1]));
        memset(qube[3], 'b', sizeof(qube[3]));
        char side, dir;
        for(int i=0; i<n; i++){
            cin>>side>>dir;
            rotate_qube(side, dir);
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout<<qube[0][i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
