#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
	int num[4][4];
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> num[i][j];
		}
	}
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (num[i][j]==1) {
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4) {
						if (num[ny][nx] == 1) {
							flag = true;
							break;
						}
					}
				}
			if (flag)break;
			}
		if (flag)break;
		}
	}
	if (flag) {
		cout << "위험한 상태";
	}
	else {
		cout << "안전한 상태";
	}


	return 0;
}
