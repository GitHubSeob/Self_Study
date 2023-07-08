#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer(0), idx(0), left(0), right(0);
    multiset<int, greater<int>>ms;
    for (right = 0; right < k; ++right) {
        ms.insert(stones[right]);
    }

    auto iter = ms.begin();
    answer = *iter;

    for (right; right < stones.size(); ++right, ++left) {
        ms.erase(ms.find(stones[left]));
        ms.insert(stones[right]);
        iter = ms.begin();
        answer = min(answer, *iter);
    }

    return answer;
}