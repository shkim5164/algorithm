#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m, x, y, k, input;
int map[20][20] = {0, };
vector<int> orders;
int zo[4][3]= {{0,2,0},
               {4,1,3},
               {0,5,0},
               {0,6,0}};
int num[6] = {0,0,0,0,0,0};

void gum(){
    int bottom = num[zo[3][1]];
    int top = num[zo[1][1]];
    if(map[x][y] == 0){
        map[x][y] = bottom;
    }
    else{
        num[zo[3][1]] = map[x][y];
        map[x][y] = 0;
    }
    cout << top << endl;
}

void gool(int b){
        switch(b){
            case 1: //동
                if(y+1 < m){
                    y += 1;
                    int temp = zo[3][1];
                    zo[3][1] = zo[1][2];
                    zo[1][2] = zo[1][1];
                    zo[1][1] = zo[1][0];
                    zo[1][0] = temp;
                    gum();
                    break;
                }else{
                    return;
                }
            case 2: //서
                if(y-1 >= 0){
                    y -= 1;
                    int temp = zo[3][1];
                    zo[3][1] = zo[1][0];
                    zo[1][0] = zo[1][1];
                    zo[1][1] = zo[1][2];
                    zo[1][2] = temp;
                    gum();
                    break;
                }else{
                    return;
                }
            case 3: // 북
                if(x-1 >= 0){
                    x -= 1;
                    int temp = zo[0][1];
                    zo[0][1] = zo[1][1];
                    zo[1][1] = zo[2][1];
                    zo[2][1] = zo[3][1];
                    zo[3][1] = temp;
                    gum();
                    break;
                }else{
                    return;
                }
            case 4:
                if(x+1 < n){
                    x += 1;
                    int temp = zo[3][1];
                    zo[3][1] = zo[2][1];
                    zo[2][1] = zo[1][1];
                    zo[1][1] = zo[0][1];
                    zo[0][1] = temp;
                    gum();
                    break;
                }else{
                    return;
                }
        }
}


int main(){

    cin >> n >> m >> x >> y >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    map[x][y] = 0;

    for(int i = 0; i < k; i++){
        cin >> input;
        orders.push_back(input);
    }

    for(int i = 0; i < k; i++){
        gool(orders[i]);
    }


    return 0;
}