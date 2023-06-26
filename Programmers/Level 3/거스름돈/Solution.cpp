#include <string>
#include <vector>
#define DIV 1000000007
using namespace std;

int solution(int n, vector<int> money) {
    int idx(0), won(0);
    vector<int>cnt(n + 1, 0);

    cnt[0] = 1;

    for (won = 0; won < money.size(); ++won) {
        for (idx = money[won]; idx <= n; ++idx) {
            cnt[idx] += (cnt[idx - money[won]] % DIV);
        }
    }

    return cnt[n];
}