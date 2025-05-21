#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int y; int x; int lev;
};

int arr[4][5];
int used[4][5];
int cnt;
int main()
{
	queue<Node> q;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				q.push({ i,j,0 });
			}
		}
	}
	
	
	int direct[9][2] = { -1,0,1,0,0,1,0,-1,1,1,-1,1,-1,-1,1,-1,0,0 };
	
	while (!q.empty()) {
		Node d = q.front();
		if (cnt < d.lev) {
			cnt = d.lev;
		}
		q.pop();
		for (int i = 0; i < 9; i++) {
			int ny = d.y + direct[i][0];
			int nx = d.x + direct[i][1];
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 5) continue;
			if (arr[ny][nx] == 1) continue;
			if (used[ny][nx] == 1) continue;
			used[ny][nx] = 1;
			q.push({ ny,nx,d.lev + 1 });
		}
	}
	cout << cnt;
	return 0;
}