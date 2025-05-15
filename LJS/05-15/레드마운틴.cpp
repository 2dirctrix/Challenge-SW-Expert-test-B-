#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
int arr[16][16];
int n;
void bfs() {
	int visited[16][16];
	for (int i = 0; i < 16; i++) {
		fill(visited[i], visited[i] + 16, 0);
	}
	queue<pair<int,int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;
	while (!q.empty()) {

	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	bfs();
}