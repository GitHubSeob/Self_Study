#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>>visit;
vector<vector<int>>map;
int dy[] = { 0,0,1,-1 };
int dx[] = { -1,1,0,0 };

int BFS() {
    queue<vector<int>>q;
    visit[0][0] = true;
    q.push({ 0,0,1 });
    int y(0), x(0), cnt(0);
    int idx(0);
    while (!q.empty()) {
        y = q.front()[0];
        x = q.front()[1];
        cnt = q.front()[2];
        q.pop();        
        
        for (idx = 0; idx < 4; ++idx) {
            int n_y(y + dy[idx]);
            int n_x(x + dx[idx]);
            if (n_y >= 0 && n_y < map.size() && n_x >= 0 && n_x < map[0].size()) {
                if(n_y==map.size()-1&&n_x==map[0].size()-1){
                    return (cnt+1);
                }
                if (!visit[n_y][n_x] && map[n_y][n_x]) {
                    q.push({ n_y,n_x,cnt + 1 });
                    visit[n_y][n_x] = true;
                }
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    map = maps;
    visit = vector<vector<bool>>(maps.size(), vector<bool>(maps[0].size(), false));

    return BFS();
}