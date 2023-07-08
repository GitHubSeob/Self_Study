#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int idx(0), answer(sticker[0]);

    sticker.insert(sticker.begin(), 0);
    sticker.insert(sticker.begin(), 0);
    sticker.insert(sticker.begin(), 0);

    vector<int>DP1(sticker.size(), 0);

    for (idx = 3; idx + 1 < sticker.size(); ++idx) {
        DP1[idx] = sticker[idx] + max(DP1[idx - 2], DP1[idx - 3]);
        answer = max(answer, DP1[idx]);
    }

    sticker.erase(sticker.begin() + 3);

    vector<int>DP2(sticker.size(), 0);

    for (idx = 3; idx < sticker.size(); ++idx) {
        DP2[idx] = sticker[idx] + max(DP2[idx - 2], DP2[idx - 3]);
        answer = max(answer, DP2[idx]);
    }

    return answer;
}