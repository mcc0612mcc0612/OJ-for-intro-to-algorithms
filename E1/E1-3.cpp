#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int cnt = 0;
    void merge(int left, int mid, int right, vector<int> &nums){
        vector<int> backup(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                backup[k++] = nums[i++];
            }else{
                backup[k++] = nums[j++];
                cnt += mid - i + 1;
                if(cnt>=10000007)
                    cnt -= 10000007;
            }
        }
        while(i <= mid) backup[k++] = nums[i++];
        while(j <= right) backup[k++] = nums[j++];
        for(int i = left, k = 0; i <= right; i++, k++)
            nums[i] = backup[k];
    }
 
    void merge_sort(int left, int right, vector<int> &nums){
        if(left < right){
            int mid = (left + right) / 2;
            merge_sort(left, mid, nums);
            merge_sort(mid + 1, right, nums);
            merge(left, mid, right, nums);
        }
    }
 
    int reversePairs(vector<int>& nums) {
        merge_sort(0, nums.size() - 1, nums);
        return cnt;
    }
};

int main(){
    int n;
	cin >> n ;
    int c = 0;
	char a = 0;
    vector<int> A;
    Solution solution;
	for (int i = 0; i<n; i++)
	{
		cin >> c;
		A.push_back(c);
		a = getchar();
	}
    cout << solution.reversePairs(A);
        }