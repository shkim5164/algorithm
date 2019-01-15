#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int arr[20][20];
int ck [20];
vector<int> team1;
vector<int> team2;
int res;

int subAbility(){
	int ability1;
	int ability2;
	for(int i=0; i<(N/2)-1; i++){
		for(int j=0; j<N/2; j++){
			ability1 += arr[team1.at(i)][team1.at(j)];
			ability1 += arr[team1.at(j)][team1.at(j)];
			ability2 += arr[team2.at(i)][team2.at(i)];
			ability2 += arr[team2.at(j)][team2.at(j)];
		}
	}

	return abs(ability1 - ability2);
}

void putRest(){
	for(int i=0; i<N; i++){
		if (ck[i] == true) continue;
		team2.push_back(i);
	}
}

void combination(int num){
	ch[num] = true;
	team1.push_back(num);

	if(team1.size() == N/2){
		vector<int> newTeam;
		putRest();
		res = min(res, subAbility());
		
		team2 = newTeam;
		return;
	}

	for(int i = num + 1; i <N; i++){
		if(ck[i] == true) continue;
		combination(i);
		team1.pop_back();
		ck[i] = false;
	}
}

int main(){
	res = 10000;
	cin >> N;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> arr[i][j];
		}
	}

	for(itn i=0; i<N; i++){
		combination(i);
	}

	cout << res << '\n';
	return 0;
}

