#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    vector<bool>check(10, false);
    int idx = 0;
    int answer = 0;

    for (idx = 0; idx < numbers.size(); ++idx)
        check[numbers[idx]] = true;

    for (idx = 0; idx < 10; ++idx)
        if (!check[idx]) answer += idx;

    return answer;
}