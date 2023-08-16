#include <bits/stdc++.h>
using namespace std;

struct Coord {
	int num;
	int x;
	int y;
	int z;
};

struct Link {
	int node1;
	int node2;
	int cost;
};

vector<int>parent;
vector<Link> tunnel;
vector<Coord>planet;

bool cmp(Link& l1, Link&l2) {
	return l1.cost < l2.cost;
}

bool compareX(Coord& c1, Coord& c2) {
	return c1.x < c2.x;
}

bool compareY(Coord& c1, Coord& c2) {
	return c1.y < c2.y;
}

bool compareZ(Coord& c1, Coord& c2) {
	return c1.z < c2.z;
}

int union_find(int node) {
	if (parent[node] == node) return node;
	else return parent[node]= union_find(parent[node]);
}

void merge(int node1, int node2) {
	node1 = parent[node1];
	node2 = parent[node2];

	if (node1 > node2) swap(node1, node2);
	parent[node2] = node1;
}

bool isUnion(int node1, int node2) {
	if (union_find(node1) == union_find(node2)) {		
		return true;
	}
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N(0);
	cin >> N;	

	planet = vector<Coord>(N);
	parent = vector<int>(N, 0);

	for (int idx = 0; idx < N; ++idx) {
		cin >> planet[idx].x >> planet[idx].y >> planet[idx].z;
		planet[idx].num = idx;
		parent[idx] = idx;
	}	

	sort(planet.begin(), planet.end(), compareX);

	for (int idx = 0; idx + 1 < N; ++idx) {		
		Link link;
		link.node1 = planet[idx].num;
		link.node2 = planet[idx + 1].num;
		link.cost = abs(planet[idx].x - planet[idx + 1].x);
		tunnel.push_back(link);
	}

	sort(planet.begin(), planet.end(), compareY);

	for (int idx = 0; idx + 1 < N; ++idx) {
		Link link;
		link.node1 = planet[idx].num;
		link.node2 = planet[idx + 1].num;
		link.cost = abs(planet[idx].y - planet[idx + 1].y);
		tunnel.push_back(link);
	}

	sort(planet.begin(), planet.end(), compareZ);

	for (int idx = 0; idx + 1 < N; ++idx) {
		Link link;
		link.node1 = planet[idx].num;
		link.node2 = planet[idx + 1].num;
		link.cost = abs(planet[idx].z - planet[idx + 1].z);
		tunnel.push_back(link);
	}
	
	sort(tunnel.begin(), tunnel.end(), cmp);

	int cnt(0), answer(0);

	for (int idx = 0; idx < tunnel.size(); ++idx) {
		int node1 = tunnel[idx].node1;
		int node2 = tunnel[idx].node2;		
		if (isUnion(node1, node2) == true) {			
			continue;
		}
		else {			
			merge(node1, node2);
			answer += tunnel[idx].cost;
			++cnt;
			if (cnt == N - 1) break;
		}
	}
	cout << answer;
}

//문제풀이: https://githubseob.tistory.com/312