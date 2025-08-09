#include <iostream>
using namespace std;

int cnt = 10;
int root[10];

int find(int x) {
    if (root[x] != x) {
        root[x] = find(root[x]);
    }
    return root[x];
}

void union_set(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB) return;
    root[rootA] = rootB;
    cnt--;
}

int main() {
    // 1. 초기화 (각 노드는 자기 자신을 부모로)
    for (int i = 0; i < 10; i++) {
        root[i] = i;
    }

    // 2. 초기 그룹 하드코딩 (A-J → 0~9)
    union_set(0, 1);  // A-B
    union_set(0, 2);  // A-C
    union_set(3, 4);  // D-E
    union_set(3, 5);  // D-F
    union_set(6, 7);  // G-H
    union_set(8, 9);  // I-J

    // 3. 사용자 입력
    int N;
    cin >> N;
    char a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        int x = a - 'A';
        int y = b - 'A';
        if (find(x) != find(y)) {
            union_set(x, y);
        }
    }

    // 4. 결과 출력
    cout << cnt << "개" << endl;
}
