#include<iostream>
#include<queue>
#include<string>
using namespace std;

char MAP[10][10];
struct Node {
	int y, x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main()
{
	string str;
	int n, m;
	cin >> n >> m;
	int sy, sx;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			MAP[i][j] = str[j];
			if(MAP[i][j] == '1') {
				sy = i;
				sx = j;
			}
		}
	}

	return 0;
}