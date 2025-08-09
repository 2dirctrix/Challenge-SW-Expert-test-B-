#include <iostream>
#include <queue>
using namespace std;
int EX, EY;
int used[4][4];
struct Node {
	int y, x;
	int value;
};

int main() {
	int arr[4][4] = { {0,0,0,0},{1,1,0,1},{0,0,0,0},{1,0,1,0} };
	int a, b;
	cin >> a >> b;
	cin >> EY >> EX;
	queue<Node> q;
	q.push({a,b,0});
	used[a][b] = 1;
	Node n;
	int direct[4][2] = {1,0,0,1,-1,0,0,-1};
	int cnt = 0;
	while (!q.empty()) {
		n= q.front();
		q.pop();
		if (n.y == EY && n.x == EX) {
			cnt == n.value;
			break;
		}
		for (int i = 0; i < 4;i++) {
			int dy = n.y + direct[i][0];
			int dx = n.x + direct[i][1];
			if (dy < 0 || dy>=4 || dx < 0 || dx>=4)continue;
			if (arr[dy][dx] == 1) continue;
			if (used[dy][dx] == 1)continue;
			used[dy][dx] = 1;
			q.push({dy,dx,n.value+1});
		}
	}
	cout << cnt << "ȸ";
	return 0;
}