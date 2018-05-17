#include<bits/stdc++.h>
using namespace std;

vector<int> G[200001];
queue<int> q;
bool visit[200001];

void dfs(int v){
	q.push(v);
	visit[v] = 1;
	for (int i = 0; i < G[v].size(); ++i){
		if (visit[G[v][i]] == 0)
			dfs(G[v][i]);
	}
}

int main(){
	int n, m, u, v, c=0;
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool chk;
	for (int i = 0; i < n; ++i){
		if (visit[i] == 0){
			dfs(i);
			chk = 1;
			while (!q.empty()){
				if (G[q.front()].size() != 2){
					chk = 0;
				}
				q.pop();
				
			}
			if (chk) c++;
		}
	}
	cout << c;
	return 0;
}
