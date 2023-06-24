#include <string>
#include <vector>
#define DIV 1000000007
using namespace std;

int solution(int n) {
    long long idx(0), idx2(0);
    vector<long long>DP(n + 1, 0);
    vector<long long>DP2(n + 1, 0);
    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 3;
    for (idx = 3; idx <= n; ++idx) {
        DP[idx] = ((DP[idx - 1] + DP[idx - 2] * 2) % DIV + DP[idx - 3] * 5) % DIV;
        if (idx > 3) {
            DP2[idx] += ((DP2[idx - 1] + DP[idx - 4] * 2) % DIV);
            DP2[idx] %= DIV;
            for (idx2 = 2; idx2 <= (idx / 3); idx2++) {
                DP[idx] += (DP[idx - idx2 * 3] * 2 % DIV);
            }
            DP[idx] += DP2[idx];
            DP[idx] %= DIV;
        }
    }
    return DP[n];
}