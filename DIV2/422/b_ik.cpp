//ik_e version
//brute-force
#include<bits/stdc++.h>
using namespace std;
char s[1001], t[1001];
vector<int> lists;
int main() {
	int n, m, sol=1001;
	cin >> n >> m;
	cin >> s;
	cin >> t;
	for (int i = 0; i+n <= m; i++) {
		int cnt = 0;
		vector<int> tmp;
		for (int j = 0; j < n; j++) {
			if (s[j] != t[i + j]) {
				cnt++;
				tmp.push_back(j + 1);
			}
		}
		if (sol > cnt) {
			sol = cnt;
			lists.swap(tmp);
		}
	}
	cout << sol << endl;
	for (int i = 0; i < sol; i++) {
		cout << lists[i] << " ";
	}
	return 0;
}
