#include <iostream>
#include <queue>
using namespace std;
int used[4][6];
struct Node {
	int y, x;
};
int arr[4][6];
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}
	queue<Node> q;
	q.push({0,0});
	used[0][0] = 1;
	Node n;
	int direct[4][2] = {1,0,0,1,-1,0,0,-1};
	int cnt = 0;
	while (!q.empty()) {
		n= q.front();
		q.pop();
		for (int i = 0; i < 4;i++) {
			int dy = n.y + direct[i][0];
			int dx = n.x + direct[i][1];
			if (dy < 0 || dy>=4 || dx < 0 || dx>=6)continue;
			if (arr[dy][dx] == 1) continue;
			if (used[dy][dx] == 1)continue;
			if (arr[dy][dx] == 2) cnt++;
			used[dy][dx] = 1;
			q.push({dy,dx});
		}
	}
	cout << cnt;
	return 0;
}