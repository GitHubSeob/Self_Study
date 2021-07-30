#include <iostream>
#include <vector>
using namespace std;

long long A, B;
long long ans=100;

void dfs(long long A, long long cnt) {
	if (A == B) ans=min(ans,cnt);
	if(A*2<=B)
	dfs(A * 2,cnt+1);
	if (A * 10 + 1 <= B)
	dfs(A * 10 + 1,cnt+1);	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A >> B;

	dfs(A,1);
	if (ans==1000000) cout << "-1";
	else cout << ans;
	
}