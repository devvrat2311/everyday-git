#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<long> productExceptSelf(vector<long>& nums) {
		long int n = nums.size();

		vector<long> left_product(n);
		left_product[0] = 1;
		for(int i = 1; i < n; i++){
			left_product[i] = left_product[i-1] * nums[i-1];
		}

		vector<long> right_product(n);
		right_product[n-1] = 1;
		for(int i = n-2; i >= 0; i--){
			right_product[i] = right_product[i+1] * nums[i+1]; 
		}

		vector<long> answer(n);
		for(int i = 0; i < n; i++){
			answer[i] = left_product[i] * right_product[i];
		}

		return answer;
	}
	
};

int main() {
	vector<long> nums = {1,2,3,4};
	vector<long> ans, ans2;
	Solution s, s2;
	vector<long> nums2 = {10, 11, 13, 17, 23};
	
	ans = s.productExceptSelf(nums);
	ans2 = s2.productExceptSelf(nums2);

	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}
