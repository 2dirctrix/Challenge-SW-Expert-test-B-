#include<iostream>
using namespace std;

int main() {
	char arr[4][4] = { '_' };
	for (int i = 0; i < 4; i++) {
		fill(arr[i], arr[i] + 4, '_');
	}
	int x, y;
	int dy[8] = { 0,0,-1,1,1,1,-1,-1 };
	int dx[8] = { 1,-1,0,0,-1,1,-1,1 };
	int ny, nx;
	for (int i = 0; i < 3; i++) {
		cin >> y >> x;
		arr[y][x] = '#';
		for (int j = 0; j < 8; j++) {
			ny = y + dy[j];
			nx = x + dx[j];
			if (0 <= ny && ny < 4 && 0 <= nx && nx < 4) {
				if (arr[ny][nx] == '#')continue;
				arr[ny][nx] = '@';
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (char item : arr[i]) {
			cout << item;
		}
		cout << endl;
	}
	return 0;
}