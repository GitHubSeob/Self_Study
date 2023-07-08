#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    int idx(0), start(0);
    vector<int> answer(2, 0);
    map<string, int>gem_cnt;

    for (idx = 0; idx < gems.size(); ++idx) {
        if (gem_cnt[gems[idx]] == 0) {
            ++gem_cnt[gems[idx]];
            answer[0] = start;
            answer[1] = idx;
        }
        else {
            ++gem_cnt[gems[idx]];
            while (gem_cnt[gems[start]] > 1) {
                --gem_cnt[gems[start]];
                ++start;
            }
            if (answer[1] - answer[0] > idx - start) {
                answer[0] = start;
                answer[1] = idx;
            }
        }

    }

    ++answer[0];
    ++answer[1];
    return answer;
}