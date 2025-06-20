#include <iostream>
#include <queue>
using namespace std;
struct Node
{
	int y, x;
};
int map[4][9];
int visited[4][9];
int MAX = 0;
int answer = 0;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
void bfs(int y, int x) {
	visited[y][x] = 1;
	queue<Node> q;
	int count = 1;
	int same = map[y][x];
	q.push({ y, x});
	while(!q.empty()) {
		Node now = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 9) continue;
			if (map[ny][nx] == same && visited[ny][nx] == 0) {
				visited[ny][nx] = 1;
				count++;
				q.push({ ny, nx });
			}
		}
	}
	if (count > MAX) {
		MAX = count;
		answer = same*MAX;
	}
}
int main() {
	for(int i = 0; i < 4; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] >0 && visited[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
	cout << answer << endl;
	return 0;
}