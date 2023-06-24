#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer(0), idx(0);
    sort(score.begin(), score.end(), greater<>());
    for (idx = m - 1; idx < score.size(); idx += m) {
        answer += (score[idx] * m);
    }
    return answer;
}