#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<int> s;

int main() {
	int n, top = 0, cur = 1;
	int lu = 0;
	int reorder = 0;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		string query;
		cin >> query;
		if (query == "add") {
			int input;
			cin >> input;

			s.push(input);
			lu++;
		}
		else {	//remove
			if (lu) {	//unsorted
				if (cur == s.top()) {	
					lu--;
					s.pop();
					cur++;
				}
				else {
					reorder++;
					lu = 0;
					cur++;

					top = cur;	//exist or not
				}
			}
			else {		//sorted
				cur++;
				top = cur;	//exist or not
			}
		}
	}
	cout << reorder;
}