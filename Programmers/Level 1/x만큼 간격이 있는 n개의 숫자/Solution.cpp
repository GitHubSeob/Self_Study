#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int idx = 0;
    for (idx = 0; idx < n; ++idx)
        answer.push_back(x * (idx + 1));
    return answer;
}