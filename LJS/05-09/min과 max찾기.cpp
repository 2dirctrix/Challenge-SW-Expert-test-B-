#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int num[6];
	for (int i = 0; i < 6; i++) {
		cin >> num[i];
	}
	char cmd[7];
	cin >> cmd;
	bool used[6] = { false };
	for (int i = 0; i < 6; i++) {
		int max=0;
		int min=21e8;
		int indx;
		if (cmd[i] == 'm') {
			for (int j = 0; j < 6; j++) {
				if (used[j])continue;
				if (num[j] > max) {
					max = num[j];
					indx = j;
				}
			}
			used[indx] = true;
			cout << max;
		}
		else {
			for (int j = 0; j < 6; j++) {
				if (used[j])continue;
				if (num[j] <min) {
					min = num[j];
					indx = j;
				}
			}
			used[indx] = true;
			cout << min;
		}
	}
	return 0;
}