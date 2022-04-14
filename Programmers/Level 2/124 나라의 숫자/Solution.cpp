#include <string>
#include <stack>

using namespace std;

string solution(int n) {
    string answer = "";
    stack<int>number;
    int remainder(0);

    while (n > 0) {
        n--;
        remainder = n % 3;
        n /= 3;
        if (remainder == 2)
            number.push(4);
        else
            number.push(remainder + 1);
    }

    while (!number.empty()) {
        answer += to_string(number.top());
        number.pop();
    }
    return answer;
}