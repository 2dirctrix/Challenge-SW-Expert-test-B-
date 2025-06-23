#include<iostream>
#include<queue>
using namespace std;

char MAP[8][10];
struct Node {
	int y, x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

queue<Node>start_qu;
void getStartPoint(int y, int x) {
	int visited[8][9] = { 0 };
	queue<Node> qu;
	qu.push({ y,x });
	visited[y][x] = 1;

	while (!qu.empty()) {
		Node now = qu.front(); qu.pop();
		start_qu.push({ now.y ,now.x });
		for (int t = 0; t < 4; t++) {
			int ny = now.y + dy[t];
			int nx = now.x + dx[t];
			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9) continue;
			if (MAP[ny][nx] != '#') continue;
			if (visited[ny][nx] == 1) continue;
			visited[ny][nx] = 1;
			qu.push({ ny,nx });
		}
	}
}

int findLand() {
	int visited[8][9] = { 0 };
	int dist[8][9] = { 0 }; // 거리 기록
	// 시작지점 처리
	queue<Node> qu;
	while (!start_qu.empty()) {
		Node a = start_qu.front(); start_qu.pop();
		qu.push(a);
		visited[a.y][a.x] = 1;
	}
	// BFS
	while (!qu.empty()) {
		Node now = qu.front(); qu.pop();
		if (dist[now.y][now.x] != 0 && MAP[now.y][now.x] == '#') return dist[now.y][now.x] - 1;
		for (int t = 0; t < 4; t++) {
			int ny = now.y + dy[t];
			int nx = now.x + dx[t];
			if (ny < 0 || nx < 0 || ny >= 8 || nx >= 9) continue;
			if (visited[ny][nx] == 1) continue;
			visited[ny][nx] = 1;
			dist[ny][nx] = dist[now.y][now.x] + 1;
			qu.push({ ny,nx });
		}
	}
	return 21e8;
}
int main()
{
	for (int y = 0; y < 8; y++) {
		cin >> MAP[y];
	}

	// 한사람 찾기
	int flag = 0;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 9; x++) {
			if (MAP[y][x] == '#') {
				getStartPoint(y, x);
				flag = 1;
				break;
			}
		}
		if (flag == 1)break;
	}

	// 가장 가까운 땅 찾기
	int ans = findLand();
	cout << ans;

	return 0;
}