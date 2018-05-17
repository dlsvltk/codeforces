#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<functional>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
stack<int> stk;
int main() {
	int n, top = -1;
	int cnt = 1;
	int result = 0;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		string query;
		cin >> query;
		if (query == "add") {
			int input;
			cin >> input;
			stk.push(input);
			top = input;
		}//맞음
		else {
			if (top == cnt) {
				cnt++;
				if (stk.empty()) {//맞았는데 pq값이었음
					pq.pop();
					if (pq.empty()) {
						top = -1;
					}
					else {
						top = pq.top();
					}
				}
				else {//맞았는데 스택값이었음
					stk.pop();
					if (stk.empty()) {//스택값이 없어
						if (pq.empty()) {
							top = -1;
						}
						else {
							top = pq.top();
						}
					}
					else {//스택값이 있어
						top = stk.top();
					}
				}
			}
			else {//응 틀렸어
				result++;
				cnt++;
				while (!stk.empty()) {
					int tmp = stk.top();
					stk.pop();
					pq.push(tmp);
				}
				pq.pop();
				top = pq.top();
			}
		}
	}
	cout << result;
}
