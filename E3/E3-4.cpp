/*Squares counting*/
/*--------------------------------------------------------------------------------------------------------------------------------
reference:https://blog.csdn.net/unclerunning/article/details/51173821
-----------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int min(int a, int b, int c){
    int min;
    min = a < b?a:b;
    min = min < c?min:c;
    return min;
}
int main() {
	int n, m;
	cin >> n >> m;
  	int** _floor = new int*[n];
  	int **square_count = new int*[n];
  	for (int i = 0;i < n; ++i)
	{
		_floor[i] = new int[m];
        square_count[i] = new int[m];
    }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _floor[i][j];
		}
	}
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (_floor[i][j] == 0) {
				if (i == 0) {
					if (j == 0) square_count[i][j] = 1;
					else square_count[i][j] =  1;
				}
				else if (j == 0) {
					square_count[i][j] =  1;
				}
                else
				    square_count[i][j] = min(square_count[i - 1][j], square_count[i - 1][j - 1], square_count[i][j - 1]) + 1;
			}
			else {
				square_count[i][j] = 0;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += square_count[i][j];
		}
	}
	cout << sum;
	return 0;
}