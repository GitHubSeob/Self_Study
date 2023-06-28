#include <string>
#include <vector>
#include <algorithm>
#define MAX 2147483646
using namespace std;

int solution(int n, vector<int> cores) {
    int answer(0), idx(0), left(1), right(MAX), mid(0), cnt(0);
    vector<int>div;
    
    if (n <= cores.size())
        return n;

    while (left <= right) {
        mid = (left + right) / 2;
        cnt = 0;
        div = vector<int>();
        for (idx = 0; idx < cores.size(); ++idx) {
            if (mid % cores[idx] != 0)
                cnt += (mid / cores[idx] + 1);
            else {
                div.push_back(idx);
                cnt += (mid / cores[idx]);
            }
            if (cnt >= n) break;
        }
        
        if (cnt < n && cnt + div.size() >= n) {
            return div[n - cnt - 1] + 1;
        }
        else if (cnt >= n) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
}