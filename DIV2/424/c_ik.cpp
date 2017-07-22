//ik_e version
//sort and order check (only exist)
#include<bits/stdc++.h>
using namespace std;
int A[2001], B[2001];
vector<int> sol;

int main() {
	int k, n, cnt=0;
	cin >> k >> n;
	cin >> A[0];
	for (int i = 1; i < k; i++) {
		cin >> A[i];
		A[i] += A[i - 1];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	sort(A, A + k);
	sort(B, B + n);
	for (int i = 0; i < k; i++) {   //matching i with B[0]
		int x = B[0] - A[i];
		bool chk = 0;
		for (int i = 0; i < sol.size(); i++)  //already check
			if (x == sol[i])	chk = 1;
		if (chk) continue;
		int j = 1, idx=i+1;
		while (j < n && idx < k) {    //all matching
			int temp = B[j] - A[idx];
			if (temp == x) {
				j++;
				idx++;
			}
			else {
				if (temp > x) 	idx++;
				else break;
			}
		}
		if (j == n) { //all exist
			cnt++;
			sol.push_back(x);
		}
	}
	cout << cnt;
	return 0;
}
