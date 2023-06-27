#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int target) {
    int idx(0), idx2(0), next(0);
    vector<vector<int>>DP(target + 1, vector<int>(2, 0));
    vector<int>scores = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,26,27,28,30,32,33,34,36,38,39,40,42,45,48,50,51,54,57,60 };

    for (idx = 0; idx <= target; ++idx) {
        for (idx2 = 0; idx2 < scores.size(); ++idx2) {
            next = idx + scores[idx2];
            if (next <= target && (DP[next][0] == 0 || DP[idx][0] + 1 < DP[next][0] || (DP[next][0] == DP[idx][0] + 1 && DP[next][1] <= DP[idx][1]))) {
                DP[next][0] = DP[idx][0] + 1;
                DP[next][1] = DP[idx][1];

                if ((1 <= scores[idx2] && scores[idx2] <= 20) || scores[idx2] == 50) {
                    DP[next][1]++;
                }
            }
        }
    }
    return DP[target];
}