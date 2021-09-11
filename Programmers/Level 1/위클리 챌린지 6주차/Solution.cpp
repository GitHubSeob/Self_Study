#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(vector<double>a,vector<double>b){
    if(a[0]==b[0]){
        if(a[1]==b[1]){
            if(a[2]==b[2]){
                return a[3]<b[3];
            }
            else return a[2]>b[2];
        }
        else return a[1]>b[1];
    }
    else return a[0]>b[0];
}


vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<vector<double>>records(weights.size(),vector<double>(0,0));
    int idx=0;
    int idx2=0;
    for(idx=0;idx<head2head.size();++idx){
        int win=0;
        int lose=0;
        int win_heavy=0;
        for(idx2=0;idx2<head2head[idx].size();++idx2){
            if(head2head[idx][idx2]=='W'){
                win++;
                if(weights[idx]<weights[idx2])
                    win_heavy++;
            }
            else if(head2head[idx][idx2]=='L')
                lose++;
        }
        double rate=0;
        if(win==0)rate=0;
        else if(lose==0) rate=100;
        else rate = (double)win / (lose + win);
        records[idx].push_back(rate);
        records[idx].push_back(win_heavy);
        records[idx].push_back(weights[idx]);
        records[idx].push_back(idx+1);
    }
    sort(records.begin(),records.end(),Compare);
    vector<int> answer;
    for(idx=0;idx<weights.size();++idx){
        answer.push_back(records[idx][3]);
    }
    
    return answer;
}