#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<unordered_map<string, int>>vm;

bool cmp(pair<string, int>num1, pair<string, int>num2) {
    return num1.second > num2.second;
}

void DFS(int idx, int cnt, vector<int>course, string mkset, string menu) {
    if (idx == menu.size() || cnt == course[course.size() - 1]) {
        int idx2(0);
        for (idx2 = 0; idx2 < course.size(); ++idx2) {
            if (cnt == course[idx2]) {
                vm[idx2][mkset]++;
            }
        }
    }
    else if (idx < menu.size() && cnt < course[course.size() - 1]) {
        DFS(idx + 1, cnt, course, mkset, menu);
        mkset += menu[idx];
        DFS(idx + 1, cnt + 1, course, mkset, menu);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vm = vector<unordered_map<string, int>>(course.size());
    int idx(0), idx2(0);
    for (idx = 0; idx < orders.size(); ++idx) {
        sort(orders[idx].begin(), orders[idx].end());
        DFS(0, 0, course, "", orders[idx]);
    }

    for (idx = 0; idx < vm.size(); ++idx) {
        vector<pair<string, int>>v(vm[idx].begin(), vm[idx].end());
        sort(v.begin(), v.end(), cmp);
        for (idx2 = 0; idx2 < v.size(); ++idx2) {
            if (v[idx2].second > 1) {
                answer.push_back(v[idx2].first);
                if (idx2 + 1 == v.size() || v[idx2].second != v[idx2 + 1].second)
                    break;
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}