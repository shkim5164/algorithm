#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int A, B, C, N;
long long int all;
vector<int> Ai;

void translate(int k, int c) {
	if (k > 0) {
		int new1 = k / c;
		all += (new1);
		if (k % c > 0) {
			all += 1;
		}
	}
	return;
}

int main() {
	cin >> N;
	all = N;
	for (int i = 0; i < N; i++) {
		cin >> A;
		Ai.push_back(A);
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		translate(Ai[i] - B, C);
	}

	cout << all;

	return 0;
}