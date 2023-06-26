#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer(0), cnt(0), idx(0), idx2(0), sub(0);
    string str("");
    queue<pair<string, int>>q;
    vector<bool>visit(words.size(), false);

    q.push({ begin,0 });

    while (!q.empty()) {
        str = q.front().first;
        cnt = q.front().second;
        q.pop();
        for (idx = 0; idx < words.size(); ++idx) {
            if (visit[idx] == false) {
                sub = 0;
                for (idx2 = 0; idx2 < words[idx].size(); ++idx2) {
                    if (words[idx][idx2] != str[idx2]) {
                        sub++;
                    }
                }
                if (sub == 1) {
                    if (words[idx] == target) {
                        return cnt + 1;
                    }
                    else {
                        visit[idx] = true;
                        q.push({ words[idx], cnt + 1 });
                    }
                }
            }
        }
    }
    return 0;
}