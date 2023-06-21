#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> ingredient) {
    int idx(0);
    int answer = 0;

    for (idx; idx + 3 < ingredient.size(); ++idx) {
        if (ingredient[idx] == 1 && ingredient[idx + 1] == 2 && ingredient[idx + 2] == 3 && ingredient[idx + 3] == 1) {
            ingredient.erase(ingredient.begin() + idx, ingredient.begin() + idx + 4);
            answer++;
            idx = max(-1, idx - 4);
        }
    }

    return answer;
}