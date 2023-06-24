#include <string>
#include <vector>

using namespace std;

vector<string>can{ "ma","ye","aya","woo" };

bool Func(string babble) {
    int idx(1), idx2(0), cnt(-1), prev(-1);
    string s("");
    while (1) {
        s = babble.substr(idx - 1, 2);
        for (cnt = 0; cnt < 4; ++cnt) {
            if (s.size() < can[cnt].size()) {
                if (idx + 1 < babble.size()) {
                    s += babble[++idx];
                }
                else return false;
            }
            if (s == can[cnt]) {
                if (prev == cnt) return false;
                else if (idx + 1 == babble.size()) return true;
                else {
                    prev = cnt;
                    idx += 2;
                    break;
                }
            }
            if (cnt == 3) return false;
        }
        if (idx >= babble.size()) {
            return false;
        }
    }
}

int solution(vector<string> babbling) {
    int answer(0), idx(0);
    for (idx = 0; idx < babbling.size(); ++idx) {
        if (Func(babbling[idx]))
            answer++;
    }

    return answer;
}