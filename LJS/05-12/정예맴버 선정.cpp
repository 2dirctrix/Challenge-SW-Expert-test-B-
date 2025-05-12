#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int A[3][3] = { {2,6,3},{7,1,1},{3,4,2} };
	int B[2][4] = { {6,4,2,4},{1,1,5,8} };
	int C[2][3] = { {9,2,3},{4,2,1} };
	int ans[3][3] = { 0 };

	// A 배열에서 가장 큰 값 3개 추출
	vector<int> aVals;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			aVals.push_back(A[i][j]);

	sort(aVals.begin(), aVals.end(), greater<>()); // 내림차순 정렬
	for (int i = 0; i < 3; ++i)
		ans[0][i] = aVals[i];

	// B 배열에서 가장 작은 값 3개 추출
	vector<int> bVals;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 4; ++j)
			bVals.push_back(B[i][j]);

	sort(bVals.begin(), bVals.end()); // 오름차순 정렬
	for (int i = 0; i < 3; ++i)
		ans[1][i] = bVals[i];

	// C 배열에서 가장 작은 값 2개 + 가장 큰 값 1개
	vector<int> cVals;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 3; ++j)
			cVals.push_back(C[i][j]);

	sort(cVals.begin(), cVals.end()); // 오름차순 정렬
	ans[2][0] = cVals[0];
	ans[2][1] = cVals[1];
	ans[2][2] = cVals.back(); // 가장 큰 값

	// 출력
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			cout << ans[i][j] << ' ';
		cout << endl;
	}

	return 0;
}