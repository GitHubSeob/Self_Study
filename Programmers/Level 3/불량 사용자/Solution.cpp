#include <string>
#include <vector>
#include <set>
using namespace std;

set<string>answer;
vector<vector<string>>banned_ids;

void DFS(int idx, set<string>ids) {
    int idx2(0), idx3(0);
    for (idx2 = 0; idx2 < banned_ids[idx].size(); ++idx2) {
        set<string>nids = ids;
        nids.insert(banned_ids[idx][idx2]);
        if (idx + 1 < banned_ids.size()) {
            DFS(idx + 1, nids);
        }
        else {
            string set_id("");
            if (nids.size() == banned_ids.size()) {
                for (auto iter = nids.begin(); iter != nids.end(); ++iter) {
                    set_id += *iter;
                }
                answer.insert(set_id);
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int idx(0), idx2(0), idx3(0);

    banned_ids = vector<vector<string>>(banned_id.size());

    for (idx = 0; idx < banned_id.size(); ++idx) {
        for (idx2 = 0; idx2 < user_id.size(); ++idx2) {
            if (banned_id[idx].size() != user_id[idx2].size()) continue;
            for (idx3 = 0; idx3 < user_id[idx2].size(); ++idx3) {
                if (banned_id[idx][idx3] == '*') continue;
                else if (banned_id[idx][idx3] != user_id[idx2][idx3]) break;
            }
            if (idx3 == user_id[idx2].size()) {
                banned_ids[idx].push_back(user_id[idx2]);
            }
        }
    }

    DFS(0, {});

    return answer.size();
}