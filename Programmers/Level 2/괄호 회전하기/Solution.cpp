#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {

    int answer(0);
    int idx(0), idx2(0);

    for (idx = 0; idx < s.size(); ++idx) {
        stack<char>st;
        for (idx2 = 0; idx2 < s.size(); ++idx2) {
            if (st.empty()) {
                st.push(s[idx2]);
            }
            else {
                if (st.top() == '(' && s[idx2] == ')') {
                    st.pop();
                }
                else if (st.top() == '[' && s[idx2] == ']') {
                    st.pop();
                }
                else if (st.top() == '{' && s[idx2] == '}') {
                    st.pop();
                }
                else st.push(s[idx2]);
            }
        }
        if (st.empty())
            answer++;

        string first = "";
        first = s[0];
        s.erase(0, 1);
        s += first;
    }

    return answer;
}