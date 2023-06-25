#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long solution(vector<int> sequence) {
    long long answer(0), idx(0);
    vector<vector<long long>>DP(sequence.size(), vector<long long>(2, 0));

    DP[0] = { sequence[0], 0 };
    answer = abs(sequence[0]);
    for (idx = 1; idx < sequence.size(); ++idx) {
        if (idx % 2 == 0) {
            DP[idx][0] = sequence[idx] + max(DP[idx - 1][0], max(DP[idx - 1][1], (long long)0));
            DP[idx][1] = sequence[idx] + min(DP[idx - 1][0], min(DP[idx - 1][1], (long long)0));
        }
        else if (idx % 2 == 1) {
            DP[idx][0] = sequence[idx] * -1 + max(DP[idx - 1][0], max(DP[idx - 1][1], (long long)0));
            DP[idx][1] = sequence[idx] * -1 + min(DP[idx - 1][0], min(DP[idx - 1][1], (long long)0));
        }
        answer = max(answer, max(abs(DP[idx][0]), abs(DP[idx][1])));
    }

    return answer;
}