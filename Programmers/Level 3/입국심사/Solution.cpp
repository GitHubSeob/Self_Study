#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000000000000000000
using namespace std;

long long solution(int n, vector<int> times) {
    long long left(0), right(MAX), mid(0), idx(0), cnt(0);

    while (left <= right) {
        mid = (left + right) / 2;
        cnt = 0;
        for (idx = 0; idx < times.size(); ++idx) {
            cnt += mid / times[idx];
        }        
        if (cnt < n) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}