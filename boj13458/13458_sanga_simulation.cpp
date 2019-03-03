#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int A[1000000];
int B; //총 감독관이 감시할 수 있는 응시자 수
int C; //부 감독관이 감시할 수 있는 응시자 수
long long int res;

int algorithm(int room) {
	int ret = 1;
	int num = A[room] - B;

	if (num <= 0) {
		return ret;
	}

	ret += num / C;

	if(num % C) {
		ret += 1;
	}

	return ret;
}

int main() {
	res = 0;
	memset(A, 0, sizeof(A));
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		res += algorithm(i);
	}

	cout << res << '\n';

	return 0;
}
