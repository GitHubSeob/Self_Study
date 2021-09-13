#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int idx = 0;
    int answer = 0;

    for (idx = 1; idx <= n; ++idx)
        if (n % idx == 0) answer += idx;

    return answer;
}