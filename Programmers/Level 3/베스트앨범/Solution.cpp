#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

struct compare {
    bool operator()(pair<int, int>& song1, pair<int, int>& song2) {
        if (song1.first == song2.first) {
            return song1.second < song2.second;
        }
        return song1.first > song2.first;
    }
};

bool cmp(pair<string, int>& genre1, pair<string, int>& genre2) {
    return genre1.second > genre2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int idx(0), song1(0), song2(0);
    vector<int> answer;
    map<string, int>genre;
    map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, compare>>songs;

    for (idx = 0; idx < plays.size(); ++idx) {
        genre[genres[idx]] += plays[idx];
        songs[genres[idx]].push({ plays[idx],idx });
        if (songs[genres[idx]].size() > 2) {
            songs[genres[idx]].pop();
        }
    }
    
    vector<pair<string, int>>v(genre.begin(), genre.end());
    sort(v.begin(), v.end(), cmp);
    
    for (idx = 0; idx < genre.size(); ++idx) {
        if (songs[v[idx].first].size() == 1) {
            answer.push_back(songs[v[idx].first].top().second);
            songs[v[idx].first].pop();
        }
        else {
            song2 = songs[v[idx].first].top().second;
            songs[v[idx].first].pop();
            song1 = songs[v[idx].first].top().second;
            songs[v[idx].first].pop();

            answer.push_back(song1);
            answer.push_back(song2);
        }
    }

    return answer;
}