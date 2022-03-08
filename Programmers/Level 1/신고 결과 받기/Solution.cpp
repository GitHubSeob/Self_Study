#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map <string, int> report_cnt;
    unordered_map <string, int> reporter_cnt;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    int idx(0);
    int blank_idx(0);

    for (idx = 0; idx < report.size(); ++idx) {
        blank_idx = report[idx].find(" ") + 1;
        report_cnt[report[idx].substr(blank_idx)]++;
    }
    for (idx = 0; idx < report.size(); ++idx) {
        blank_idx = report[idx].find(" ") + 1;
        if (report_cnt[report[idx].substr(blank_idx)] >= k) {
            reporter_cnt[report[idx].substr(0, blank_idx - 1)]++;
        }
    }
    for (idx = 0; idx < id_list.size(); ++idx) {
        answer.push_back(reporter_cnt[id_list[idx]]);
    }

    return answer;
}