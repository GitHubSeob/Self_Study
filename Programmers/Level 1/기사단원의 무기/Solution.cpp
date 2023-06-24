#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer(0), idx(0), idx2(0);
    vector<int>divisor(number + 1, 1);
    for (idx = 2; idx <= number; ++idx) {
        for (idx2 = 1; idx * idx2 <= number; ++idx2) {
            divisor[idx * idx2]++;
        }
    }
    
    for (idx = 1; idx <= number; ++idx) {
        if (divisor[idx] > limit)
            divisor[idx] = power;
        answer += divisor[idx];
    }

    return answer;
}