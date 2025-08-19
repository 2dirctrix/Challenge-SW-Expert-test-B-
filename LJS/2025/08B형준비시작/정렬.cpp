#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> m;
    map<string, int> total;
    int indx = 0;
    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]].push_back({ plays[i], i });
        total[genres[i]] += plays[i];
    }
    for (auto &i : m) {
        sort(i.second.begin(), i.second.end(),
            [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.first != b.first)return a.first > b.first;
                return a.second < b.second;
            });
    }

    sort(total.begin(), total.end(), [](const pair<string, int> &a, pair<string, int> &b) {
        return a.second > b.second;
        });

    for (auto& t : total) {
        string genre = t.first;
        int count = 0;
        for (auto& song : m[genre]) {
            answer.push_back(song.second); // ¿Œµ¶Ω∫ √ﬂ∞°
            if (++count == 2) break;       // √÷¥Î 2∞Ó∏∏
        }
    }

    return answer;
}