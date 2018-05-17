#include<bits/stdc++.h>
using namespace std;
int a[100001];
int re[100001];
int p[256];
int sz[256];
int find(int v) {
	if (p[v] == v) return v;
	return p[v] = find(p[v]);
}
void merge(int v, int u) {
	int p1 = find(v);
	int p2 = find(u);
	p[p2] = p1;
	sz[p1] += sz[p2];
}

int main() {
	int n, k, s;
	cin >> n >> k;
	for (int i = 0; i < 256; ++i) {
		p[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s = find(a[i]);
		if (s == a[i]) {
			while (s!=0 && sz[s] + sz[find(s-1)] <= k) {
				merge(s-1, s);
				s = find(s - 1);
			}
		}
		re[i] = s;
	}
	for (int i = 0; i < n; ++i) cout << re[i] << " ";
	return 0;
}
