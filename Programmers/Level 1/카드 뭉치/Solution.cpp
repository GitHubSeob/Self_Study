#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx(0), idx1(0), idx2(0);
    for (idx = 0; idx < goal.size(); ++idx) {
        if (cards1[idx1] == goal[idx]) {
            ++idx1;
        }
        else if (cards2[idx2] == goal[idx]) {
            ++idx2;
        }
        else return "No";
    }

    return "Yes";
}