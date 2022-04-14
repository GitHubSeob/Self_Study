#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char>st;
    int answer = -1;
    int idx(0);

    for (idx = 0; idx < s.size(); ++idx) {
        if (!st.empty()) {
            if (st.top() == s[idx])
                st.pop();
            else
                st.push(s[idx]);
        }
        else st.push(s[idx]);
    }
    if (!st.empty())
        answer = 0;
    else
        answer = 1;

    return answer;
}