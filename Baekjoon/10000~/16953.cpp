/*
DFS를 이용하는 문제이다.
ans 값을 여유롭게 100으로 설정한다.
연산의 최솟값+1 값을 출력해야 하므로 cnt=1인 상태로 A부터 DFS 함수를 실행한다.
A=B 이면 ans 값과 cnt 값을 비교해 더 작은 값을 저장한다.
A*2 <= B 이면 DFS에 A*2, cnt+1 값을 넣고 DFS 함수를,
A*10+1 <= B 이면 DFS에 A*10+1, cnt+1 값을 넣고 DFS 함수를 실행한다.
ans 값이 변하지 않았다면 A->B의 변환이 불가능하므로 -1을 출력한다.
그 외에는 ans 값을 출력한다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

long long A, B;
int ans=100;

void DFS(long long A, int cnt) {
	if (A == B) ans=min(ans,cnt);
	if(A*2<=B)
	DFS(A * 2,cnt+1);
	if (A * 10 + 1 <= B)
	DFS(A * 10 + 1,cnt+1);	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A >> B;

	DFS(A,1);
	if (ans==100) cout << "-1";
	else cout << ans;	
}