#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;
int r, c;
int dice[4][3];
int map[20][20];
int d_r[5] = {0, 0, 0, -1, 1};
int d_c[5] = {0, 1, -1, 0, 0};
vector<int> res;

int range(int r, int c) {
   if (r >= 0 && r < N && c >= 0 && c < M) return 1;
   return 0;
}

void spin(int dir) {
   int tmp;
   switch (dir) {
   case 1:
      tmp = dice[1][0];
      dice[1][0] = dice[3][1];
      dice[3][1] = dice[1][2];
      dice[1][2] = dice[1][1];
      dice[1][1] = tmp;
      break;
   case 2:
      tmp = dice[1][0];
      dice[1][0] = dice[1][1];
      dice[1][1] = dice[1][2];
      dice[1][2] = dice[3][1];
      dice[3][1] = tmp;
      break;
   case 3:
      tmp = dice[0][1];
      dice[0][1] = dice[1][1];
      dice[1][1] = dice[2][1];
      dice[2][1] = dice[3][1];
      dice[3][1] = tmp;
      break;
   case 4:
      tmp = dice[3][1];
      dice[3][1] = dice[2][1];
      dice[2][1] = dice[1][1];
      dice[1][1] = dice[0][1];
      dice[0][1] = tmp;
      break;
   }
}

void algorithm(int dir) {
   int newR = r + d_r[dir];
   int newC = c + d_c[dir];

   if (!range(newR, newC)) {
      return; 
   }

   spin(dir);

   if (map[newR][newC]) { //0이 아닌 경우
      dice[3][1] = map[newR][newC];
      map[newR][newC] = 0;
   }
   else { // 0인 경우
      map[newR][newC] = dice[3][1];
   }

   res.push_back(dice[1][1]);
   r = newR;
   c = newC;
}

int main() {
   cin >> N >> M >> r >> c >> K;

   memset(dice, 0, sizeof(dice));

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         cin >> map[i][j];
      }

   }
   for (int i = 0; i < K; i++) {
      int dir;
      cin >> dir;
      algorithm(dir);
   }

   for (int i = 0; i < res.size(); i++) {
      cout << res.at(i) << '\n';
   }

   return 0;
}
