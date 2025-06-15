#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};
queue<Node> q;
int map[300][300];
int used[300][300];
int N, M;
int direct[4][2] = {1,0,-1,0,0,1,0,-1};
void bfs(int y, int x) {
	q.push({ y,x });
	used[y][x] = 1;
	while (!q.empty()) {
		Node n = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = n.y + direct[i][0];
			int nx = n.x + direct[i][1];
			if (nx < 0 || ny < 0 || ny >= N || nx >= M)continue;
			if (map[ny][nx] == 0)continue;
			if (used[ny][nx] == 1)continue;
			used[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	cin >> N >> M;
	int cnt=0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin>>map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && used[i][j]==0) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}