#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
map<int, pii> s;
map<int, pii>::iterator it;
stack<int> st;
int p[200001];
int main(){
	int n, a, l = 1, idx = 0;
	memset(p, -1, sizeof(p));
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a;
		it = s.find(a - 1);
		if (it != s.end()){
			s[a] = (s[a].first > it->second.first ? s[a] : pii(it->second.first + 1, i));
			p[i] = it->second.second;
			if (l < it->second.first + 1){
				l = it->second.first + 1;
				idx = i;
			}
			s.erase(it);
		}
		else{
			s[a] = (s[a].first > 0 ? s[a] : pii(1,i));
		}
	}
	cout << l << endl;
	while (idx != -1){
		st.push(idx + 1);
		idx = p[idx];
	}
	while (!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}
