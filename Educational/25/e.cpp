#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

vector<int> rev[100001];
int order[100001];
int cnt[100001];
bool visited[100001];
int _rank;

int n, m;

int main() {
	cin >> n >> m;

	_rank = n;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		rev[v].push_back(u);
		cnt[u]++;
	}

	priority_queue<int, vector<int> > pq;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int from = pq.top();
		pq.pop();

		visited[from] = true;
		order[from] = _rank--;

		for (int i = 0; i < rev[from].size(); i++) {
			int next = rev[from][i];
			if (visited[next]) continue;
			cnt[next]--;
			if (cnt[next] == 0) {
				pq.push(next);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << order[i] << ' ';
	}
}