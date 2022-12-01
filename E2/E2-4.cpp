#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef struct mystruct {
	int start;
    int end;
    int danger;
	mystruct* left_child;
	mystruct* right_child;
	mystruct(int _start,int _end,int _danger) {
		start = _start;
        end = _end;
        danger = _danger;
		left_child = NULL;
		right_child = NULL;
	}
}*treenode;
int insert(treenode &iroot, treenode node) {
	treenode root = iroot;
	treenode pointer = root;
	int danger = node->danger;
	if (iroot == NULL) {
		iroot = node;
		return 0;
	}
	while (iroot != NULL) {
		pointer = root;
		if (danger < root->dange) {
			root = root->left_child;
			if (root == NULL) {
				pointer->left_child = node;
				return 0;
			}
		}
		else if (danger > root->danger) {
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
treenode find_extract_max(treenode& iroot){
    treenode pre_root = iroot;
    treenode root = iroot;
    if(root == NULL){
        return -1;
    }
    if(iroot -> right_child){
        while(root->right_child){
            pre_root = root;
            root = root->right_child;
        }
        pre_root->right_child = root->left_child;
        return root; 
    }
    else if(iroot->left_child){
        iroot = iroot-> left_child;
        return root;
    }
}
int main(){
    int n,m;
    cin >> n;//危险品数量
    cin >> m;//危险组合数
    int a[100000];
    treenode root = NULL;
    for (int i = 0; i < n;i++) {
        int a,b,danger;
        cin >> a; 
        cin >> b;
        cin >> danger;
        treenode mynode = new mystruct(a,b,danger);
        insert(root,mynode);
    }
    while(1){
        treenode del_root = find_extract_max(root);
        a1 = del_root.start;
        a2 = del_root.end;
        A[a1]++;
        A[a2]++;
        if(A[a1] > 2 | A[a2] > 2){
            return del_root.danger;
        }
    }
}