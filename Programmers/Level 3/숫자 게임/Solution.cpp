#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer(0), idx(0), idx2(0);
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());

    for (idx = 0; idx < A.size(); ++idx) {
        idx2 = lower_bound(B.begin(), B.end(), A[idx] + 1) - B.begin();
        if (idx2 < B.size()) {
            answer++;
        }
        B.erase(B.begin() + idx2 % B.size());
    }
    return answer;
}