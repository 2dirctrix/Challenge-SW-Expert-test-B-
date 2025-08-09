#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};

queue<Node> q;
int map[300][300];

int main()
{
	int n;
	int a, b, c, d;

	cin >> n;
	cin >> a >> b >> c >> d;

	map[a][b] = 1;
	map[c][d] = 1;
	q.push({ a, b });
	q.push({ c, d });

	int direct[4][2] = { -1,0, 1,0, 0,1, 0,-1 };

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int t = 0; t < 4; t++) {
			int ny = now.y + direct[t][0];
			int nx = now.x + direct[t][1];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (map[ny][nx] != 0) continue;
			map[ny][nx] = map[now.y][now.x] + 1;
			if (map[ny][nx] > 9) map[ny][nx] = 9;

			q.push({ ny, nx });
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}

	return 0;
}