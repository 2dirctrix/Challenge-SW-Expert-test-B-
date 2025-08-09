#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int y; int x;
};

int arr[4][4];
int used[4][4];
int cnt;
int direct[5][2] = { -1,0,1,0,0,1,0,-1 };
int bfs(int y,int x) {
	queue<Node> q;
	q.push({ y,x });
	used[y][x] = 1;
	int size = 1;
	while (!q.empty()) {
		Node d = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = d.y + direct[i][0];
			int nx = d.x + direct[i][1];
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4 || arr[ny][nx] == 0) continue;
			if (used[ny][nx] == 1) continue;
			used[ny][nx] = 1;
			q.push({ ny,nx });
			size++;
		}
	}
	return size;
}
int main()
{
	int answer = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	int tmp;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j]&&used[i][j]==0) {
				tmp = bfs(i, j);
				if (tmp > answer) {
					answer = tmp;
				}
			}
		}
	}
	
	cout << answer;
	return 0;
}