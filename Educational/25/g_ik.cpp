//ik_e version
// cin,cout -> TLE
//init, global accessible node -> minimum index
//update -> global (from x to black(ancestor)) 

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1000001];
int p[1000001];
int min_i[1000001];
bool black[1000001];
//making tree by dfs
void make_T(int cur, int mins, int pa) {
	p[cur] = pa;
	min_i[cur] = mins;
	for (int i = 0; i < adj[cur].size(); i++) {
		int nxt = adj[cur][i];
		if(min_i[nxt]==0)	make_T(nxt, min(mins, nxt), cur);
	}
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int type,x, last=0, sol = 10000000;
	q--;
	scanf("%d %d", &type, &x);
	x = (x + last) % n + 1;
	black[x] = 1;
	make_T(x, x, -1);
	while (q--) {
		scanf("%d %d", &type, &x);
		x = (x + last) % n + 1;
		if (type == 1) {
			if (black[x]) continue;
			black[x] = 1;
			sol = min(sol, x);
			int nxt = p[x];
			while (black[nxt] == 0) {
				black[nxt] = 1;
				sol = min(sol, nxt);
				nxt = p[nxt];
			}
		}
		else {
			last = min(sol, min_i[x]);
			printf("%d\n", last);
		}
	}

	return 0;
}
