#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n;
	cin >> n;
    int c = 0;
	char a = 0;
    vector<int> citation;
	for (int i = 0; i<n; i++)
	{
		cin >> c;
		citation.push_back(c);
		a = getchar();
	}
    sort(citation.begin(),citation.end());
    int h = 0;
    vector<int>::iterator it = citation.end()-1;
    for(;it>=citation.begin();it--){
        h++;
        if(*it<h) break;
    }
    cout << h-1;
}