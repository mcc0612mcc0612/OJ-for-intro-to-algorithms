/*
Knapsack problem:
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int V[201][10001];
typedef struct itemstruct {
	int weight;
	int value;
	int num;
	itemstruct() {
		weight = 0;
		value = 0;
		num = 0;
	}
} *item;

int max_value(item items, int number_of_items, int W) {
	for (int i = 0; i <= W; i++) {
		V[0][i] = 0;
	}
	for (int i = 0; i <= number_of_items; i++) {
		V[i][0] = 0;
	}
	for (int i = 1; i <= number_of_items; i++) {
		for (int w = 1; w <= W; w++) {
			for (int k = 1; k <= items[i-1].num; k++) {
				int total_weight = k * items[i-1].weight;
				int total_value = k * items[i-1].value;
				if (w < total_weight) {
					if (k == 1) V[i][w] = V[i - 1][w];
					break;
				}
              	if(k == 1)
					V[i][w] = max(V[i - 1][w], V[i - 1][w - total_weight] + total_value);
              	else
                	V[i][w] = max(V[i][w], V[i - 1][w - total_weight] + total_value);//这一步很关键与0-1背包问题不同
			}
		}
	}
	return V[number_of_items][W];
}

int main() {
	int number_of_items, capacity;
	cin >> number_of_items >> capacity;
	item items = new itemstruct[number_of_items];
	for (int i = 0; i < number_of_items; i++) {
		cin >> items[i].weight;
		cin >> items[i].value;
		cin >> items[i].num;
	}
	int result = max_value(items, number_of_items, capacity);
	cout << result;
}
