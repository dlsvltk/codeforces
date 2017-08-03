//ik_e version
//excel converion alphabet <-> number
//radix notation
#include<bits/stdc++.h>
using namespace std;
stack<char> s;
int main(){
	int n;
	char q[30];
	cin >> n;
	while (n--){
		cin >> q;
		bool number=0;
		int idxC = 2;
		if ('1' <= q[1] && q[1] <= '9'){
			while (q[idxC] != 0){
				if (q[idxC] == 'C'){
					number = 1;
					break;
				}
				idxC++;
			}
		}

		if (number){ //number
			int l;
			int digit=1,C=0;
			l = idxC + 1;
			while (q[l] != 0) l++;
			for (int i = l - 1; i > idxC; i--){
				C += digit*(q[i] - '0');
				digit *= 10;
			}
			while (C != 0){
				s.push((C%26? 'A'+C%26-1:'Z'));
				if (C % 26 == 0) C--;
				C /= 26;
			}
			while (!s.empty()){
				cout << s.top();
				s.pop();
			}
			for (int i = 1; i < idxC; i++) cout << q[i];
			cout << "\n";
		}
		else{	//alphabet
			int idx = 0;
			int digit=1,C = 0;
			while (!('1' <= q[idx] && q[idx] <= '9')) idx++;
			cout << 'R';
			for (int i = idx; q[i] != 0; i++) cout << q[i];

			cout << 'C';
			for (int i = idx - 1; i> -1; i--){
				C += (q[i]-'A'+1) * digit;
				digit *= 26;
			}
			cout << C;
			cout << "\n";
		}
	}
	return 0;
}
