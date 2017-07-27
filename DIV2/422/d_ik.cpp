//ik_e version
//greedy - prime+O(r)
//p: minimum divisor (not 1), a*b%m = ((a%m)*(b%m))%m
#include<bits\stdc++.h>
#define MOD 1000000007
using namespace std;

int p[5000001];
long long f[5000001];

int main(){
	int t, l, r, sol=0,tmp=1;
	cin >> t >> l >> r;

	for (int i = 1; i <= r; i++){
		if (i%2)	p[i] = i;
		else p[i] = 2;
	}
	for (int i = 3; i <= r; i+=2){
		if (p[i] == i){
			long long index = (long long)i*i;
			while (index <= r){
				p[index] = min(i, p[index]);
				index += 2*i;
			}
		}
	}

	for (int i = 1; i <= r; i++){
		if (p[i] == i)	f[i] = ((long long)i*(i - 1)/2) % MOD;
		else f[i] = (f[i / p[i]] + (long long)i*(p[i]-1) / 2) % MOD;
	}
	
	for (int i = l; i <= r; i++){
		sol = (sol + (long long)tmp*f[i]) % MOD;
		tmp = ((long long)tmp*t)%MOD;
	}
	cout << sol;
	return 0;
}
