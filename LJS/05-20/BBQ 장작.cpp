#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int y; int x; int lev;
};
int N, M;
int arr[150][150];
int used[150][150];
int h, j;
int cnt;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int y, x;
	cin >> y >> x;
	queue<Node> q;
	int direct[4][2] = { -1,0,1,0,0,1,0,-1 };
	q.push({y,x,0});
	while (!q.empty()) {
		Node d = q.front();
		cnt = d.lev;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = d.y + direct[i][0];
			int nx = d.x + direct[i][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (arr[ny][nx] == 1) continue;
			if (used[ny][nx] == 1) continue;
			used[ny][nx] = 1;
			q.push({ ny,nx,d.lev + 1 });
		}
	}
	cout << cnt;
	return 0;
}