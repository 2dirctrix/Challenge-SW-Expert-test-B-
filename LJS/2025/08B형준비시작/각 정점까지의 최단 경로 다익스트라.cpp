#include <iostream>
#include <queue>
#include <vector>
#include <limits> // INF 값을 위해 사용

using namespace std;

// const int INF = 21e8; // 이 값도 충분히 큽니다.
const int INF = numeric_limits<int>::max(); // 더 안전한 무한대 값 설정

int n, m, k;
vector<vector<pair<int, int>>> edge;
vector<int> dist;

void dijk(int startNode) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[startNode] = 0;
    pq.emplace(0, startNode); // (거리, 노드)

    while (!pq.empty()) {
        int nowDist = pq.top().first;
        int nowNode = pq.top().second;
        pq.pop();

        if (nowDist > dist[nowNode]) {
            continue;
        }

        for (auto& next : edge[nowNode]) {
            int nextNode = next.first;
            int costToNext = next.second;
            int newCost = nowDist + costToNext;

            if (newCost < dist[nextNode]) {
                dist[nextNode] = newCost;
                pq.emplace(newCost, nextNode);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> k;

    // --- 수정된 부분 1: n을 입력받고 크기 동적 할당 ---
    // 1-based 인덱스를 사용하기 위해 n+1 크기로 설정
    edge.resize(n + 1);
    dist.assign(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // --- 수정된 부분 2: 무방향 그래프이므로 양쪽으로 간선 추가 ---
        edge[u].emplace_back(v, w);
        edge[v].emplace_back(u, w);
    }

    dijk(k);

    // --- 수정된 부분 3: 출력 형식 및 범위 수정 ---
    // 1번 노드부터 n번 노드까지 출력
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << -1 << "\n"; // 도달할 수 없으면 -1 출력
        }
        else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}