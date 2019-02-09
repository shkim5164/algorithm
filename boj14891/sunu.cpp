#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int arr[4][8];
int n, a, b;

void turn(int t, int c){
	if(c < 0){
		int temp = arr[t][0];
		for(int i = 1; i < 8; i++){
			arr[t][i-1] = arr[t][i];
		}
		arr[t][7] = temp;
	}
	else{
		int temp = arr[t][7];
		for(int i = 6; i >= 0; i++){
			arr[t][i+1] = arr[t][i];
		}
		arr[t][0] = temp;
	}
}

void spin(int t, int c){
	swith(t){
		case 1:
		case 2:
			if(arr[0][6]){

			}
			if(arr[1][2] != arr[2][6]){
				if(arr[2][6] != arr[3][2]){
					turn()
				}
				turn(1, c);
			}
		case 3:
		case 4:
	}

}

int main(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 8; j++){
			scanf("%1d", &arr[i][j]);
		}
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
	}
	
	


	return 0;
}