#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer(0), idx(0), idx2(0);

    for (idx = 1; idx <= n; ++idx) {
        if (idx2 < stations.size() && stations[idx2] - w <= idx && idx <= stations[idx2] + w) {
            idx = stations[idx2] + w;
            ++idx2;
        }
        else {
            idx += (w * 2);
            answer++;
        }
    }


    return answer;
}