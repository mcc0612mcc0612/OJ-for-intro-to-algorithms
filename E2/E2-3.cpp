/*-----------------------Description--------------------------------
C语言中需要申请一块连续的内存时需要使用malloc等函数。如果分配成功则返回指向被分配内存的指针(此存储区中的初始值不确定)，否则返回空指针NULL。
现在小明决定实现一个类似malloc的内存分配系统，具体来说，他需要连续处理若干申请内存的请求，这个请求用一个闭区间[a_i..b_i]
来表示。当这个区间和当前已被申请的内存产生重叠时，则返回内存分配失败的信息。否则返回内存分配成功，并将该区间标记为已被占用。
假设初始状态下内存均未被占用，管理的内存地址范围为0~1GB*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef struct mystruct {
	int start;
    int end;
	mystruct* left_child;
	mystruct* right_child;
	mystruct(int _start,int _end) {
		start = _start;
        end = _end;
		left_child = NULL;
		right_child = NULL;
	}
}*treenode;
int insert(treenode &iroot, treenode node) {
	treenode root = iroot;
	treenode pointer = root;
	int start = node->start;
    int end = node->end;
	if (iroot == NULL) {
		iroot = node;
		return 0;
	}
	while (iroot != NULL) {
		pointer = root;
		if (end < root->start) {
			root = root->left_child;
			if (root == NULL) {
				pointer->left_child = node;
				return 0;
			}
		}
		else if (start > root->end) {
			root = root->right_child;
			if (root == NULL) {
				pointer->right_child = node;
				return 0;
			}
		}
		else {
			return -1;
		}
	}
}
int main(){
    int n;
    cin >> n;
    treenode root = NULL;
    for (int i = 0; i < n;i++) {
        int a,b;
        cin >> a; 
        cin >> b;
        treenode mynode = new mystruct(a,b);
        int if_new=insert(root,mynode);
        cout << if_new<<endl;
    }
}