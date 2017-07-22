//ik_e version
//tree consturt balanced depth -> firstly depth compute -> expand until depth
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k, dis, depth, re;
	cin >> n >> k;
	depth = (n - 1) / k;
	re = (n - 1) % k;
	if (re <= 2) dis = 2 * depth + re;
	else dis = 2 * depth + 2;
	
	cout << dis << "\n";
	int pre = 1,d=0;
	for (int nxt = 2; nxt<= n; nxt++) {
		cout << pre << " " << nxt << "\n";
		d++;
		if(re!=0){
			if (d == depth + 1) pre = 1, re--,d=0;
			else pre = nxt;
		}
		else{
			if (d == depth) pre = 1,d=0;
			else pre = nxt;
		}
	}

	return 0;
}
