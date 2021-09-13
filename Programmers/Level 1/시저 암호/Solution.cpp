#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int idx = 0;
    for (idx = 0; idx < s.size(); ++idx) {
        if (s[idx] >= 65 && s[idx] <= 90)
            answer.push_back((s[idx] + n) % 65 % 26 + 65);
        else if (s[idx] >= 97 && s[idx] <= 122)
            answer.push_back((s[idx] + n) % 97 % 26 + 97);
        else answer.push_back(' ');
    }
    return answer;
}