#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    int check = 0;
    for (idx = 0; idx < s.size(); ++idx, ++check) {
        if (s[idx] == ' ') {
            check = -1;
            answer.push_back(' ');
        }
        if (check % 2 == 1)
            answer.push_back(tolower(s[idx]));
        else if (check % 2 == 0)
            answer.push_back(toupper(s[idx]));
    }
    return answer;
}