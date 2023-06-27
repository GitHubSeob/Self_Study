#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<vector<int>> scores) {
    int idx(0), rank(1), cnt(0);
    int sum(0), work(0), peer(0), prev(0);
    bool pass(false);

    multimap<int, int, greater<int>>m;
    map<int, int, greater<int>>max_num;

    m.insert({ scores[0][0] + scores[0][1], scores[0][1] });

    for (idx = 0; idx < scores.size(); ++idx) {
        if (scores[0][0] + scores[0][1] < scores[idx][0] + scores[idx][1]) {
            m.insert({ scores[idx][0] + scores[idx][1], scores[idx][1] });
        }
        if (scores[0][0] < scores[idx][0] && scores[0][1] < scores[idx][1]) {
            return -1;
        }
    }

    for (auto it = m.begin(); it != m.end(); ++it) {
        sum = it->first;
        work = sum - it->second;
        peer = it->second;
        for (auto iter = max_num.begin(); iter != max_num.end(); ++iter) {
            if (work < iter->first && peer < iter->second) {
                pass = true;
                break;
            }
        }
        if (pass == true) {
            pass = false;
            continue;
        }
        if (max_num[work] == 0) {
            max_num[work] = peer;
        }

        if (prev == sum) {
            cnt++;
        }
        else {
            rank += cnt;
            cnt = 1;
        }

        prev = sum;
    }
    return rank;
}