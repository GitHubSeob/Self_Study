#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer(queries.size(), 10000);

    int y = 0, x = 0;
    int idx(0);
    int s_x(0), e_x(0), s_y(0), e_y(0);

    vector<vector<int>>matrix(rows, vector<int>(columns, 0));

    idx = 0;
    for (y = 0; y < rows; ++y) {
        for (x = 0; x < columns; ++x) {
            matrix[y][x] = ++idx;
        }
    }

    vector<vector<int>>copy_matrix = matrix;

    for (idx = 0; idx < queries.size(); ++idx) {
        s_x = queries[idx][1] - 1;
        e_x = queries[idx][3] - 1;
        s_y = queries[idx][0] - 1;
        e_y = queries[idx][2] - 1;
        y = s_y;

        for (x = s_x + 1; x <= e_x; ++x) {
            matrix[y][x] = copy_matrix[y][x - 1];
            answer[idx] = min(answer[idx], matrix[y][x]);
        }
        --x;
        ++y;
        
        for (y; y <= e_y; ++y) {
            matrix[y][x] = copy_matrix[y - 1][x];
            answer[idx] = min(answer[idx], matrix[y][x]);
        }
        --y;
        --x;
        
        for (x; x >= s_x; --x) {
            matrix[y][x] = copy_matrix[y][x + 1];
            answer[idx] = min(answer[idx], matrix[y][x]);
        }
        ++x;
        --y;
        
        for (y; y >= s_y; --y) {
            matrix[y][x] = copy_matrix[y + 1][x];
            answer[idx] = min(answer[idx], matrix[y][x]);
        }
        copy_matrix = matrix;
    }

    return answer;
}