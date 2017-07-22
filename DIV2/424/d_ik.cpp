//ik_e version
//greedy sol -> order matching
#include<bits/stdc++.h>
using namespace std;
int A[1001], B[2001];
int main() {
	int n, k, p;
	int sol = (1 << 31) - 1;
	cin >> n >> k >> p;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> B[i];
	}
	sort(A, A + n);
	sort(B, B + k);

	for (int i = 0; i + n <= k ; i++) { //start point
		int temp=0;
		for (int j = 0; j < n; j++) { //order matching
			int cur, d1, d2, d3;
			d1 = abs(A[j] - p);
			d2 = abs(A[j] - B[i + j]);
			d3 = abs(p - B[i + j]);
			cur = d1;
			if (d2 + d3 != d1) 	cur += min(2*d3, 2*d2);   //not person -- k -- p or p -- k -- person 
			temp = max(temp, cur);
		}
		sol = min(sol, temp);
	}
	cout << sol;
	return 0;
}
