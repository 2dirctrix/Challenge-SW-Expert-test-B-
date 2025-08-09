#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int y, x;
};
int map[10][10];
int visited[10][10];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	queue<Node> q;
	q.push({ 0, 0 });
	visited[0][0] = 1;
	int flag = 0;
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx] == 1) continue;
			if (ny == n - 1 && nx == n - 1) {
				flag = 1;
				break;
			}
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
		if(flag) {
			break;
		}
	}
	if (flag) {
		cout << "가능";
	}
	else {
		cout << "불가능";
	}
}