#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    int y(0), x(0), sum(0);
    vector<int> answer;
    vector<int> cnt(26, 101);

    for (y = 0; y < keymap.size(); ++y) {
        for (x = 0; x < keymap[y].size(); ++x) {
            cnt[keymap[y][x] - 'A'] = min(cnt[keymap[y][x] - 'A'], x + 1);
        }
    }
    for (y = 0; y < targets.size(); ++y) {
        sum = 0;
        for (x = 0; x < targets[y].size(); ++x) {
            if (cnt[targets[y][x] - 'A'] == 101) {
                sum = -1;
                break;
            }
            sum += cnt[targets[y][x] - 'A'];
        }
        answer.push_back(sum);
    }
    return answer;
}