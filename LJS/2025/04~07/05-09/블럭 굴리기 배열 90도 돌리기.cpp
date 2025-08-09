#include <iostream>
using namespace std;
char arr[3][3] = { {'_','5','4'},{'3','_','_'},{'_','_','1'} };
void Roll() {
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
	int n=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Roll();
	}
	for (int i = 0; i < 3; i++) {
		for (int j=0;j<3;j++){
			cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}