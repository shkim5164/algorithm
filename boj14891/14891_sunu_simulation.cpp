#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int arr[4][8];
int n, a, b;
int topni[100][2];

void turn(int t, int c) {
	if (c < 0) {
		int temp = arr[t][0];
		for (int i = 1; i < 8; i++) {
			arr[t][i - 1] = arr[t][i];
		}
		arr[t][7] = temp;
	}
	else {
		int temp = arr[t][7];
		for (int i = 6; i >= 0; i--) {
			arr[t][i + 1] = arr[t][i];
		}
		arr[t][0] = temp;
	}
}

void spin(int t, int c) {
	switch (t) {
	case 1:
		if (arr[0][2] != arr[1][6]) {
			if (arr[1][2] != arr[2][6]) {
				if (arr[2][2] != arr[3][6]) {
					turn(3, -1 * c);
				}
				turn(2, c);
			}
			turn(1, -1 * c);
		}
		turn(0, c);
		break;
	case 2:
		if (arr[0][2] != arr[1][6]) {
			turn(0, -1 * c);
		}
		if (arr[1][2] != arr[2][6]) {
			if (arr[2][2] != arr[3][6]) {
				turn(3, c);
			}
			turn(2, -1 * c);
		}
		turn(1, c);
		break;
	case 3:
		if (arr[2][6] != arr[1][2]) {
			if (arr[1][6] != arr[0][2]) {
				turn(0, c);
			}
			turn(1, -1 * c);
		}
		if (arr[2][2] != arr[3][6]) {
			turn(3, -1 * c);
		}
		turn(2, c);
		break;
	case 4:
		if (arr[2][2] != arr[3][6]) {
			if (arr[1][2] != arr[2][6]) {
				if (arr[1][6] != arr[0][2]) {
					turn(0, -1 * c);
				}
				turn(1, c);
			}
			turn(2, -1 * c);
		}
		turn(3, c);
		break;
	}

}

int sum() {
	int answer = 0;
	if (arr[0][0] == 1) {
		answer += 1;
	}
	if (arr[1][0] == 1) {
		answer += 2;
	}
	if (arr[2][0] == 1) {
		answer += 4;
	}
	if (arr[3][0] == 1) {
		answer += 8;
	}
	return answer;
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		topni[i][0] = a;
		topni[i][1] = b;
	}
	for (int i = 0; i < n; i++) {
		spin(topni[i][0], topni[i][1]);
	}

	cout << sum();
	return 0;
}