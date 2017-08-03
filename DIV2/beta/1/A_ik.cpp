//ik_e version
//implementation
#include<bits/stdc++.h>

using namespace std;
int main(){
	long long n, m, a;
	cin >> n >> m >> a;
	n += (a - 1);
	m += (a - 1);
	cout << (n / a)*+(m / a);
	return 0;
}
