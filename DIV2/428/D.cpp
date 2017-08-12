#include<iostream>
#define ll long long
#define MOD 1000000007
using namespace std;

ll myPow(ll base, ll exp) {
	if (exp == 0) return 1;

	ll mid = myPow(base, exp / 2);

	if (exp % 2 == 0) {
		return (mid * mid) % MOD;
	}
	else {
		return (base * mid * mid) % MOD;
	}
}

int n;
int num[1000001];
int divid[1000001];
ll dp[1000001];

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) { //countSort
		int input;
		cin >> input;
		num[input]++;
	}

	for (int i = 2; i <= 1000000; i++) {
		for (int j = i; j <= 1000000; j += i) {
			divid[i] += num[j];
			divid[i] %= MOD;
		}
	}

	for (int i = 1000000; i >= 2; i--) {
		if (!divid[i]) continue;

		dp[i] = (myPow(2, divid[i] - 1) * divid[i]) % MOD; //만족하는 k들의 길이들의 합
		for (int j = 2 * i; j <= 1000000; j += i) {
			dp[i] = (dp[i] + MOD - dp[j]) % MOD; //음수 ㄴㄴ, 배수들은 중복처리되니까 빼줌
		}
	}

	ll result = 0;

	for (int i = 2; i <= 1000000; i++) {
		result += ((i * dp[i]) % MOD);
		result %= MOD;
	}

	cout << result;
}
