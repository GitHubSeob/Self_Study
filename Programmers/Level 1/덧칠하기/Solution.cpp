#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer(0), idx(0), roller(0);

    for (idx = 0; idx < section.size(); ++idx) {
        if (roller < section[idx]) {
            roller = section[idx] + m - 1;
            answer++;
        }
    }

    return answer;
}