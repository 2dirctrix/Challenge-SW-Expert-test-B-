#include <iostream>
#include <string>
using namespace std;
int map[7][7];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int flag = 0;
void bfs(int sy, int sx) {
	int g;
	if (map[sy][sx] == 1) {
		g = 3;
	}
	if (map[sy][sx] == 2) {
		g = 4;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < g; j++) {
			int ny = sy + dy[i] * j;
			int nx = sx + dx[i] * j;
			if (ny < 0 || ny >= 7 || nx < 0 || nx >= 7) continue;
			if (g == 3 && map[ny][nx] == 1) {
				flag = 1;
				return;
			}
			if (g == 4 && map[ny][nx] == 2) {
				flag = 1;
				return;
			}
		}
	}
	
}
int main() {
	string line;
	for(int i = 0; i < 7; i++) {
		cin >> line;
		for (int j = 0; j < 7; j++) {
			map[i][j] = line[j] - '0';
		}
	}
	for(int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (map[i][j] !=0) {
				bfs(i, j);
			}
			if (flag == 1)break;
		}
		if (flag == 1)break;
	}
	if (flag == 1) {
		cout << "fail";
	} else {
		cout << "pass";
	}
	return 0;
}