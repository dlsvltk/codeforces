#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5001];
int p[5001];
int re[5001];
int dp[5001];
bool s[5001][5001];
bool chk(int a, int b){
	ll t = ll(a)*b;
	if (t <= 0) return 0;
	ll k = sqrt(t);
	if (k*k == t) return 1;
	return 0;
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		p[i] = i;
		dp[i] = 1;
	}
	for (int i = 0; i < n; ++i){
		if (a[i]!=0 && p[i] == i)
		for (int j = i + 1; j < n; ++j){
			if (a[j] == 0) continue;
			if (chk(a[i], a[j])){
				p[j] = i;
			}
		}
	}
	for (int i = 0; i < n; ++i){
		if (a[i] == 0) s[i][n] = 1;
		s[i][p[i]] = 1;
	}
	re[1] += n;

	for (int i = 1; i < n; ++i){
		for (int j = i; j < n; ++j){
			if (s[j][n] == 1){
				s[j][n] = (a[j - 1] == 0);
				s[j][p[j - i]] = 1;
			}
			else if (a[j-i] != 0 && s[j][p[j-i]] == 0){
				dp[j]++;	
				s[j][p[j - i]] = 1;
			}
			re[dp[j]]++;
		}
	}

	for (int i = 1; i <= n; ++i){
		printf("%d ",re[i]);
	}
	return 0;
}
