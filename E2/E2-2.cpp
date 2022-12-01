/*-----------------------Description------------------------------------
给定某二叉树的前序序列和中序序列，输出该二叉树的后序序列。（输入的前序遍历和中序遍历的结果中都不含重复的数字）
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> _LRD;
void LRD(int*start_qian, int*end_qian, int*start_zhong, int*end_zhong) {
	int*interval = start_zhong;
	if (start_qian > end_qian)
		return;//防止前一步interval等于qian_end,这时候没有右子树
	while (*interval != *start_qian) {
		*interval++;
	}
	_LRD.push_back(*start_qian);
	if (start_qian == end_qian ) {
		return;
	}
	int* right_start = start_qian + (interval - start_zhong) + 1;
	LRD(right_start, end_qian, interval + 1, end_zhong);
	LRD(start_qian + 1, right_start - 1, start_zhong, interval - 1);
}
int main() {
	int n;
	int VLR[100000];//前序
	int LDR[100000];//中序
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		cin >> VLR[i];
		getchar();
	}
	for (int i = 0; i < n; i++) {
		cin >> LDR[i];
	}
	LRD(VLR, VLR + n - 1, LDR, LDR + n - 1);
	cout << _LRD.back();
	_LRD.pop_back();
	while(_LRD.begin()!= _LRD.end()) {
		cout << " " << _LRD.back();
		_LRD.pop_back();
	}
}