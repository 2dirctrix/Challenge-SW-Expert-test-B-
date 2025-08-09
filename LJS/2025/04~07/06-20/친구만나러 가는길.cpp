#include <iostream>
#include <queue>
using namespace std;
struct Node
{
	int y, x,v;
};
char map[20][20];
int n, m;
int cnt = 0;
void bfs(int sy, int sx, int ey, int ex) {
	int direct[2][4] = { 0,1,0,-1,-1,0,1,0 };
	int visited[20][20] = { 0 };
	visited[sy][sx] = 1;
	queue<Node> q;
	q.push({ sy, sx,0 });
	while (!q.empty()) {
		int y, x,v;
		y = q.front().y;
		x = q.front().x;
		v = q.front().v;
		q.pop();
		if (y == ey && x == ex) {
			cnt += v;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + direct[0][i];
			int nx = x + direct[1][i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (map[ny][nx] == 'x' || visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx,v+1 });
		}
	}
}
	int main() {
	cin >> n >> m;
	int sy, sx;
	int cx, cy;
	int dx, dy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				sy = i;
				sx = j;
			}
			if (map[i][j] == 'C') {
				cx = j;
				cy = i;
			}
			if (map[i][j] == 'D') {
				dx = j;
				dy = i;
			}
		}
	}
	bfs(sy, sx, cy, cx);
	bfs(cy, cx, dy, dx);
	cout << cnt;
	return 0;
}