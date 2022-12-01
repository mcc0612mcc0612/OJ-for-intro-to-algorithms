/*------------description---------------------
勤奋的小明为了预习下学期的数据库课程，决定亲自实现一个简单的数据库系统。
该数据库系统需要处理用户的数据库插入和查询语句，并输出相应的输出。
具体来说，用户的输入共包含若干条插入语句和查询语句。其中每条插入语句包含一个主键（唯一标识）id和一个字符串s_{id},表示在数据库中插入一个主键为id，属性值为s_{id}的条目。
每条查询语句包含一个字符串k，表示在数据库总查询是否有条目属性值为k，若存在属性值为k的条目，则输出该条目对应的主键（输入保证至多有一个条目满足要求），否则输出一个-1表示不存在这样的条目。
*/
/*--------------------input---------------------
首先是若干行插入语句，每行的格式为：
INSERT id s_{id} 
​紧接着若干行查询语句，每行的格式为：
FIND k
最后单独的一行EXIT表示输入结束。
*/
/*------------output-------------------------
对每条查询语句输出一行，每行输出一个数字，表示查询的结果。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef struct mystruct {
	string name;
	int id;
	mystruct* left_child;
	mystruct* right_child;
	mystruct(string _name, int _id) {
		name = _name;
		id = _id;
		left_child = NULL;
		right_child = NULL;
	}
}*treenode;
int insert(treenode &iroot, treenode node) {
	treenode root = iroot;
	treenode pointer = root;
	string name = node->name;
	if (iroot == NULL) {
		iroot = node;
		return 1;
	}
	while (iroot != NULL) {
		pointer = root;
		if (name < root->name) {
			root = root->left_child;
			if (root == NULL) {
				pointer->left_child = node;
				return 0;
			}
		}
		else if (name > root->name) {
			root = root->right_child;
			if (root == NULL) {
				pointer->right_child = node;
				return 0;
			}
		}
		else {
			return 0;
		}
	}
}
int search(treenode root, string key) {
	while (root != NULL) {
		if (key > root->name) {
			root = root->right_child;
		}
		else if (key < root->name) {
			root = root->left_child;
		}
		else {
			return root->id;
		}
	}
	return -1;
}
int main() {
	treenode root = NULL;
	while (1) {
		string c;
		cin >> c;
		if (c == "INSERT") {
			int id;
			string name;
			cin >> id;
			cin >> name;
			treenode node = new mystruct(name, id);
			insert(root, node);
		}
		else if (c == "FIND") {
			string key;
			cin >> key;
			int result = search(root, key);
			cout << result << endl;
		}
		else{
			return 0;
		}
		getchar();

	}
}