#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    int answer(0), idx(0);
    vector<string>num;
    string s("");
    
    for (idx = 0; idx < p.size(); ++idx) {
        s += t[idx];
    }
    num.push_back(s);
    
    for (idx = 1; idx + p.size() - 1 < t.size(); ++idx) {
        s.erase(s.begin());
        s += t[idx + p.size() - 1];
        num.push_back(s);
    }
    
    for (idx = 0; idx < num.size(); ++idx) {
        if (num[idx] <= p)
            answer++;
    }

    return answer;
}