#include <iostream>
#include <vector>
using namespace std;
int vect[200];
int name[27];
int find(int x) {
    if (name[x] != x) {
		name[x] = find(name[x]);
    }
	return name[x];
}
bool union_set(int x, int y) {
	int rootA = find(x);
	int rootB = find(y);
	if(rootA == rootB) {
		return true;
	}
	name[rootA] = rootB;
	return false;
}
int main() {
	int N;
	cin >> N;
	char a, b;
	int x, y;
	bool flag = false;
	for(int i=0;i<26;i++)
	{
		name[i] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		x = a - 'A';
		y = b - 'A';
		if(union_set(x, y)) {
			flag = true;
		}
	}
	cout << (flag ? "발견" : "미발견") << endl;
    return 0;
}
