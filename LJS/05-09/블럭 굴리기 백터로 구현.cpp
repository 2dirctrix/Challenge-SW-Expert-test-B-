#include <iostream>
#include <vector>
using namespace std;

void Roll(vector<vector<char>>& arr) {
	char map[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			map[i][j] = arr[2 - j][i];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[i][j]=map[i][j];
		}
	}
}
int main()
{
	vector<vector<char>> arr = { {'_','5','4'},{'3','_','_'},{'_','_','1'} };
	int n=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Roll(arr);
	}
	for (int i = 0; i < 3; i++) {
		for (int j=0;j<3;j++){
			cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}