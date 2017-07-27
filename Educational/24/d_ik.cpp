//ik_e version
//implemtation O(n)
#include<bits/stdc++.h>
using namespace std;

int cnt[1000005];
int main() {
	int n,A,B,color,cmax=0,idx=-1;
	bool chk = 1;
	cin >> n >> A;
	for (int i = 0; i < n; i++) {
		cin >> color;
		if (color == A) {
			cnt[A]++;
			if (cmax < cnt[A]) {
				chk = 0;
				break;
			}
		}
		else {
			if (cnt[A] > cnt[color]) continue;
			cnt[color]++;
			if (cnt[color] > cmax) {
				cmax++;
				idx = color;
			}
		}
	}

	if (!chk) cout << -1;
	else {
		if (cmax == 0) {
			if (A == 1) cout << 2;
			else cout << 1;
		}
		else {
			cout << idx;
		}
	}
	return 0;
}
