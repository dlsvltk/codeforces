//ik_e version
//string idx sort and check previous already
#include<bits/stdc++.h>
using namespace std;
string str[100001];
int l[100001];
int K[100001];
pair<int, int> sol[1000001];
char s[2000001];
int main() {
	int n,k,idx,siz=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i] >> k;
		l[i] = str[i].length();
		for (int j = 0; j < k; j++) {
			cin >> idx;
			sol[siz].first = idx;
			sol[siz].second = i;
			siz++;
		}
	}
	sort(sol, sol + siz);
	int pre=-1, ends=-1;

	for (int i = 0; i < siz; i++) {
		int si = sol[i].first;
		int th = sol[i].second;
		int expand = si + l[th] - 1;
		
		if (pre < expand) {
			int sx,dx;
			if (si > pre) {
				dx = si;
				sx = 0;
			}
			else {
				dx = pre + 1;
				sx = pre - si + 1;
			}
			while (str[th][sx]!=0) {
				s[dx] = str[th][sx];
				sx++;
				dx++;
			}
			pre = expand;
			ends = max(ends,expand);
		}
	}
	for (int i = 1; i <= ends; i++) {
		if (s[i] == 0) cout << 'a';
		else cout << s[i];
	}

	return 0;
}
