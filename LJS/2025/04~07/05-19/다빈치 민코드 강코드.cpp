#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<int> deck;
int n, m;
int minGop = 21e8;

int path[100];
int minPath[100];

void back(int level, int start, int gop) {
	if (level == m) {
		if (minGop > gop) {
			minGop = gop;
			memcpy(minPath, path, 100 * 4); //int : 4 Byte x 100ĭ
		}
		return;
	}

	for (int i = start; i < n; i++) {
		path[level] = deck[i];
		back(level + 1, i + 1, gop * deck[i]);
		path[level] = 0;
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		deck.push_back(a);
	}

	sort(deck.begin(), deck.end());

	back(0, 0, 1);

	for (int i = 0; i < m; i++) {
		cout << minPath[i] << " ";
	}

	return 0;
}