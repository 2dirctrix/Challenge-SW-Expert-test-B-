#include <string>
#include <vector>
#include <queue>

using namespace std;
int visited[51];
queue<pair<string, int>> q;
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    q.push({ begin,0 });
    while (!q.empty()) {
        pair<string, int> p = q.front();
        q.pop();
        if (p.first == target) {
            answer = p.second;
            break;
        }
        for (int i = 0; i < words.size(); i++) {
            if (visited[i] == 1)continue;
            for (int j = 0; j < words[0].length(); j++) {
                string s1 = words[i];
                s1.erase(j, 1);

                string s2 = p.first;
                s2.erase(j, 1);

                if (s1 == s2) {
                    visited[i] = 1;
                    q.push({ words[i],p.second + 1 });
                }
            }
        }
    }



    return answer;
}