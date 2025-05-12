#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int arr[8] = { 2,3,4,1,5,3,5,6 };
	vector<int> vect = { 2,3,4,1,5,3,5,6 };

	int n = vect.size();

	for (int x = 0; x < n; x++) {
		cout << vect[x] << " ";
	}
	cout << endl;

	cout << vect[2];

	vector<int> vect2;
	for (int x = 0; x < 3; x++) {
		cin >> vect[x];
	}
	cout << vect[2];
	for (int x = 0; x < 3; x++) {
		int a;
		cin >> a;
		vect2.push_back(a);
	}
	cout << vect[2];
	return 0;
}