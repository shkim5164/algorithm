#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int N;
int gear[5][8];

int calculate() {
	int res = 0;

	if (gear[1][0]) res += 1;
	if (gear[2][0]) res += 2;
	if (gear[3][0]) res += 4;
	if (gear[4][0]) res += 8;

	return res;
}

void rotate(int gearNum, int dir) {
	int tmp;
	if (dir == 1) {
		tmp = gear[gearNum][7];
		for (int i = 6; i >= 0; i--) {
			gear[gearNum][i + 1] = gear[gearNum][i];
		}
		gear[gearNum][0] = tmp;
	}
	else {
		tmp = gear[gearNum][0];
		for (int i = 1; i < 8; i++) {
			gear[gearNum][i - 1] = gear[gearNum][i];
		}
		gear[gearNum][7] = tmp;
	}
}

void algorithm(int gearNum, int dir) {
	switch (gearNum) {
	case 1:
		if (gear[1][2] ^ gear[2][6]) {
			if (gear[2][2] ^ gear[3][6]) {
				if (gear[3][2] ^ gear[4][6]) {
					rotate(4, -dir);
				}
				rotate(3, dir);
			}
			rotate(2, -dir);
		}
		rotate(1, dir);
		break;
	case 2:
		if (gear[2][6] ^ gear[1][2]) {
			rotate(1, -dir);
		}

		if (gear[2][2] ^ gear[3][6]) {
			if (gear[3][2] ^ gear[4][6]) {
				rotate(4, dir);
			}
			rotate(3, -dir);
		}
		rotate(2, dir);
		break;
	case 3:
		if (gear[3][2] ^ gear[4][6]) {
			rotate(4, -dir);
		}

		if (gear[3][6] ^ gear[2][2]) {
			if (gear[2][6] ^ gear[1][2]) {
				rotate(1, dir);
			}
			rotate(2, -dir);
		}
		rotate(3, dir);
		break;
	case 4:
		if (gear[4][6] ^ gear[3][2]) {
			if (gear[3][6] ^ gear[2][2]) {
				if (gear[2][6] ^ gear[1][2]) {
					rotate(1, -dir);
				}
				rotate(2, dir);
			}
			rotate(3, -dir);
		}
		rotate(4, dir);
		break;
	default:
		printf("algorithm: gear num error\n");
		break;
	}
}

int main() {
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &gear[i][j]);
		}
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		int gearNum, dir;
		cin >> gearNum >> dir;

		algorithm(gearNum, dir);
	}

	cout << calculate() << '\n';

	return 0;
}