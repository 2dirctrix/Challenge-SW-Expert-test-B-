#include <iostream>
#include <vector>
using namespace std;

int n, m;
int query[100000][3];
vector<int> name;
vector<int> Rank;
int find(int x) {
    if (name[x] != x) {
        name[x] = find(name[x]);
    }
    return name[x];
}

void uni(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        if (Rank[rootA] > Rank[rootB])name[rootB] = name[rootA];
        else if (Rank[rootA] < Rank[rootB])name[rootA] = name[rootB];
        else {
            name[rootB] = name[rootA];
            Rank[rootA]++;
        }
    }
}


int main() {
    cin >> n >> m;
    parent.resize(n + 1); // resize를 써도 되고, parent(n+1)로 해도 됩니다.
    Rank.assign(n + 1, 0); // Rank(n+1, 0) 로 선언해도 됩니다.
    for (int i = 0; i <= n ; i++) {
        name[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> query[i][0] >> query[i][1] >> query[i][2];
        //출력
        if (query[i][0]) {
            int rootA = find(query[i][1]);
            int rootB = find(query[i][2]);
            if (rootA != rootB) {
                cout << '0'<<'\n';
            }
            else {
                cout << '1'<<'\n';
            }
        }
        //유니온
        else {
            uni(query[i][1], query[i][2]);
        }
    }
    
    // Please write your code here.

    return 0;
}
//입력
//7 8
//0 1 3
//1 1 7
//0 7 6
//1 7 1
//0 3 7
//0 4 2
//0 1 1
//1 1 1
//출력
//0
//0
//1