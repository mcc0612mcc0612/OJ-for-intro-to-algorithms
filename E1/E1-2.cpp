#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int c = 0;
	char a = 0;
	vector<int> A;
	vector<int> B;
	for (int i = 0; a != '\n'; i++)
	{
		cin >> c;
		A.push_back(c);
		a = getchar();
	}
	a = 0;
	for (int i = 0; a != '\n'; i++)
	{
		cin >> c;
		B.push_back(c);
		a = getchar();
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<int>::iterator it_A = A.begin();
	vector<int>::iterator it_B = B.begin();
	int ifempty = 1;
	int pre_num = 0;
	for (; it_A != A.end() && it_B != B.end();) {
		if (*it_A > *it_B) {
			it_B++;
		}
		else if (*it_A < *it_B) {
			it_A++;
		}
		else {
			if (pre_num != *it_A) {
				ifempty = 0;
				cout << *it_A << " ";
			}
			pre_num = *it_A;
			it_A++;
			it_B++;
		}
	}
	if (ifempty == 1)
		cout << -1;
}
