#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long long_num = num;
    while (long_num != 1) {
        if (answer == 500) {
            answer = -1;
            break;
        }
        if (long_num % 2 == 0)long_num /= 2;
        else long_num = long_num * 3 + 1;
        answer++;
    }
    return answer;
}