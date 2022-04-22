#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int idx(0);
    sort(citations.begin(), citations.end());

    for (idx = 0; idx < (citations.size() + 1) / 2; ++idx) {
        if (citations.size() - idx <= citations[idx]) {
            return (citations.size() - idx);
        }
    }
}