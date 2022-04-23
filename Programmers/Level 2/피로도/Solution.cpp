#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>dungeon;
int answer;

bool compare(vector<int>d1, vector<int>d2) {
    if (d1[0] == d2[0]) {
        return d1[1] < d2[1];
    }
    return d1[0] > d2[0];
}

void DFS(int num, int idx, int cnt) {
    if (idx == dungeon.size()) {
        answer = max(answer, cnt);
    }
    else {
        DFS(num, idx + 1, cnt);
        if (num >= dungeon[idx][0]) {
            DFS(num - dungeon[idx][1], idx + 1, cnt + 1);
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dungeon = dungeons;
    sort(dungeon.begin(), dungeon.end(), compare);
    do {
        DFS(k, 0, 0);
    } while (prev_permutation(dungeon.begin(), dungeon.end()));

    return answer;
}