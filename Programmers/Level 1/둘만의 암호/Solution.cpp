#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    int idx(0), idx2(0);
    string answer("");
    string alp = "abcdefghijklmnopqrstuvwxyz";
    map<char, char>code;

    sort(skip.begin(), skip.end());

    while (!skip.empty()) {
        if (alp[idx] == skip[0]) {
            alp.erase(idx, 1);
            skip.erase(0, 1);
        }
        else {
            ++idx;
        }
    }
    for (idx = 0; idx < alp.size(); ++idx) {
        code[alp[idx]] = alp[(idx + index) % alp.size()];
    }

    for (idx = 0; idx < s.size(); ++idx) {
        answer += code[s[idx]];
    }

    return answer;
}