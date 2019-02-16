#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, input, oper;
int big = -1000000000;
int small = 1000000000;
vector<int> inputs;
vector<int> opers;

void putin(int index, int plus, int minus, int multiple, int devide, int total){
	if(index == n){
		big = max(total, big);
		small = min(total, small);
		return ;
	}
	if(plus < opers[0]){
		putin(index+1, plus+1, minus, multiple, devide, total+inputs[index]);
	}
	if(minus < opers[1]){
		putin(index+1, plus, minus+1, multiple, devide, total-inputs[index]);
	}
	if(multiple < opers[2]){
		putin(index+1, plus, minus, multiple+1, devide, total*inputs[index]);
	}
	if(devide < opers[3]){
		putin(index+1, plus, minus, multiple, devide+1, total/inputs[index]);
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
		opers.push_back(oper);
	}

	putin(1,0,0,0,0,inputs[0]);

	cout << big << "\n" << small;

	return 0;
}