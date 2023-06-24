#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int>numX(10, 0);
    vector<int>numY(10, 0);
    vector<char>partner;
    int idx(0), min_cnt(0);

    for (idx = 0; idx < X.size(); ++idx) {
        numX[X[idx] - '0']++;
    }
    
    for (idx = 0; idx < Y.size(); ++idx) {
        numY[Y[idx] - '0']++;
    }
    
    for (idx = 0; idx <= 9; ++idx) {
        min_cnt = min(numX[idx], numY[idx]);
        while (min_cnt--)
            partner.push_back(idx + '0');
    }

    sort(partner.begin(), partner.end(), greater<>());

    for (idx = 0; idx < partner.size(); ++idx) {
        answer += partner[idx];
    }
    if (answer[0] == '0')
        answer = "0";
    else if (answer.empty())
        answer = "-1";

    return answer;
}