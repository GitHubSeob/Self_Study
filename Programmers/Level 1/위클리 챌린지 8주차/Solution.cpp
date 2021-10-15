#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int idx1(0);
    int max_length_w(0);
    int max_length_h(0);
    for (idx1 = 0; idx1 < sizes.size(); ++idx1) {
        if (sizes[idx1][0] < sizes[idx1][1])
            swap(sizes[idx1][0], sizes[idx1][1]);
        max_length_w = max(max_length_w, sizes[idx1][0]);
        max_length_h = max(max_length_h, sizes[idx1][1]);
    }

    return max_length_w * max_length_h;
}