#include<iostream>
using namespace std;

int main() {
	int arr[5][4] = { 0 };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0,BoomIndex=0;
	for (int i = 0; i < 5; i++) {
		if (arr[i][0] == 1) {
			cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (arr[i][j] == 1) {
					cnt++;
				}
			}
			if (cnt == 4) {
				BoomIndex = i;
				for (int j = 0; j < 4; j++) {
					arr[i][j] = 0;
				}
			}
		}
	}
	int indx=BoomIndex;
	for (int j = 0; j < 4; j++) {
		indx = BoomIndex;
		for (int i = BoomIndex; i >= 0; i--) {
			if (arr[i][j]) {
				arr[indx][j] = arr[i][j];
				arr[i][j] = 0;
				indx = i;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}