#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PAIR;
bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {  
  if(lhs.second < rhs.second) 
    return  1;
  else if(lhs.second > rhs.second)
    return 0;
  else
    return lhs.first < rhs.first;
}  
int main(){
  int n;
	cin >> n;
    int c = 0;
	char a = 0;
  map<int, int> occurence;
	for (int i = 0; i<n; i++)
	{
		cin >> c;
		occurence[c]++; 
		a = getchar();
	}
  vector<PAIR> name_score_vec(occurence.begin(), occurence.end());  
  sort(name_score_vec.begin(),name_score_vec.end(),cmp_by_value);
  for (int i = 0; i < name_score_vec.size(); ++i) {  
    for (int k = 0;k<name_score_vec[i].second;++k)
      cout<<name_score_vec[i].first<<" ";  
  }  
  return 0; 
}

   


