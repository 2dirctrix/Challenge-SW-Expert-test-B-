#include <iostream>
#include <queue>
using namespace std;

int map[1000][1000];
int result[1000][1000];
int y1, x1, N;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

struct Edge {
    int y, x, cost;
};

struct cmp {
    bool operator()(const Edge& a, const Edge& b) const {
        return a.cost > b.cost;  // 최소 힙
    }
};

void dijkstra() {
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push({ y1, x1, map[y1][x1]});
    result[y1][x1] = map[y1][x1];

    while (!pq.empty()) {
        Edge now = pq.top(); pq.pop();
        if (result[now.y][now.x] < now.cost) continue;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (map[ny][nx] == -1) continue;

            int newCost = now.cost + map[ny][nx];
            if (newCost < result[ny][nx]) {
                result[ny][nx] = newCost;
                pq.push({ ny, nx, newCost });
            }
        }
    }
}

int main() {
    cin >> y1 >> x1 >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            result[i][j] = 2e9;  // 충분히 큰 값 (INF)
        }

    dijkstra();

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (result[i][j] != 2e9 && result[i][j] > ans)
                ans = result[i][j];

    cout << ans << '\n';
}
