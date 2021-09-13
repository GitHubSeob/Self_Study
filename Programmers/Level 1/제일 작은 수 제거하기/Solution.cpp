#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min_num = *min_element(arr.begin(), arr.end());
    if (arr.size() == 1) answer.push_back(-1);
    else {
        bool visit = false;
        for (int idx = 0; idx < arr.size(); ++idx)
            if (arr[idx] == min_num && !visit) visit = true;
            else answer.push_back(arr[idx]);
    }
    return answer;
}