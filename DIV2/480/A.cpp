#include<bits/stdc++.h>
using namespace std;
char s[101];
int main(){
	int o = 0, l = 0;
	cin >> s;
	for (int i = 0; s[i] != 0; ++i){
		if (s[i] == 'o') o++;
		else l++;
	}
	if (l == 0 || o == 0 || (l>=o && l%o == 0)){
		cout << "YES";
	}
	else{
		cout << "NO";
	}

	return 0;
}
