#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, input, oper;
vector<int> opers;
vector<int> inputs;
int big, small;
int opop[10];
int check[11] = {0};
int all = 0;

void calculator(int a, int b, int o) {
	if (o == 0) {
		return a + b;
	}
	else if (o == 1) {
		return a - b;
	}
	else if (o == 2) {
		return a * b;
	}
	else {
		return a / b;
	}
}

void dfs(int l, int index, vector<int> newarr) {
	if (check[index] == 0) {
		check[index] = 1;
		opop[index] = l;
		for (int j = index + 1; j < n; j++) {
			dfs(l, j, );
			check[j] = 0;
		}
		newarr[l] -= 1;
	}
	else{
		for (int i = 0; i < n; i++) {
			calculator(all, inputs[i], inputs[i + 1]);
		}
		return ;
	}
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		inputs.push_back(input);
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper;
		opers[i] = oper;
	}

	vector<int> newone = opers;

	for (int i = 0; i < 4; i++) {
		if (newone[i] == 0) {
			continue;
		}
		else{
			for (int j = 0; j < n-1; j++) {
				dfs(i, j, newone);
			}
		}
	}

	

	return 0;
}