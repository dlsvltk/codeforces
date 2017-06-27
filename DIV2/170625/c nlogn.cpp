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
		}//����
		else {
			if (top == cnt) {
				cnt++;
				if (stk.empty()) {//�¾Ҵµ� pq���̾���
					pq.pop();
					if (pq.empty()) {
						top = -1;
					}
					else {
						top = pq.top();
					}
				}
				else {//�¾Ҵµ� ���ð��̾���
					stk.pop();
					if (stk.empty()) {//���ð��� ����
						if (pq.empty()) {
							top = -1;
						}
						else {
							top = pq.top();
						}
					}
					else {//���ð��� �־�
						top = stk.top();
					}
				}
			}
			else {//�� Ʋ�Ⱦ�
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