#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0), L(0);
	cin >> N >> L;
	vector<int>nums(N, 0);
	
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	for (int idx = 0; idx < N; ++idx) {
		cin >> nums[idx];
		pq.push({ nums[idx],idx });
		if (idx == 0) {			
			cout << nums[idx] << " ";
		}
		else {			
			while (1) {
				if (pq.top().second < idx - L + 1) pq.pop();
				else break;
			}
			cout << pq.top().first <<' ';
		}		
	}	
}

//문제풀이: https://githubseob.tistory.com/311