#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n,l,r,c;
int arr[50][50] = {0, };
int check[50][50] = {0, };
int cnt = 1;
int chai;

int up(int i, int j){
    int res;
    res = abs(arr[i][j] - arr[i-1][j]);
    return res;
}
int down(int i, int j){
    int res;
    res = abs(arr[i][j] - arr[i+1][j]);
    return res;
}
int right(int i, int j){
    int res;
    res = abs(arr[i][j] - arr[i][j+1]);
    return res;
}
int left(int i, int j){
    int res;
    res = abs(arr[i][j] - arr[i][j-1]);
    return res;
}

int checking(int a, int b, int k){
    if(a <= k && b >= k){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    scanf("%d %d %d", &n, &l, &r);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &c);
            arr[i][j] = c;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == n){
                if(j == n){
                    continue;
                }
                else{
                    int count = 0;
                    if(checking(l, r, right(i, j))){
                        count += 1;
                    }
                    if(count > 0){
                        if(check[i][j] != 0){
                            check[i][j+1] = check[i][j];
                        }
                        else{
                            check[i][j] = cnt;
                            check[i][j+1] = cnt;
                            cnt += 1;
                        }
                    }
                }
            }
            else if(j == n){
                int count = 0;
                if(checking(l, r, down(i, j))){
                    count += 1;
                }
                if(count > 0){
                    if(check[i][j] != 0){
                        check[i+1][j] = check[i][j];
                    }
                    else{
                        check[i][j] = cnt;
                        check[i+1][j] = cnt;
                        cnt += 1;
                    }
                }
            }
            else{
                int count = 0;
                if(checking(l, r, down(i, j))){
                    count += 1;
                }
                if(count == 1){
                    if(check[i][j] != 0){
                        check[i+1][j] = check[i][j];
                    }
                    else{
                        check[i][j] = cnt;
                        check[i+1][j] = cnt;
                        cnt += 1;
                    }
                }
                if(checking(l, r, right(i, j))){
                    count += 1;
                }
                if(count == 1 || count == 2){
                    if(check[i][j] != 0){
                        check[i][j+1] = check[i][j];
                    }
                    else{
                        check[i][j] = cnt;
                        check[i][j+1] = cnt;
                        cnt += 1;
                    }
                }
                
            }
            
        }
    }

    printf("%d", cnt-1);



    return 0;
}